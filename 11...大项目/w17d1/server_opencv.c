/*
 * 服务器（OpenCV 版）
 * -------------------------------------------------
 *  端口 8080 : 等 OpenCV Python 脚本连进来，收一帧帧 JPEG
 *  端口 8081 : 浏览器访问，实时画面 / 录像列表 / 录像回放
 *
 * 网页文件是同目录下的 index.html（独立文件，改页面不用重新编译）
 * 录像存 recordings/ 目录，每 60 秒切一段 .mjpg
 *
 * 新增接口：
 *   GET  /api/history?n=50   查询 sensor_log 最近 n 条，返回 JSON
 *
 * 编译：gcc server_opencv.c cJSON.c -o server_opencv -O2 -Wall -lpthread -lsqlite3
 * 运行：./server_opencv
 */
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <sqlite3.h>
#include "cJSON.h"

/* OpenCV connects here and sends consecutive complete JPEG images. */
#define UPLOAD_PORT 8080

/* Use 8081 so the server does not need root privileges. */
#define HTTP_PORT 8081

#define MAX_JPEG_SIZE 200000
#define SEGMENT_SECONDS 60
#define PLAYBACK_FRAME_DELAY_US 66000
#define REC_DIR "recordings"
#define DB_FILE "gateway.db"

static uint8_t latest_buf[MAX_JPEG_SIZE];
static size_t latest_len = 0;
static unsigned long long latest_sequence = 0;
static pthread_mutex_t latest_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t latest_condition = PTHREAD_COND_INITIALIZER;

static FILE *recording_file = NULL;
static time_t segment_start = 0;
static pthread_mutex_t recording_mutex = PTHREAD_MUTEX_INITIALIZER;

static int send_all(int fd, const void *data, size_t length)
{
    const uint8_t *cursor = data;

    while (length > 0) {
        ssize_t sent = send(fd, cursor, length, 0);
        if (sent < 0 && errno == EINTR)
            continue;
        if (sent <= 0)
            return -1;

        cursor += (size_t)sent;
        length -= (size_t)sent;
    }

    return 0;
}

static void publish_latest(const uint8_t *jpeg, size_t length)
{
    if (length > MAX_JPEG_SIZE)
        return;

    pthread_mutex_lock(&latest_mutex);
    memcpy(latest_buf, jpeg, length);
    latest_len = length;
    latest_sequence++;
    pthread_cond_broadcast(&latest_condition);
    pthread_mutex_unlock(&latest_mutex);
}

/* recording_mutex must already be held. */
static void open_segment_locked(void)
{
    struct tm local_time;
    char path[256];
    time_t now = time(NULL);

    if (recording_file != NULL) {
        fclose(recording_file);
        recording_file = NULL;
    }

    segment_start = now;
    localtime_r(&now, &local_time);
    snprintf(
        path,
        sizeof(path),
        REC_DIR "/rec_%04d%02d%02d_%02d%02d%02d.mjpg",
        local_time.tm_year + 1900,
        local_time.tm_mon + 1,
        local_time.tm_mday,
        local_time.tm_hour,
        local_time.tm_min,
        local_time.tm_sec
    );

    recording_file = fopen(path, "ab");
    if (recording_file != NULL)
        printf("New recording segment: %s\n", path);
    else
        perror("Cannot open recording file");
}

static void record_frame(const uint8_t *jpeg, size_t length)
{
    pthread_mutex_lock(&recording_mutex);

    if (recording_file == NULL ||
        time(NULL) - segment_start >= SEGMENT_SECONDS)
        open_segment_locked();

    if (recording_file != NULL) {
        if (fwrite(jpeg, 1, length, recording_file) != length)
            perror("Cannot write recording frame");
        fflush(recording_file);
    }

    pthread_mutex_unlock(&recording_mutex);
}

static int has_mjpg_suffix(const char *name)
{
    size_t length = strlen(name);
    return length > 5 && strcmp(name + length - 5, ".mjpg") == 0;
}

/* 读 index.html 文件作为网页内容 */
static void serve_index(int fd)
{
    FILE *f = fopen("index.html", "rb");
    if (f == NULL) {
        send_all(fd,
            "HTTP/1.1 500 Internal Error\r\n"
            "Content-Length: 0\r\n"
            "Connection: close\r\n\r\n", 65);
        return;
    }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *body = malloc((size_t)sz);
    if (body == NULL || fread(body, 1, (size_t)sz, f) != (size_t)sz) {
        free(body);
        fclose(f);
        send_all(fd,
            "HTTP/1.1 500 Internal Error\r\n"
            "Content-Length: 0\r\n"
            "Connection: close\r\n\r\n", 65);
        return;
    }
    fclose(f);

    char header[256];
    int header_length = snprintf(
        header, sizeof(header),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=utf-8\r\n"
        "Content-Length: %ld\r\n"
        "Cache-Control: no-store\r\n"
        "Connection: close\r\n\r\n",
        sz);

    send_all(fd, header, (size_t)header_length);
    send_all(fd, body, (size_t)sz);
    free(body);
}

static void send_response(
    int fd,
    const char *status,
    const char *content_type,
    const void *body,
    size_t body_length
)
{
    char header[512];
    int header_length = snprintf(
        header,
        sizeof(header),
        "HTTP/1.1 %s\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %zu\r\n"
        "Cache-Control: no-store\r\n"
        "Connection: close\r\n\r\n",
        status,
        content_type,
        body_length
    );

    send_all(fd, header, (size_t)header_length);
    if (body_length > 0)
        send_all(fd, body, body_length);
}

/* ============================================================
 * 历史数据查询：读 gateway.db 的 sensor_log，返回 JSON 数组
 * ============================================================ */
static char *history_json(int limit)
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[256];
    cJSON *arr = cJSON_CreateArray();

    if (sqlite3_open(DB_FILE, &db) != SQLITE_OK) {
        if (db != NULL) sqlite3_close(db);
        return cJSON_PrintUnformatted(arr);
    }

    sqlite3_busy_timeout(db, 3000);
    sqlite3_exec(db, "PRAGMA journal_mode=WAL;", NULL, NULL, NULL);

    snprintf(sql, sizeof(sql),
        "SELECT id,ts,tem,hum,light,smoke,flame,infrared,"
        "pum,fan,led,curtain,beep FROM sensor_log "
        "ORDER BY id DESC LIMIT %d;",
        limit);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            cJSON *row = cJSON_CreateObject();
            const unsigned char *ts = sqlite3_column_text(stmt, 1);

            cJSON_AddNumberToObject(row, "id", sqlite3_column_int(stmt, 0));
            cJSON_AddStringToObject(row, "ts", ts != NULL ? (const char *)ts : "");
            cJSON_AddNumberToObject(row, "tem", sqlite3_column_double(stmt, 2));
            cJSON_AddNumberToObject(row, "hum", sqlite3_column_double(stmt, 3));
            cJSON_AddNumberToObject(row, "light", sqlite3_column_int(stmt, 4));
            cJSON_AddNumberToObject(row, "smoke", sqlite3_column_int(stmt, 5));
            cJSON_AddNumberToObject(row, "flame", sqlite3_column_int(stmt, 6));
            cJSON_AddNumberToObject(row, "infrared", sqlite3_column_int(stmt, 7));
            cJSON_AddNumberToObject(row, "pum", sqlite3_column_int(stmt, 8));
            cJSON_AddNumberToObject(row, "fan", sqlite3_column_int(stmt, 9));
            cJSON_AddNumberToObject(row, "led", sqlite3_column_int(stmt, 10));
            cJSON_AddNumberToObject(row, "curtain", sqlite3_column_int(stmt, 11));
            cJSON_AddNumberToObject(row, "beep", sqlite3_column_int(stmt, 12));
            cJSON_AddItemToArray(arr, row);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return cJSON_PrintUnformatted(arr);
}

static void stream_live(int fd)
{
    const char *header =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n"
        "Cache-Control: no-store\r\n"
        "Connection: close\r\n\r\n";
    uint8_t *frame = malloc(MAX_JPEG_SIZE);
    unsigned long long sent_sequence = 0;

    if (frame == NULL)
        return;

    if (send_all(fd, header, strlen(header)) != 0) {
        free(frame);
        return;
    }

    while (1) {
        size_t frame_length;
        char part_header[160];
        int part_header_length;

        pthread_mutex_lock(&latest_mutex);
        while (latest_sequence == sent_sequence)
            pthread_cond_wait(&latest_condition, &latest_mutex);

        frame_length = latest_len;
        sent_sequence = latest_sequence;
        memcpy(frame, latest_buf, frame_length);
        pthread_mutex_unlock(&latest_mutex);

        part_header_length = snprintf(
            part_header,
            sizeof(part_header),
            "--frame\r\n"
            "Content-Type: image/jpeg\r\n"
            "Content-Length: %zu\r\n\r\n",
            frame_length
        );

        if (send_all(fd, part_header, (size_t)part_header_length) != 0 ||
            send_all(fd, frame, frame_length) != 0 ||
            send_all(fd, "\r\n", 2) != 0)
            break;
    }

    free(frame);
}

static void stream_recording(int fd, const char *path)
{
    const char *header =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n"
        "Cache-Control: no-store\r\n"
        "Connection: close\r\n\r\n";
    FILE *file = fopen(path, "rb");
    uint8_t *frame;
    size_t frame_length = 0;
    int in_frame = 0;
    int overflow = 0;
    int previous = -1;
    uint8_t chunk[65536];
    size_t count;

    if (file == NULL)
        return;

    frame = malloc(MAX_JPEG_SIZE);
    if (frame == NULL) {
        fclose(file);
        return;
    }

    if (send_all(fd, header, strlen(header)) != 0)
        goto done;

    while ((count = fread(chunk, 1, sizeof(chunk), file)) > 0) {
        size_t index;

        for (index = 0; index < count; index++) {
            int current = chunk[index];

            if (!in_frame) {
                if (previous == 0xff && current == 0xd8) {
                    in_frame = 1;
                    overflow = 0;
                    frame_length = 2;
                    frame[0] = 0xff;
                    frame[1] = 0xd8;
                }
            } else {
                if (frame_length < MAX_JPEG_SIZE)
                    frame[frame_length++] = (uint8_t)current;
                else
                    overflow = 1;

                if (previous == 0xff && current == 0xd9) {
                    if (!overflow) {
                        char part_header[160];
                        int part_header_length = snprintf(
                            part_header,
                            sizeof(part_header),
                            "--frame\r\n"
                            "Content-Type: image/jpeg\r\n"
                            "Content-Length: %zu\r\n\r\n",
                            frame_length
                        );

                        if (send_all(fd, part_header, (size_t)part_header_length) != 0 ||
                            send_all(fd, frame, frame_length) != 0 ||
                            send_all(fd, "\r\n", 2) != 0)
                            goto done;

                        usleep(PLAYBACK_FRAME_DELAY_US);
                    }

                    in_frame = 0;
                    frame_length = 0;
                }
            }

            previous = current;
        }
    }

done:
    free(frame);
    fclose(file);
}

static int get_recording_name(const char *url, char *name, size_t name_size)
{
    const char *query = strchr(url, '?');
    const char *value;
    const char *end;
    size_t length;

    if (query == NULL || (value = strstr(query + 1, "name=")) == NULL)
        return -1;

    value += 5;
    end = strchr(value, '&');
    length = end == NULL ? strlen(value) : (size_t)(end - value);

    if (length == 0 || length >= name_size)
        return -1;

    memcpy(name, value, length);
    name[length] = '\0';

    if (strchr(name, '/') != NULL ||
        strchr(name, '\\') != NULL ||
        strstr(name, "..") != NULL ||
        !has_mjpg_suffix(name))
        return -1;

    return 0;
}

static void *http_client(void *argument)
{
    int fd = *(int *)argument;
    char request[8192];
    char method[16];
    char url[2048];
    char *body_start = NULL;
    size_t total = 0;
    size_t content_length = 0;
    ssize_t received;

    free(argument);

    /* 1) 读完整 HTTP 请求头 */
    while (total < sizeof(request) - 1) {
        received = recv(fd, request + total, sizeof(request) - 1 - total, 0);
        if (received <= 0) goto done;
        total += (size_t)received;
        request[total] = '\0';
        char *header_end = strstr(request, "\r\n\r\n");
        if (header_end != NULL) {
            body_start = header_end + 4;
            char *cl = strcasestr(request, "content-length:");
            if (cl != NULL) content_length = (size_t)atol(cl + 15);
            break;
        }
    }

    /* 2) POST：按 Content-Length 继续读 body */
    if (body_start != NULL && content_length > 0) {
        size_t have = total - (size_t)(body_start - request);
        while (have < content_length && total < sizeof(request) - 1) {
            received = recv(fd, request + total, sizeof(request) - 1 - total, 0);
            if (received <= 0) break;
            total += (size_t)received;
            have += (size_t)received;
        }
        request[total] = '\0';
    }

    if (body_start == NULL) goto done;

    if (sscanf(request, "%15s %2047s", method, url) != 2) goto not_found;
    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) goto not_found;

    if (strcmp(url, "/") == 0) {
        serve_index(fd);
        goto done;
    }

    if (strcmp(url, "/stream") == 0) {
        stream_live(fd);
        goto done;
    }

    if (strcmp(url, "/recordings") == 0) {
        char *body = NULL;
        size_t body_length = 0;
        FILE *html = open_memstream(&body, &body_length);
        DIR *directory;
        struct dirent *entry;

        if (html == NULL)
            goto not_found;

        fputs(
            "<!doctype html><html lang=\"zh-CN\"><head><meta charset=\"utf-8\">"
            "<title>录像列表</title></head><body><h2>录像列表</h2><ul>",
            html
        );

        directory = opendir(REC_DIR);
        if (directory != NULL) {
            while ((entry = readdir(directory)) != NULL) {
                if (has_mjpg_suffix(entry->d_name))
                    fprintf(
                        html,
                        "<li><a href=\"/watch?name=%s\">%s</a></li>",
                        entry->d_name,
                        entry->d_name
                    );
            }
            closedir(directory);
        }

        fputs("</ul><p><a href=\"/\">返回实时画面</a></p></body></html>", html);
        fclose(html);
        send_response(fd, "200 OK", "text/html; charset=utf-8", body, body_length);
        free(body);
        goto done;
    }

    if (strncmp(url, "/watch?", 7) == 0) {
        char name[256];
        char body[1024];
        int body_length;

        if (get_recording_name(url, name, sizeof(name)) != 0)
            goto not_found;

        body_length = snprintf(
            body,
            sizeof(body),
            "<!doctype html><html lang=\"zh-CN\"><head><meta charset=\"utf-8\">"
            "<title>录像回放</title></head>"
            "<body style=\"margin:0;background:#111;color:#fff;text-align:center\">"
            "<h2>%s</h2><img src=\"/play?name=%s\" style=\"width:95%%;max-width:800px\">"
            "<p><a style=\"color:#6cf\" href=\"/recordings\">返回录像列表</a></p>"
            "</body></html>",
            name,
            name
        );

        send_response(
            fd,
            "200 OK",
            "text/html; charset=utf-8",
            body,
            (size_t)body_length
        );
        goto done;
    }

    if (strncmp(url, "/play?", 6) == 0) {
        char name[256];
        char path[512];
        struct stat file_status;

        if (get_recording_name(url, name, sizeof(name)) != 0)
            goto not_found;

        snprintf(path, sizeof(path), REC_DIR "/%s", name);
        if (stat(path, &file_status) != 0 || !S_ISREG(file_status.st_mode))
            goto not_found;

        stream_recording(fd, path);
        goto done;
    }

    /* ---- 历史数据查询：GET /api/history?n=50 ---- */
    if (strcmp(method, "GET") == 0 &&
        strncmp(url, "/api/history", 12) == 0 &&
        (url[12] == '\0' || url[12] == '?')) {
        int n = 50;
        char *np = strstr(url, "n=");
        if (np != NULL) n = atoi(np + 2);
        if (n < 1 || n > 500) n = 50;
        char *body = history_json(n);
        send_response(fd, "200 OK", "application/json; charset=utf-8",
                      body, strlen(body));
        free(body);
        goto done;
    }

not_found:
    send_response(fd, "404 Not Found", "text/plain", "Not Found\n", 10);

done:
    close(fd);
    return NULL;
}

static void *http_server(void *argument)
{
    int server_fd;
    int reuse = 1;
    struct sockaddr_in address = {0};

    (void)argument;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("HTTP socket");
        return NULL;
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(HTTP_PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("HTTP bind");
        close(server_fd);
        return NULL;
    }

    if (listen(server_fd, 16) < 0) {
        perror("HTTP listen");
        close(server_fd);
        return NULL;
    }

    printf("Web page: http://<server-ip>:%d/\n", HTTP_PORT);

    while (1) {
        int *client_fd = malloc(sizeof(*client_fd));
        pthread_t thread;

        if (client_fd == NULL)
            continue;

        *client_fd = accept(server_fd, NULL, NULL);
        if (*client_fd < 0) {
            free(client_fd);
            continue;
        }

        if (pthread_create(&thread, NULL, http_client, client_fd) != 0) {
            close(*client_fd);
            free(client_fd);
            continue;
        }

        pthread_detach(thread);
    }
}

static void receive_opencv_stream(int client_fd)
{
    uint8_t receive_buffer[65536];
    uint8_t *jpeg = malloc(MAX_JPEG_SIZE);
    size_t jpeg_length = 0;
    int in_frame = 0;
    int previous = -1;
    ssize_t received;

    if (jpeg == NULL)
        return;

    while ((received = recv(client_fd, receive_buffer, sizeof(receive_buffer), 0)) > 0) {
        ssize_t index;

        for (index = 0; index < received; index++) {
            int current = receive_buffer[index];

            if (!in_frame) {
                if (previous == 0xff && current == 0xd8) {
                    jpeg[0] = 0xff;
                    jpeg[1] = 0xd8;
                    jpeg_length = 2;
                    in_frame = 1;
                }
            } else {
                if (jpeg_length >= MAX_JPEG_SIZE) {
                    fprintf(stderr, "Dropped oversized JPEG frame\n");
                    jpeg_length = 0;
                    in_frame = 0;
                } else {
                    jpeg[jpeg_length++] = (uint8_t)current;

                    if (previous == 0xff && current == 0xd9) {
                        record_frame(jpeg, jpeg_length);
                        publish_latest(jpeg, jpeg_length);
                        jpeg_length = 0;
                        in_frame = 0;
                    }
                }
            }

            previous = current;
        }
    }

    free(jpeg);
}

int main(void)
{
    int upload_server_fd;
    int reuse = 1;
    struct sockaddr_in address = {0};
    pthread_t http_thread;

    signal(SIGPIPE, SIG_IGN);

    if (mkdir(REC_DIR, 0755) != 0 && errno != EEXIST) {
        perror("Cannot create recordings directory");
        return EXIT_FAILURE;
    }

    if (pthread_create(&http_thread, NULL, http_server, NULL) != 0) {
        fprintf(stderr, "Cannot start HTTP thread\n");
        return EXIT_FAILURE;
    }

    upload_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (upload_server_fd < 0) {
        perror("Upload socket");
        return EXIT_FAILURE;
    }

    setsockopt(upload_server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(UPLOAD_PORT);

    if (bind(upload_server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Upload bind");
        return EXIT_FAILURE;
    }

    if (listen(upload_server_fd, 4) < 0) {
        perror("Upload listen");
        return EXIT_FAILURE;
    }

    printf("Waiting for OpenCV uploader on TCP port %d...\n", UPLOAD_PORT);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_length = sizeof(client_address);
        int client_fd = accept(
            upload_server_fd,
            (struct sockaddr *)&client_address,
            &client_length
        );

        if (client_fd < 0)
            continue;

        printf(
            "OpenCV uploader connected: %s\n",
            inet_ntoa(client_address.sin_addr)
        );

        receive_opencv_stream(client_fd);
        close(client_fd);
        printf("OpenCV uploader disconnected; waiting for reconnection...\n");
    }
}
