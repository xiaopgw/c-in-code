#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>
#define N 64
int main(int argc, char const *argv[])
{
    char arecv[N] = {}, arrac[N] = {};
    char asend[N] = {"这里是服务端发送的数据，应该由客户端接收"};
    // 整个流程：创建套接字文件。拿到这个文件的文件描述符
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }
    // 设置开放链接的套接字里面的IP和端口号以及通信方式
    struct sockaddr_in addr, addrci;
    int len = sizeof(addrci);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(25565);
    addr.sin_addr.s_addr = INADDR_ANY;
    // 172.25.227.190
    // 设置开放链接
    int bin = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (bin < 0)
    {
        perror("bin->");
        return -1;
    }
    // 监听
    int lis = listen(sockfd, 5);
    if (lis < 0)
    {
        perror("lis->");
        return -1;
    }
    while (1)
    {

        // 链接客户端
        int accfd = accept(sockfd, (struct sockaddr *)&addrci, &len);
        if (accfd < 0)
        {
            perror("accfd->");
            return -1;
        }
        printf("IP为: %s %d的客户端已连接\n", inet_ntoa(addrci.sin_addr), htons(addrci.sin_port));
        // read(accept, arrac, N - 1);
        // printf("%s\n", arrac);

        // 设置多路复合io
        // fd_set rfds;
        // FD_ZERO(&rfds);
        // FD_SET(accfd)
        // int sel = select();

        while (1)
        {
            ssize_t rec = recv(accfd, arecv, N, 0);
            if (rec < 0)
            {
                if (errno == ECONNRESET)
                {
                    printf("客户端异常断开了\n");
                }
                else
                {
                    perror("rec->");
                    return -1;
                }
            }
            else if (rec == 0)
            {
                // 结束链接
                printf("结束了链接\n");
                break;
                close(accfd);
            }
            ssize_t sen = send(accfd, asend, N, 0);
            if (sen < 0)
            {
                perror("sen->");
                return -1;
            }

            printf("%s\n", arecv);
        }
        // 进行接收和发送
    }
    close(sockfd);
    return 0;
}
