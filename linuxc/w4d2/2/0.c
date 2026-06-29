#include<stdio.h>
#include"my.h"
extern int a;
int main(int argc, char const *argv[])
{
    printf("Hello %d %d\n", a, b());
    return 0;
}
