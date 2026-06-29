#include <stdio.h>
int main()
{
    int x = 21, y = 36;
    x = y++ + x++;
    y = ++y + ++x;
    printf("%d%d", x, y);
}