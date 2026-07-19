#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>
#include <pthread.h>

#define N 64

int main(int argc, char const *argv[])
{
    char arecv[N] = {}, arrac[N] = {};
    char asend[N] = {"这里是服务端发送的数据，应该由客户端接收"};
    // 整个流程：创建套接字文件。拿到这个文件的文件描述符
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
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
    while (1)
    {

        // 进行接收和发送
        ssize_t recf = recvfrom(sockfd, arecv, N, 0, (struct sockaddr *)&addrci, &len);
        if (recf < 0)
        {
            perror("recf->");
            return -1;
        }
        printf("%s\n", arecv);
        if (sendto(sockfd, asend, N, 0, (struct sockaddr *)&addrci, len) < 0)
        {
            perror("sendf");
            return -1;
        }
    }
    // close(sockfd);
    return 0;
}
