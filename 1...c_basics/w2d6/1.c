#include <stdio.h>


int main(int argc, char const *argv[])
{   
    int a[] = {6, 8};
    void *p;
    int *q = a;
    int *b = (a + 1);
    *b = 7;
    p = q;
    printf("%d\n", *((int *)p + 1));
}
