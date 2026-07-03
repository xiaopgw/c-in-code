#include"my.h"
// 创建一个空的数组存顺序栈
sp CreatSequeStack()
{
    // 创建结构体的空间
    sp p = malloc(sizeof(ss));
    if (p == NULL)
    {
        perror("X->");
        return NULL;
    }
    // 开数组的空间
    p->data = malloc(sizeof(datatype) * 8);
    // 初始化数组
    p->all = 8;
    p->top = -1;
    // 返回结构体地址
    return p;
}
// 满
int FullStack(sp p)
{
    return p->top >= p->all - 1;
}
// 入栈
int PushStack(sp p, datatype data)
{
    //判满
    if (FullStack(p))
    {
        printf("X");
        return -1;
    }
    // top上移
    (p->top)++;
    printf("Top-%d-\n", p->top);
    //录入数据
    p->data[p->top] = data;
    
    // 返回顶部数据
    return p->data[p->top];
}
// 全部遍历
void ShowStack(sp p)
{
    for (int i = 0; i < p->all; i++)
    {
        printf("%d ", p->data[i]);
    }
    printf("\n'''''''''''''''''''''''''''''''\n");
}
// 判空
int NullStack(sp p)
{
    return p->top == -1;
}
// 出栈
int PopStack(sp p)
{
    // 判空
    if (NullStack(p))
    {
        printf("X");
        return -1;
    }

    // 存储数据
    datatype num = p->data[p->top];
    // 释放空间
    p->data[p->top] = 0;
    // top下移
    (p->top)--;
    // 返回顶部数据
    return num;
}
// 求长度
int LengStack(sp p)
{
    return p->top + 1;
}