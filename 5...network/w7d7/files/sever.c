#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 64

void sendfile(int accfd);
void recvfile(int accfd);

int main(int argc, char const *argv[])
{
    char arecv[N] = {}, asend[N] = {};
    // 建立服务端套接字文件描述符
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }
    // 设置服务端地址信息的结构体
    struct sockaddr_in addrsev, addrcli;
    addrsev.sin_family = AF_INET;
    addrsev.sin_port = htons(25565);
    addrsev.sin_addr.s_addr = INADDR_ANY;
    int len = sizeof(addrsev);
    // 设置开放这个地址可以连接进来
    int bin = bind(sockfd, (struct sockaddr *)&addrsev, len);
    if (bin < 0)
    {
        perror("bin->");
        return -1;
    }
    // 监听
    int lis = listen(sockfd, 5);
    // 死循环
    while (1)
    {
        // 接受客户端发来的连接进行匹配
        int accfd = accept(sockfd, (struct sockaddr *)&addrcli, &len);
        if (accfd < 0)
        {
            perror("accfd->");
            return -1;
        }
        printf("域名为%s:%d的客户端已登录\n", inet_ntoa(addrcli.sin_addr), ntohs(addrcli.sin_port));
        // 如果有进行来匹配的则发送选项：

        printf("等待客户端选择上传/下载文件中\n\n");
        while (1)
        {
            // 循环显示要选哪一个
            int rec = recv(accfd, arecv, N, 0);
            if (rec < 0)
            {
                if (errno == ECONNRESET)
                {
                    printf("客户端异常断开\n");
                }
                else if (rec < 0)
                {
                    perror("rec->");
                    return -1;
                }
            }
            if (rec == 0)
            {
                printf("域名为%s:%d的客户端已退出\n", inet_ntoa(addrcli.sin_addr), ntohs(addrcli.sin_port));
                break;
            }
            // 上传文件函数
            if (!strcmp(arecv, "upload"))
            {
                printf("客户端选择了上传文件%s\n", arecv);
                sendfile(accfd);
            }
            // 下载文件函数
            else if (!strcmp(arecv, "download"))
            {
                printf("客户端选择了下载文件%s\n", arecv);
                recvfile(accfd);
            }
            // 退出客户端
            else if (!strcmp(arecv, "quit"))
            {
                printf("客户端已退出\n");
                close(accfd);
                break;
            }
            else if (!strcmp(arecv, "exit"))
            {
                close(accfd);
                close(sockfd);
                return 0;
            }
            else
            {
                printf("你输鸡毛呢，滚回去重练\n");
            }
            // fflush(NULL);
        }
    }

    return 0;
}

// 上传文件结构体(我们还是把上传和下载全整合到一起)
// 当客户端选择上传后，发送来的文件名进行创建，                                                         当然服务端也可以选择要下载的文件名，不对，服务器不能选择，一般都是客户端进行请求
// 然后根据发送来的文件内容进行书写，当然需要打开文件,判断\n等等操作
void sendfile(int accfd)
{
    // printf("进入了函数内部\n");
    char arecv[N] = {}, asend[N] = {};
    int rec = recv(accfd, arecv, N, 0);
    if (rec < 0)
    {
        if (errno == ECONNRESET)
        {
            printf("客户端异常断开\n");
        }
        else if (rec < 0)
        {
            perror("rec->");
            return;
        }
    }
    printf("客户端请求上传%s\n", arecv);
    // printf("文件名为%s,即将打开文件\n", arecv);
    FILE *fp = fopen(arecv, "a+");
    if (fp < 0)
    {
        perror("fp->");
        return;
    }
    // printf("已经打开, 开始接收\n");
    // recv(accfd, arecv, N, 0);
    // printf("已接收内容为%s, 准备写入\n", arecv);
    // fputs(arecv, fp);
    while (1)
    {
        recv(accfd, arecv, N, 0);
        // printf("接收到了：\n%s\n", arecv);
        if (!strcmp(arecv, "close"))
        {
            printf("已全部接收完毕\n");
            break;
        }
        fputs(arecv, fp);
        fflush(NULL);
        send(accfd, asend, N, 0);

        // send(sockfd, asend, strlen(asend), 0);
    }
    printf("传输已完成\n");
}
// 下载文件结构体
// 此时这里客户端是下载文件，需要等待客户端选择的文件名等客户端进行创建
// 然后把文件内容发送过去
void recvfile(int accfd)
{

    char asend[N] = {}, arecv[N] = {};
    FILE *fp;
    while (1)
    {
        int rec = recv(accfd, arecv, N, 0);
        if (rec < 0)
        {
            if (errno == ECONNRESET)
            {
                printf("客户端异常断开\n");
            }
            else if (rec < 0)
            {
                perror("rec->");
                return;
            }
        }
        printf("客户端请求下载%s\n", arecv);
        // printf("%s\n", arecv);
        fp = fopen(arecv, "r");
        if (fp == NULL)
        {
            printf("fp不等于NULL\n");
            if (errno == ENOENT)
            {
                printf("不存在这个文件，请重新输入\n");
                strcpy(asend, "remix");
                send(accfd, asend, strlen(asend) + 1, 0);
                continue;
            }
            else if (fp == NULL)
            {
                perror("fp->");
                return;
            }
        }
        strcpy(asend, "next");
        send(accfd, asend, strlen(asend) + 1, 0);
        break;
    }
    printf("开始循环把文件内容下载下来\n");
    while (1)
    {
        if (fgets(asend, N, fp) == NULL)
        {
            printf("传输到结尾了\n");
            break;
        }
        // printf("读取到了: \n%s\n", asend);
        send(accfd, asend, strlen(asend) + 1, 0);
        recv(accfd, arecv, sizeof(arecv), 0);
    }
    send(accfd, "close", sizeof("close"), 0);
}
// 可以用打开文件看看文件存不存在