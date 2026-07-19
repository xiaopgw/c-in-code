#include"my.h"

//创建空的顺序栈
sp CreateEmptySeqStack(int len)
{
    sp p = malloc(sizeof(ss));
    if (p == NULL)
    {
        perror("X->");
        return NULL;
    }
    p->maxlen = len;
    p->data = malloc(sizeof(datatype) * p->maxlen);
    p->top = -1;
    return p;
}
// 判满
int FullSepStack(sp p)
{
    return p->top >= p->maxlen - 1;
}
// 判空
int NullSepStack(sp p)
{
    return p->top == -1;
}
// 入栈
int PushStack(sp p, datatype data)
{
    if (FullSepStack(p))
    {
        printf("X");
        return -1;
    }
    (p->top)++;
    p->data[p->top] = data;
    return 0;
}
// 出栈, 改变长度
int PopStack(sp p)
{
    if (NullSepStack(p))
    {
        printf("X");
        return -1;
    }
    (p->top)--;
    return p->data[p->top + 1];
}
// 读取栈，不改变长度
int TopStack(sp p)
{
    if (NullSepStack(p))
    {
        printf("X");
        return -1;
    }
    return p->data[p->top];
}
// 再开
// int AddStack(sp p)
// {
//     sp p = malloc;
// }
// 遍历
void ShowSepStack(sp p)
{
    for (int i = 0; i < p->maxlen; i++)
    {
        printf("%d ", p->data[i]);
    }
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}
// 真实数据遍历
void RealShowSepStack(sp p)
{
    int len = 0;
    for (int i = 0; i <= p->top; i++)
    {
        len++;
        printf("%d ", p->data[i]);
    }
    
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}
// 计算数据长度
int LongSepStack(sp p)
{
    return p->top + 1;
}
// 释放所有空间
void DestroySeqStack(sp p)
{
    free(p->data);
    free(p);
}