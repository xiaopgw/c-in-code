#include "my.h"

int deletem(int *p, int post)
{
    if (post > n)
    {
        printf("你选择了一个数据外的位置，请重新选择");
        return -1;
    }
    for (int i = post; i < n; i++)
    {
        p[i] = p[i + 1];
    }
    return n--;
}