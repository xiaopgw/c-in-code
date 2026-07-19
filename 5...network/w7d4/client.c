#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#define N 64
int main(int argc, char const *argv[])
{
    char arecv[N] = {};
    char asend[N] = {"这里是客户端发送的数据，应该由服务端接收"};
    // 创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }
    // 向服务端发送请求
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(25565);
    // atoi(argv[2])
    addr.sin_addr.s_addr = inet_addr("192.168.50.141");
    // argv[1]
    // 172.25.227.190
    while (1)
    {
        // 进行接收和发送
        fgets(sockfd, asend, N - 1);
        // sendto(sockfd, );
        // if (sen < 0)
        // {
        //     perror("sen->");
        //     return -1;
        // }
        ssize_t rec = recv(sockfd, arecv, N, 0);
        if (rec < 0)
        {
            perror("rec->");
            return -1;
        }
            printf("%s\n", arecv);
    }
    // 结束链接
    close(sockfd);
    return 0;
}
