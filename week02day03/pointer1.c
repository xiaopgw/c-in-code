#include <stdio.h>
#include <string.h>

// #define GE "个"
#
int main(int argc, char const *argv[])
{
    // char s[32] = "hello";
    // char *p = s;
    // p++;
    // char y = (*p--)++;
    // printf("%c\n", y);
    // printf("%s\n", s);
    // printf("%s\n", p);
    // return 0;

    // char arr[9] = "hello";
    // int l = strlen(arr);
    // char *p = arr;
    // char *q = &arr[l - 1];
    // for (int i = 0; i < l / 2; p++, q--, i++)
    // {
    //     *p ^= *q;
    //     *q ^= *p;
    //     *p ^= *q;
    // }
    // printf("%s\n", arr);

    // int a1 = 1;
    // int *p1 = &a1;
    // printf("%ld\n", sizeof(p1));
    // int a2[5] = {1};
    // int *p2 = a2;
    // printf("%ld\n", sizeof(a2));
    // char a3 = 'W';
    // char *p3 = &a3;
    // printf("%ld\n", sizeof(p3));
    // float a4 = 3.14;
    // float *p4 = &a4;
    // printf("%ld\n", sizeof(p4));
    
    // char arr[32] = "12345";
    // int l = strlen(arr);
    // char *p = arr;
    // int a = 0;
    // for (int i = 0; i < l; i++, p++)
    // {
    //     if (*p >= '0' && *p <= '9')
    //     {
    //         a = a * 10 + *p - 48;
    //     }
    //     else
    //     {
    //         printf("X\n");
    //         return -1;
    //     }
    // }
    // printf("%d\n", a);

    char a[33] = "hello";
    char b[32] = "world";
    char *p = a;
    char *q = b;
    int j = 0;
    for (; b[j] != '\0'; j++);  
    for (int i = 0; !(a[i] == '\0' && i >= j); i++)
    {
        *p ^= *q;
        *q ^= *p;
        *p ^= *q;
        q++;
        p++;
    }
    printf("b-%s ", b);
    printf("a-%s\n", a);
}
