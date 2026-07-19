#include "my.h"
int main(int argc, char const *argv[])
{
    //     fd_set table;
    //     int num = 0;
    //     char arr[64] = {};
    //     int fd = open("/dev/input/mouse0", O_RDONLY);
    //     if (fd == NULL)
    //     {
    //         perror("open->");
    //         return -1;
    //     }
    //     FD_ZERO(&table);
    //     FD_SET(fd, &table);
    //     FD_SET(0, &table);
    //     num = select(fd + 1, &table, NULL, NULL, NULL);
    //     if (num > 0)
    //     {
    //         perror("select->");
    //         return -1;
    //     }
    //     else if (num == 0)
    //     {
    //         printf("time out\n");
    //     }

    //     if (FD_ISSET(0, &table))
    //     {
    //         int i = read(0, arr, 64);
    //         // arr[i - 1] = '\0';
    //         printf("%s\n", arr);
    //     }
    //     if (FD_ISSET(fd, &table))
    //     {
    //         int i = read(fd, arr, 64);
    //         // arr[i - 1] = '\0';
    //         printf("%s\n", arr);
    //     }

    // 打开这个文件
    // 新建int记录计算有多少行
    // 从上一行继续打印fprintf的时间戳
    // 看看这两个time都是干啥用的

    int n = 0;
    char arr[N] = {};
    FILE *fp = fopen(argv[1], "a+");
    while (fgets(arr, N, fp) != NULL)
    {
        // printf("%d\n", arr[strlen(arr) - 1]);
        if (arr[strlen(arr) - 1] == '\n')
        {
            n++;
        }
    }

    while (1)
    {
        time_t now = time(NULL);
        struct tm *tn = localtime(&now);
        char time[N] = {};
        fprintf(fp, "%d, %d-%d-%d %d:%d:%d\n", ++n,
               tn->tm_year + 1900,
               tn->tm_mon + 1,
               tn->tm_mday,
               tn->tm_hour,
               tn->tm_min,
               tn->tm_sec);
        // n++;
        fflush(NULL);
        sleep(1);
    }



    // select设置I/O多路复用模型
    // 6步
    // 设置双同步（）
    int ret = 0;
    char arr[N] = {};
    int fd = open(argv[1], O_RDONLY | O_NONBLOCK);
    if (fd < 0)
    {
        perror("fd->");
        return 0;
    }
        
    fd_set readfds;
    while(1)
    {
        struct timeval tm = {5, 0};
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);
        FD_SET(0, &readfds);
        ret = select(fd + 1, &readfds, NULL, NULL, &tm);
        if (ret == 0)
        {
            printf("time out\n");
        }
        else if (ret < 0)
        {
            perror("ret->");
            return 0;
        }
        if (FD_ISSET(fd, &readfds))
        {
            int len = read(fd, arr, N - 1);
            if (arr[len - 1] == '\n')
                arr[len - 1] = '\0';
            if (len > 0)
            {
                printf("%s\n", arr);
            }
            else if(len == 0)
            {
                FD_CLR(fd, &readfds);
            }
            
        }
        if (FD_ISSET(0, &readfds))
        {
            int len = read(0, arr, N - 1);
            if (arr[len - 1] == '\n')
                arr[len - 1] = '\0';
            printf("%s\n", arr);
        }
    }
    return 0;
}
