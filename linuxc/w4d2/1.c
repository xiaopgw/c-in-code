#include<stdio.h>
#include<stdlib.h>
// #include<unistd.h>
// #include"my.h"
int main(int argc, char const *argv[])
{
    
    char *p = (char *)malloc(5);
    // char a[5] = { 0 };
    // printf("%c\n", a[5]);
    p[4] = 'c';
    printf("%c\n", p[4]);
    // int n = 0;
    // printf("%d\n", n);
    return 0;
}

// tes test1;
    // test1.x = 1;
    // test1.y = 1;
    // printf("%d%d", test1.x, test1.y);
    // printf("%d\n", a);
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n", i);
    // }