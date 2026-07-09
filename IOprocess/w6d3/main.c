#include "my.h"
int main(int argc, char const *argv[])
{
    // char arr[4] = {};
    // int fd = open("test", O_RDONLY);
    // int fb = open("text", O_WRONLY | O_CREAT, 0755);
    // int arr = 0;
    // while((arr = read(fd, arr, sizeof(arr))) > 0)
    // {
    //     write(fb, arr, arr);
    // }
    // fun();
    // printf("%d\n", add(3, 4));

    if (argc == 1)
    {
        printf("没数呢\n");
        return -1;
    }

    char arr[N] = {};
    int n = 0;
    strcpy(arr, argv[1]);
    // printf("%s\n", arr);
    if (arr[0] == '-')
    {
        for (int i = 1; i <= strlen(arr) - 1; i++)
        {
            n = n * 10 + arr[i] - 48;
        }
        // printf("%d\n", n);

        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL)
        {
            perror("X->");
            return -1;
        }

        for (int i = 0; i < n; i++)
        {
            while (fgets(arr, N, fp) != NULL)
            {
                printf("%s", arr);
                if (arr[strlen(arr) - 1] == '\n')
                    break;
            }
        }
        fclose(fp);
    }
    else
    {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            perror("X->");
            return -1;
        }

        for (int i = 0; i < 10; i++)
        {
            while (fgets(arr, N, fp) != NULL)
            {
                printf("%s", arr);
                if (arr[strlen(arr) - 1] == '\n')
                {
                    break;
                }
            }
        }
        fclose(fp);
    }

    return 0;
}
