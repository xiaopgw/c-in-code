#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#define N 32
int main(int argc, char const *argv[])
{
    char arr2[N] = {};
    struct in_addr in;
    // 将字符串ip转换为32位无符号整数ip
    in.s_addr = inet_addr("185.199.110.153");
    char *arr = inet_ntoa(in);
    printf("IP为: %s\n", arr);



    // 创建流式套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }
    printf("sockfd的文件描述符: %d\n", sockfd);
    // 填充服务器的结构体信息
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(25565);
    addr.sin_addr.s_addr = inet_addr("172.25.227.190");

    // 绑定
    int bin = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (bin < 0)
    {
        perror("bin->");
        return -1;
    }
    listen(sockfd, 5);
    accept(sockfd, NULL, NULL);
    recv(sockfd, "test", N, 0);
    send(sockfd, "test2", N, 0);
    connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));



    return 0;
}