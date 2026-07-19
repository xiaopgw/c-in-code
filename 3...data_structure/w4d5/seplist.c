#include "my.h"
sp s()
{
    sp p = (sp)malloc(sizeof(ss));
    if(p == NULL)
    {
        perror("X-X");
        return NULL;
    }
    p->last = -1;
    return p;
}

void seplist_traverse(sp p)
{
    for (int i = 0; i <= p->last; i++)
    {
        printf("%d ", p->data[i]);
    }
    printf("\n");
    printf("-last-%d\n", p->last);
}

int seplist_delete(sp p, int post)
{
    if (post < 0 || post > p->last || seplist_IsEp(p))
    {
        printf("你选择了一个数据外的位置，请重新选择");//可能该数组没数据
        return -1;
    }
    for (int i = post; i < p->last; i++)
    {
        p->data[i] = p->data[i + 1];
    }
    p->data[p->last] = 0;
    return (p->last)--;
}

int seplist_insert(sp p, int post, int data)
{
    printf("-%d\n", p->last);
    if (post < 0 || post > p->last + 1 || seplist_IsFull(p))
    {
        printf("你选择了一个数据外的位置，请重新选择");
        return -1;
    }
    for (int i = p->last + 1; i > post; i--)
    {
        p->data[i] = p->data[i - 1];
    }
    p->data[post] = data;
    return (p->last)++;
}

int seplist_IsFull(sp p)
{
    return p->last == N - 1;
}
int seplist_IsEp(sp p)
{
    return p->last == -1;//可能该数组没数据
}

int seplist_ChangePost(sp p, int post, int data)
{
    if (post < 0 || post > p->last || seplist_IsFull(p) || seplist_IsEp(p))
    {
        printf("你选择了一个数据外的位置，请重新选择");//可能该数组没数据
        return -1;
    }
    p->data[post] = data;
    return p->last;
}

int seplist_searchdata(sp p, int data)
{
    for (int i = 0; i <= p->last; i++)
    {
        if (p->data[i] == data)
        {
            return i;
        }
    }
    return -1;
}
