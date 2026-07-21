#include <stdio.h>
#include <sys/socket.h> // socket的文件
#include <sys/types.h>  // sockaddr结构体
#include <netinet/in.h> // sockaddr_in结构体
#include <sys/select.h> //select头文件
#include <unistd.h>
#include <arpa/inet.h> //inet_ntoa
#include <string.h>

#define N 64

int main(int argc, char const *argv[])
{
    char arecv[12] = {};
    uint8_t asend[N] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
                        0x01, 0x03, 0x00, 0x00, 0x00, 0x01};
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
    addrsev.sin_port = htons(502);
    addrsev.sin_addr.s_addr = inet_addr("192.168.234.1");
    int len = sizeof(addrsev);

    // 尝试连接
    int con = connect(sockfd, (struct sockaddr *)&addrsev, len);
    if (con < 0)
    {
        perror("con->");
        return -1;
    }
    send(sockfd, asend, 12, 0);
    // printf("已连接\n请输入读取数据的代码:\n");
    // int l = read(0, asend, N);
    // asend[l - 1] = 0;
    // printf("要发送的代码是\n%s\n", asend);

    
    recv(sockfd, arecv, 11, 0);
    // write(0, arecv, 12);
    for (int i = 0; i < 11; i++)
    {
        printf("%02X ", arecv[i]); // 打印成 "00 00 00 00 00 07 ..."
    }
    printf("\n");
    
    return 0;
}
// 0x00,0x00,0x00,0x00,0x00,0x06,0x01,0x03,0x00,0x00,0x00,0x01