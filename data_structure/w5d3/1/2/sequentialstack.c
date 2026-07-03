#include"my.h"

// 全部遍历
void ShowStack(sp p)
{
    for (int i = 0; i < p->all; i++)
    {
        printf("%d ", p->data[i]);
    }
    printf("\n'''''''''''''''''''''''''''''''\n");
}
// 创建一个空的数组存顺序栈
sp CreatSequeStack()
{
    sp p = malloc(sizeof(ss));
    p->data = malloc(sizeof(datatype) * 8);
    p->all = 8;
    p->top = -1;
    return p;
}
// 入栈
int PushStack(sp p, datatype data)
{
    p->top++;
    p->data[p->top] = data;
    return 0;
}
// 出栈
int PopStack(sp p)
{
    (p->top)--;
    return 0;
}
// 求长度
int LengStack(sp p)
{
    return p->top + 1;
}