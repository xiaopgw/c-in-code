#include "my.h"
int seplist_insert(int *p, int *last, int post, int data)
{
    printf("-%d\n", *last);
    if (post > *last - 1)
    {
        printf("你选择了一个数据外的位置，请重新选择");
        return -1;
    }
    for (int i = *last; i > post; i--)
    {
        p[i] = p[i - 1];
    }
    p[post] = data;
    return (*last)++;
}