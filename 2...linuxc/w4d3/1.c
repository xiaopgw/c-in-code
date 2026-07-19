#include <stdio.h>
#define A 0
int l(int a){return a;}
int l1(int a){return a;}
int l2(int a){return a;}
int l3(int a){return a;}
int l4(int a){return a;}
int l5(int a){return a;}
int l6(int a){return a;}
int l7(int a){return a;}
int l8(int a){return a;}
int l9(int a){return a;}
int l0(int a){return a;}



int main(int argc, char const *argv[])
{
    #if A
        printf("yeh");
    #else
        printf("ohhh");
    #endif

    int a[] = {1, 2, 3};
    int *p = a;
    printf(" ");
    // int *q = &p;
    // int p[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int a1[5],a2[5],a3[5],a4[5],a5[5],a6[5],a7[5],a8[5],a9[4],a0[4];
    // int *p[5] = {&a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a0};
    // int *q = p;
    int (*j)(int) = l;
    int (*i[10])(int) = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l0};
    return 0;
}

int a(char *p[0])
{

    
}