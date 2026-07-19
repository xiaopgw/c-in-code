#include <stdio.h>
// #include <sys/fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define N 64

void sendfile(int sockfd);
void recvfile(int sockfd);

int main(int argc, char const *argv[])
{
    char arecv[N] = {}, asend[N] = {};
    // 建立客户端套接字文件描述符
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }

    // 设置客户端要连接的服务端的地址信息的结构体
    struct sockaddr_in addrsev, addrcli;
    addrsev.sin_family = AF_INET;
    addrsev.sin_port = htons(25565);
    addrsev.sin_addr.s_addr = inet_addr("172.25.227.190");
    int len = sizeof(addrsev);
    // 尝试连接
    int con = connect(sockfd, (struct sockaddr *)&addrsev, len);
    if (con < 0)
    {
        perror("con->");
        return -1;
    }
    while (1)
    {
        // 连接成功出现三个选项，此时客户端选择哪一个可以传到服务端，让两个选择匹配
        printf("请输入要选择的操作\n");
        printf("-------upload-------\n");
        printf("------download------\n");
        printf("--------quit--------\n");
        // while (1)
        // {

        if (fgets(asend, N - 1, stdin) == NULL)
        {
            perror("fgets->");
            return -1;
        }

        if (asend[strlen(asend) - 1] == '\n')
        {
            asend[strlen(asend) - 1] = 0;
        }
        send(sockfd, asend, N, 0);
        // 上传文件函数
        if (!strcmp(asend, "upload"))
        {

            printf("客户端输入了%s\n", asend);
            sendfile(sockfd);
        }
        // 下载文件函数
        else if (!strcmp(asend, "download"))
        {
            recvfile(sockfd);
            printf("客户端输入了%s\n", asend);
        }
        // 退出客户端
        else if (!strcmp(asend, "quit"))
        {
            close(sockfd);
            break;
        }
        else if (!strcmp(asend, "exit"))
        {
            close(sockfd);
            break;
        }
        else
        {
            printf("你输鸡毛呢，滚回去重练\n");
        }
        // fflush(NULL);
        // }
        // 之后的选择都可以匹配
    }

    return 0;
}
// 上传文件函数
// 当客户端选择某个文件名时，服务端同时显示的是文件的名字
// 此时客户端上传完选择后，然后会上传选择文件的内容和文件名
// 现在就用普通的文件类型
void sendfile(int sockfd)
{
    char asend[N] = {"test"}, arecv[N] = {};
    FILE *fp;
    while (1)
    {
        printf("请输入你要上传的文件的名字\n");
        fgets(asend, N, stdin);
        if (asend[strlen(asend) - 1] == '\n')
        {
            asend[strlen(asend) - 1] = 0;
        }
        fp = fopen(asend, "r");
        if (fp == NULL)
        {
            if (errno == ENOENT)
            {
                printf("不存在这个文件，请重新输入\n");
                continue;
            }
            else if (fp == NULL)
            {
                perror("fp->");
                return;
            }
        }
        break;
    }
    send(sockfd, asend, N, 0);
    // printf("已经打开, 开始发送\n");
    // getchar();
    // fgets(asend, N, fp);
    // printf("已读取内容为%s, 准备发送\n", asend);
    // send(sockfd, asend, strlen(asend), 0);
    while (1)
    {
        if (fgets(asend, N, fp) == NULL)
        {
            printf("传输到结尾了\n");
            break;
        }

        // printf("读取到了: \n%s\n", asend);
        send(sockfd, asend, strlen(asend) + 1, 0);
        // printf("发送了: \n%s\n", asend);
        recv(sockfd, arecv, sizeof(arecv), 0);
        // getchar();
    }
    send(sockfd, "close", sizeof("close"), 0);
    printf("上传完成点击回车继续\n");
    getchar();
}

// 下载文件结构体
// 选择下载后把文件名发送过去，然后进行创建
// 把创建的文件的内容接受过来写入到文件里
void recvfile(int sockfd)
{
    char arecv[N] = {}, asend[N] = "test";
    FILE *fp;
    while (1)
    {
        printf("请输入你要下载的文件的名字\n");
        fgets(asend, N, stdin);
        if (asend[strlen(asend) - 1] == '\n')
        {
            asend[strlen(asend) - 1] = 0;
        }
        send(sockfd, asend, N, 0);
        recv(sockfd, arecv, N, 0);
        if (!strcmp(arecv, "remix"))
        {
            printf("不存在这个文件，请重新输入\n");
            continue;
        }
        else if(!strcmp(arecv, "next"))
        {
            break;
        }
        printf("这里应该永远也达不到\n");
        break;
    }
    fp = fopen(asend, "a+");
    while (1)
    {
        recv(sockfd, arecv, N, 0);
        // printf("接收了%s\n", arecv);
        if (!strcmp(arecv, "close"))
        {
            printf("已全部接收完毕\n");
            break;
        }
        fputs(arecv, fp);
        fflush(NULL);
        send(sockfd, asend, N, 0);
    }
    printf("下载完成点击回车继续\n");
    getchar();
}