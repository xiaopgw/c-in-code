#include <stdio.h>
// #include <sys/types.h>
#include <sys/select.h>
// #include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/errno.h>
#define N 32

int main(int argc, char const *argv[])
{
    char arr[N] = {"hello"};
    char arr2[N] = {};
    char arr3[N] = {};
    int fd[2] = {};
    pipe(fd);
    int fs = fork();
    if (fs < 0)
    {
        perror("X->");
        return -1;
    }
    else if (fs == 0)
    {
        while (1)
        {
            int rt = write(fd[1], arr, N - 1);
            // printf("1");
            sleep(3);
        }
        exit(0);
    }
    // 创表
    fd_set rfds;
    while (1)
    {
        struct timeval fdtm = {1, 0};
        // 清空表
        FD_ZERO(&rfds);
        // 把要监控的放到表里
        FD_SET(0, &rfds);
        FD_SET(fd[0], &rfds);
        // select
        int se = select(4 + 1, &rfds, NULL, NULL, &fdtm);
        if (se < 0)
        {
            perror("X->");
            return -1;
        }
        else if (se == 0)
        {
            printf("time zero\n");
            break;
        }

        // 查看是否有变化
        if (FD_ISSET(0, &rfds))
        {
            while (1)
            {

                int len = read(0, arr2, N - 1);
                if (arr2[len - 1] == 10)
                {
                    arr2[len - 1] = 0;
                    printf("%s", arr2);
                    fflush(NULL);
                    break;
                }
                else
                {
                    printf("%s", arr2);
                }
            }
        }
        if (FD_ISSET(fd[0], &rfds))
        {
            int len = read(fd[0], arr3, N - 1);
            printf("%s\n", arr3);
        }
        // 返回到应用层
    }
    // 共享内存
    key_t key = 0;
    key = ftok("1.c", 51);
    int shmid = shmget(key, N, IPC_CREAT | IPC_EXCL | 0765);
    if (shmid <= 0)
    {
        if (errno == EEXIST)
        {
            shmid = shmget(key, N, 0765);
        }
        if (shmid <= 0)
        {
            perror("X->");
            return -1;
        }
    }
    
    return  0;
}
