#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define N 32
int main(int argc, char const *argv[])
{
    char arecv[] = "stest", asend[N];
    FILE *fp = fopen(arecv, "a+");
    if (fp == NULL)
    {
        if (errno == ENOENT)
        {
            printf("不存在这个文件，请重新输入\n");
        }
        else if (fp == NULL)
        {
            perror("fp->");
            return -1;
        }
    }
    if (fgets(asend, N, fp) == NULL)
        {
            printf("传输到结尾了\n");
        }
}