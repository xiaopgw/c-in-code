#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { perror("socket"); return -1; }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return -1;
    }

    printf("服务器启动，正在等待连接...\n");
    fflush(stdout);

    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int accfd = accept(sockfd, (struct sockaddr*)&client, &len);
    if (accfd < 0) {
        perror("accept");
        return -1;
    }

    printf("✅ 连接成功！客户端IP: %s, 端口: %d\n",
           inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    fflush(stdout);

    close(accfd);
    close(sockfd);
    return 0;
}