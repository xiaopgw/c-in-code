#include"my.h"
// 创建空节点
// sp CreateEmptyStack()
// {
//     sp head = malloc(sizeof(sl));
//     if (head == NULL)
//     {
//         perror("X->");
//         return NULL;
//     }
//     head = NULL;
//     return head;
// }
// 用指针创建空节点

void CreateEmptyLinkStack(sp *p)
{
    *p = NULL;
}
// 头插
datatype PushStack(sl **top, datatype data)
{
    sp p = malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return -1;
    }
    p->data = data;
    p->poit = *top;
    *top = p;
    return 0;
}
// 遍历
int ShowStack(sp p)
{
    while (p != NULL)
    {
        printf("%d ", (p)->data);
        p = (p)->poit;
    }
    putchar(10);
}
// 出栈
datatype PopStack(sp *top)
{
    if (&top == NULL)
    {
        printf("X");
        return -1;
    }
    sp p = *top;
    datatype l = p->data;
    *top = (*top)->poit;
    free(p);
    return 0;
}
// 清空
void DeleteStack(sp *top)
{
    while (*top != NULL)
    {
        sp p = *top;
        *top = p->poit;
        free(p);
    }
}
// 求长度
int LengStack(sl *top)
{
    int len = 0;
    while (top != NULL)
    {
        top = (top)->poit;
        len++;
    }
    return len;
}
