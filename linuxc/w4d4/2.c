#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4};
    int b[] = {1,2,3,4};
    int c[] = {1,2,3};
    int d[] = {1,2,3,4};
    int *p[4] = {a, b, c, d};
    printf("%d\n", p[2][3]);
    printf("%d\n", p[3][0]);
    return 0;
}
