#include"my.h"
// 初始化顶部指针
void CreateStack(sp *top)
{
    *top = NULL;
}
// 入栈
int PushStack(sp *top, datatype data)
{
    // 为新的数据开空间
    sp p = malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return -1;
    }
    p->data = data;
    // 把新的节点放到链表第一位（指向top的内容）
    p->poit = *top;
    // top指向新节点让链表链起来
    *top = p;
    return p->data;
}
// 遍历
void ShowStack(sp top)
{
    // 无头遍历
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->poit;
    }
    printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
}
// 判空
int NullStack(sp top)
{
    return top == NULL;
}
// 出栈
int PopStack(sp *top)
{
    // 判空
    if (NullStack(*top))
    {
        printf("X\n");
        return -1;
    }
    // top链接节点2
    sp l = *top;
    datatype data = l->data;
    *top = (*top)->poit;
    //free节点1
    free(l);
    return data;
}
// 栈长
int LongStack(sp top)
{
    int len = 0;
    // 无头遍历
    while (top != NULL)
    {
        len++;
        top = top->poit;
    }
    return len;
}