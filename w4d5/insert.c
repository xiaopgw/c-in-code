#include "my.h"

int insert(int *p, int post, int data)
{
    if (post > n)
    {
        printf("你选择了一个数据外的位置，请重新选择");
        return -1;
    }
    for (int i = 0; i < n - post + 1; i++)
    {
        p[n - i + 1] = p[n - i];
    }
    p[post] = data;
    return n += 1;
}