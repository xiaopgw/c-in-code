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
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define N 64

int main(int argc, char const *argv[])
{
    char arecv[N] = {}, asend[N] = {};
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("sockfd->");
        return -1;
    }
    struct sockaddr_in addrse, addrcl;
    addrse.sin_family = AF_INET;
    addrse.sin_port = htons(25565);
    addrse.sin_addr.s_addr = inet_addr("172.25.227.190");
    int len = sizeof(addrse);

    int con = connect(sockfd, (struct sockaddr *)&addrse, len);
    if (con < 0)
    {
        perror("con->");
        printf("errno: %d\n", errno);
        return -1;
    }
    printf("connect succeeded!\n");
    while (1)
    {
        fgets(asend, N, stdin);
        if (asend[strlen(asend) - 1] == 10)
            asend[strlen(asend) - 1] = 0;

        printf("终端输入了%s\n", asend);
        send(sockfd, asend, strlen(asend) + 1, 0);
    }

    return 0;
}
