/*
 * db_logger.c — 数据存储模块（cJSON 版，带"沿用上一次状态"合并）
 * 订阅 MQTT，把传感器历史 + 操作日志存到 SQLite
 *
 * 字段（11 个）：tem hum light smoke flame infrared pum fan led curtain beep
 *   采集（只收）：tem hum light
 *   安全（只收）：smoke flame beep infrared
 *   控制（可收发）：pum fan led（0/1）、curtain（0关/1半/2全）
 *
 * 编译（cJSON.c / cJSON.h 在同目录）：
 *   gcc db_logger.c cJSON.c -o db_logger -lsqlite3 -lmosquitto -lm
 * 运行：
 *   ./db_logger
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sqlite3.h>
#include <mosquitto.h>
#include "cJSON.h"

#define DB_FILE     "gateway.db"
#define BROKER_IP   "192.168.1.42"
#define BROKER_PORT 1883
#define MAX_RECORDS 1000  

static sqlite3 *db = NULL;

static void get_ts(char *buf, int size)
{
    time_t t = time(NULL);
    strftime(buf, size, "%Y-%m-%d %H:%M:%S", localtime(&t));
}

/* 自动清理 */
static void auto_cleanup(void)
{
    char sql[128];
    snprintf(sql, sizeof(sql),
        "DELETE FROM sensor_log WHERE id NOT IN "
        "(SELECT id FROM sensor_log ORDER BY id DESC LIMIT %d);",
        MAX_RECORDS);
    sqlite3_exec(db, sql, NULL, NULL, NULL);
}

/* 存一条传感器数据*/
static void save_sensor(const char *payload)
{
    char ts[32];
    get_ts(ts, sizeof(ts));

    cJSON *root = cJSON_Parse(payload);
    if (root == NULL) {
        printf("JSON 解析失败: %s\n", payload);
        return;
    }

    /* 函数退出后值仍保留 */
    static double last_tem = 0, last_hum = 0;
    static int last_light = 0;
    static int last_smoke = 0, last_flame = 0, last_beep = 0, last_infrared = 0;
    static int last_pum = 0, last_fan = 0, last_led = 0, last_curtain = 0;

    cJSON *j;
    if ((j=cJSON_GetObjectItem(root, "tem")))       
    last_tem=j->valuedouble;
    if ((j=cJSON_GetObjectItem(root, "hum")))       
    last_hum=j->valuedouble;
    if ((j=cJSON_GetObjectItem(root, "light")))     
    last_light=j->valueint;
    if ((j=cJSON_GetObjectItem(root, "smoke")))     
    last_smoke=j->valueint;
    if ((j=cJSON_GetObjectItem(root, "flame")))     
    last_flame=j->valueint;
    if ((j=cJSON_GetObjectItem(root, "beep")))      
    last_beep=j->valueint;
    if ((j=cJSON_GetObjectItem(root, "infrared")))  
    last_infrared=j->valueint;
    if ((j=cJSON_GetObjectItem(root, "pum")))       
    last_pum=j->valueint;
    if ((j=cJSON_GetObjectItem(root, "fan")))       
    last_fan=j->valueint;
    if ((j=cJSON_GetObjectItem(root, "led")))       
    last_led=j->valueint;
    if ((j = cJSON_GetObjectItem(root, "curtain")))   
    last_curtain=j->valueint;

    char sql[768];
    snprintf(sql, sizeof(sql),
        "INSERT INTO sensor_log(ts,tem,hum,light,smoke,flame,infrared,"
        "pum,fan,led,curtain,beep) "
        "VALUES('%s',%.1f,%.1f,%d,%d,%d,%d,%d,%d,%d,%d,%d);",
        ts, last_tem, last_hum, last_light,
        last_smoke, last_flame, last_infrared,
        last_pum, last_fan, last_led, last_curtain, last_beep);

    char *errmsg = NULL;
    if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        fprintf(stderr, "存传感器失败: %s\n", errmsg);
        sqlite3_free(errmsg);
    } else {
        printf("[%s] 已存: tem=%.0f hum=%.0f light=%d smoke=%d flame=%d "
               "ir=%d pum=%d fan=%d led=%d curtain=%d beep=%d\n",
            ts, last_tem, last_hum, last_light,
            last_smoke, last_flame, last_infrared,
            last_pum, last_fan, last_led, last_curtain, last_beep);
    }

    auto_cleanup();
    cJSON_Delete(root);
}

/* 存一条操作日志 */
static void save_cmd(const char *topic, const char *payload)
{
    char ts[32];
    get_ts(ts, sizeof(ts));

    char escaped[512];
    char *q = escaped; const char *p = payload;
    while (*p && q - escaped < (int)sizeof(escaped) - 4) {
        if (*p == '\'' || *p == '\\') { *q++ = '\\'; *q++ = *p++; }
        else *q++ = *p++;
    }
    *q = '\0';

    char sql[600];
    snprintf(sql, sizeof(sql),
        "INSERT INTO cmd_log(ts, cmd) VALUES('%s', '[%s] %s');",
        ts, topic, escaped);

    char *errmsg = NULL;
    if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        fprintf(stderr, "存命令日志失败: %s\n", errmsg);
        sqlite3_free(errmsg);
    } else {
        printf("[%s] 命令日志: %s\n", ts, payload);
    }
}

static void on_message(struct mosquitto *m, void *ctx,
                       const struct mosquitto_message *msg)
{
    if (!msg->payload || msg->payloadlen <= 0) return;

    char *payload = malloc(msg->payloadlen + 1);
    memcpy(payload, msg->payload, msg->payloadlen);
    payload[msg->payloadlen] = '\0';

    printf("收到 %s: %s\n", msg->topic, payload);

    if (strcmp(msg->topic, "stm32/sensor") == 0) {
        save_sensor(payload);
    } else if (strcmp(msg->topic, "stm32/cmd") == 0) {
        save_cmd(msg->topic, payload);
        /* 命令也合并进 sensor_log，这样历史数据能看到命令导致的状态变化 */
        save_sensor(payload);
    }

    free(payload);
}

static void on_connect(struct mosquitto *m, void *ctx, int rc)
{
    if (rc == 0) {
        printf("已连上 MQTT Broker %s:%d\n", BROKER_IP, BROKER_PORT);
        mosquitto_subscribe(m, NULL, "stm32/sensor", 1);
        mosquitto_subscribe(m, NULL, "stm32/cmd", 1);
        printf("已订阅主题: stm32/sensor, stm32/cmd\n");
    } else {
        fprintf(stderr, "MQTT 连接失败, rc=%d\n", rc);
    }
}

int main(void)
{
    printf("db_logger 启动!\n");

    if (sqlite3_open(DB_FILE, &db) != SQLITE_OK) {
        fprintf(stderr, "打开数据库失败: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    printf("数据库打开成功: %s\n", DB_FILE);

    char *errmsg = NULL;
    if (sqlite3_exec(db,
        "CREATE TABLE IF NOT EXISTS sensor_log("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "ts TEXT, tem REAL, hum REAL, light INTEGER,"
        "smoke INTEGER, flame INTEGER, infrared INTEGER,"
        "pum INTEGER, fan INTEGER, led INTEGER,"
        "curtain INTEGER, beep INTEGER);",
        NULL, NULL, &errmsg) != SQLITE_OK) {
        fprintf(stderr, "建 sensor_log 失败: %s\n", errmsg);
        sqlite3_free(errmsg);
        return 1;
    }
    if (sqlite3_exec(db,
        "CREATE TABLE IF NOT EXISTS cmd_log("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "ts TEXT, cmd TEXT);",
        NULL, NULL, &errmsg) != SQLITE_OK) {
        fprintf(stderr, "建 cmd_log 失败: %s\n", errmsg);
        sqlite3_free(errmsg);
        return 1;
    }
    printf("两张表建好（11 字段 sensor_log + cmd_log）\n");

    mosquitto_lib_init();
    struct mosquitto *m = mosquitto_new("db_logger", true, NULL);
    if (!m) {
        fprintf(stderr, "mosquitto_new 失败\n");
        return 1;
    }
    mosquitto_connect_callback_set(m, on_connect);
    mosquitto_message_callback_set(m, on_message);

    if (mosquitto_connect(m, BROKER_IP, BROKER_PORT, 60) != MOSQ_ERR_SUCCESS) {
        fprintf(stderr, "连不上 Broker %s:%d\n", BROKER_IP, BROKER_PORT);
        return 1;
    }

    printf("数据存储模块启动，等待设备数据...\n");
    mosquitto_loop_forever(m, -1, 1);

    mosquitto_destroy(m);
    mosquitto_lib_cleanup();
    sqlite3_close(db);
    return 0;
}
