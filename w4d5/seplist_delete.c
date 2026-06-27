#include "my.h"
int seplist_delete(int *p, int *last, int post)
{
    if (post > *last - 1)
    {
        printf("你选择了一个数据外的位置，请重新选择");
        return -1;
    }
    for (int i = post; i < *last - 1; i++)
    {
        p[i] = p[i + 1];
    }
    p[*last - 1] = 0;
    return (*last)--;
}