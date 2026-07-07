#include "my.h"
int main(int argc, char const *argv[])
{

    FILE *fp = fopen("test", "r+");
    if (NULL == fp)
    {
        perror("X->");
        return -1;
    }
    char arr[N] = {};
    int len = 1;
    while (fgets(arr, N, fp) != NULL)
    {
        // printf("%d\n", arr[strlen(arr) - 1]);
        if (arr[strlen(arr) - 1] == '\n')
        {
            len++;
        }
    }
    // 如果我就是不用fprintf呢, 假设就做到百位数
    char num[N] = "1";
    char hello[N] = ", hello\n";

    while (1)
    {
        int i = 0;
        int n = len;
        while (n)
        {
            int t = n % 10 + 48;
            n = n / 10;
            num[i] = t;
            i++;
        }
        for (int i = 0; i < strlen(num) / 2; i++)
        {
            char lin = num[i];
            num[i] = num[strlen(num) - i - 1];
            num[strlen(num) - i - 1] = lin;
        }
        
        fputs(num, fp);
        fputs(hello, fp);
        fflush(NULL);
        len++;
        sleep(1);
    }

    // 用fprintf
    
    // while(1)
    // {
    //     fprintf(fp, "%d, hello\n", len);
    //     fflush(NULL);
    //     len++;
    //     sleep(1);
    // }
    return 0;
}
