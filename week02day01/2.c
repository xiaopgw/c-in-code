#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    //反转
    char buf[32] = "Hello world";
    int len = sizeof(buf) / sizeof(buf[0]);
    for (int i = 0; i < len; i++)       //没想到要去掉/0
    {                                   //\0会终止字符串处理函数的读取 
        if (buf[i] == 0)
        {
            len = i;
        }
    }
    for (int i = 0; i < len / 2; i++)   //没想到要len/2
    {

        buf[i] ^= buf[len - 1 - i];
        buf[len - 1 - i] ^= buf[i];
        buf[i] ^= buf[len - 1 - i];
    }
    printf("%s\n", buf);
    
    //字符记录
    int A = 0, a = 0, space = 0, num = 0;
    char arr[32] = {0};
    int cou = sizeof(arr) / sizeof(arr[0]);
    // printf("%c", arr[0]);
    scanf("%[^\n]", arr);
    for (int i = 0; i < cou; i++)
    {
        if (arr[i] == 0)
        {
            break;
        }
        else if (arr[i] == ' ')                     //空格的ascii是10
        {
            space++;
        }
        else if (arr[i] >= '0' && arr[i] <= '9')
        {
            num++;
        }
        else if (arr[i] >= 'A' && arr[i] <= 'Z')    //偏移量的中括号打错了
        {
            A++;
        }
        else if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            a++;
        }
    }
    printf("-A%d-a%d-num%d-space%d", A, a, num, space);
    printf("%d\n", arr[8]);
    
}

