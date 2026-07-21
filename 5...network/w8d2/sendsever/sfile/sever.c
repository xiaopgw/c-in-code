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

// 基础收发函数
int send_all(int fd, const char *asend, size_t len)
{
    size_t total = 0;
    const char *arr = asend;
}
int recv_exact()
{

}
// 行协议函数
int send_line()
{

}
int recv_line()
{

}
// 长度前缀协议
int send_msg()
{

}
int recv_msg()
{

}