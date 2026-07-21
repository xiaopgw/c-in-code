// #include <stdio.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <errno.h>
// #include <string.h>
// #include <unistd.h>
// #include <arpa/inet.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <sys/select.h>
// #include <sys/time.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/ip.h>
// #include <arpa/inet.h>
// #include <stdlib.h>

// #define N 64

// int main(int argc, char const *argv[])
// {
//     // 创建
//     char arecv[N] = {}, asend[N] = {};
//     int sockfd = socket(AF_INET, SOCK_STREAM, 0);
//     if (sockfd < 0)
//     {
//         perror("sockfd->");
//         return -1;
//     }
//     int opt = 1;
//     if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
//     {
//         perror("setsockopt");
//     }
//     struct sockaddr_in addrse, addrcl;
//     addrse.sin_family = AF_INET;
//     addrse.sin_port = htons(25565);
//     addrse.sin_addr.s_addr = INADDR_ANY;
//     int len = sizeof(addrse);
//     int bin = bind(sockfd, (struct sockaddr *)&addrse, len);
//     if (bin < 0)
//     {
//         perror("bin->");
//         return -1;
//     }
//     listen(sockfd, 5);
//     printf("服务器已打开\n");
//     fd_set readfds, tempfds;
//     FD_ZERO(&readfds);
//     FD_SET(0, &readfds);
//     FD_SET(sockfd, &readfds);
//     int maxfd = sockfd;

//     while (1)
//     {

//         tempfds = readfds;
//         int selectyn = select(maxfd + 1, &tempfds, NULL, NULL, NULL);
//         if (selectyn < 0)
//         {
//             perror("selectyn->");
//             return -1;
//         }
//         if (FD_ISSET(0, &tempfds))
//         {
//             fgets(asend, N, stdin);
//             printf("终端输入了%s", asend);
//         }
//         // select判断sockfd出现变化表示有客户端连接，然后accfd尝试创建传输通道
//         if (FD_ISSET(sockfd, &tempfds))
//         {
//             // printf("a\n");
//             int accfd = accept(sockfd, (struct sockaddr *)&addrcl, &len);
//             if (accfd < 0)
//             {
//                 perror("accfd->");
//                 return -1;
//             }
//             // printf("b\n");
//             if (accfd > maxfd)
//                 maxfd = accfd;
//             // printf("c\n");
//             FD_SET(accfd, &readfds);
//             // printf("d\n");
//             printf("IP为%s:%d的客户端已连接\n",
//             inet_ntoa(addrcl.sin_addr), ntohs(addrcl.sin_port));
//         }
//         for (int i = sockfd + 1; i <= maxfd; i++)
//         {
//             if (FD_ISSET(i, &tempfds))
//             {
//                 int ret = recv(i, arecv, N, 0);
//                 if (ret < 0)
//                 {
//                     perror("ret->");
//                     return -1;
//                 }
//                 else if (ret == 0)
//                 {
//                     printf("客户端%s:%d已退出\n", inet_ntoa(addrcl.sin_addr), ntohs(addrcl.sin_port));
//                     close(i);
//                     FD_SET(sockfd, &readfds);
//                     if (i == maxfd)
//                         maxfd--;
//                 }
//                 else
//                 {
//                     printf("接收到了%s\n", arecv);
//                 }
//             }
//         }
//     }
//     close(sockfd);

//     return 0;
// }

#include <stdio.h>
#include <sys/socket.h> // socket的文件
#include <sys/types.h>  // sockaddr结构体
#include <netinet/in.h> // sockaddr_in结构体
#include <sys/select.h> //select头文件
#include <unistd.h>
#include <arpa/inet.h> //inet_ntoa


#define N 64

int main(int argc, char const *argv[])
{
    // 创建服务器
    char arecv[N] = {}, asend[N] = {};
    // 创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }

    // 设置服务端接收的结构体
    struct sockaddr_in addrs, addrc;
    addrs.sin_family = AF_INET;
    addrs.sin_port = htons(25565);
    addrs.sin_addr.s_addr = INADDR_ANY;
    // 服务端对外开放
    int len = sizeof(addrs);
    if (bind(sockfd, (struct sockaddr *)&addrs, len) < 0)
    {
        perror("bind->");
        return -1;
    }
    // 监听
    if (listen(sockfd, 5) < 0)
    {
        perror("listen->");
        return -1;
    }

    // 多路混合复用
    // 建空，设置监听位置
    fd_set readfds, tempfds;
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    FD_SET(sockfd, &readfds);
    // 创建镜像表

    int maxfds = sockfd;

    // 循环
    while (1)
    {
        tempfds = readfds;
        // select监听如果sockfd变化则创建通道，然后同时也创建了文件描述符
        printf("运行一下select\n");
        int sel = select(maxfds + 1, &tempfds, NULL, NULL, NULL);
        if (sel < 0)
        {
            perror("sel->");
            return -1;
        }

        // 然后把新的文件描述符放到表里
        // 创建双机交换通道
        if (FD_ISSET(sockfd, &tempfds))
        {
            int accfd = accept(sockfd, (struct sockaddr *)&addrc, &len);
            if (accfd < 0)
            {
                perror("accept->");
                return -1;
            }
            FD_SET(accfd, &readfds);
            // FD_SET(accfd, &tempfds);
            if (accfd > maxfds)
                maxfds = accfd;
            printf("连接的服务为%s:%d\n", inet_ntoa(addrc.sin_addr), ntohs(addrc.sin_port));
        }

        // 循环判断如果sockfd后面的有变化则打印客户端的内容
        for (int i = sockfd + 1; i <= maxfds; i++)
        {
            if (FD_ISSET(i, &tempfds))
            {
                // 接收打印客户端的信息
                int rec = recv(i, arecv, N, 0);
                if (rec < 0)
                {
                    perror("rec->");
                    close(i);
                }
                else if (rec == 0)
                {
                    printf("客户端%s:%d退出\n",inet_ntoa(addrc.sin_addr), ntohs(addrc.sin_port));
                    close(i);
                    FD_CLR(i, &readfds);
                    if (i == maxfds)
                        maxfds--;
                }
                else
                {
                    printf("从客户端接收：%s\n", arecv);
                }
            }
        }
    }
    close(sockfd);
    return 0;
}
