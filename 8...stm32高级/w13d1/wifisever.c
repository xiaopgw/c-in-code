// 创建套接字服务器
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>
#define N 128

void *send_thread(void *accfd);
void *recv_thread(void *accfd);

char arecv[N] = {}, arrac[N] = {};
int main()
{

    // char asend[N] = {"[服务器]您已连接上笑破怪物超绝服务器"};
    // 创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }
    // 指定网络信息(结构体)
    struct sockaddr_in addr, addrci;
    int len = sizeof(addrci);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = INADDR_ANY;
    // 绑定
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
    // 连接
    while (1)
    {
        printf("等待客户端连接...\n");
        // 链接客户端
        int accfd = accept(sockfd, (struct sockaddr *)&addrci, &len);
        if (accfd < 0)
        {
            perror("accfd->");
            return -1;
        }
        printf("单片机成功连接\n");
        // 发送接收
        // 在你 accept 成功之后调用：
        pthread_t t1, t2;
        pthread_create(&t1, NULL, recv_thread, &accfd);
        pthread_create(&t2, NULL, send_thread, &accfd);
    }
    // 关闭套接字
    close(sockfd);
    return 0;
}

void *recv_thread(void *arg)
{
    int accfd = *(int *)arg;
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
                return NULL;
            }
        }
        else if (rec == 0)
        {
            // 结束链接
            printf("结束了链接\n");
            break;
            close(accfd);
        }

        printf("%s\n\n\n", arecv);
        memset(arecv, 0, N);
    }
}
void *send_thread(void *arg)
{
    int accfd = *(int *)arg;
    char asend[N] = {};
    while (1)
    {
        scanf("%s", asend);
        ssize_t sen = send(accfd, asend, N, 0);
        if (sen < 0)
        {
            perror("sen->");
            return NULL;
        }
    }
}