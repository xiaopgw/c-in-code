#include <stdio.h>
int main()
{
    float a = 31.41;
    int b = a;
    int c = (a - b) * 100;
    printf("%d\n%d\n", b, c);
}