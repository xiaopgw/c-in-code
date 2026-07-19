#include"my.h"
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
// 初始化顶部指针
void CreateStack(sp *top)
{
    *top = NULL;
}
// 入栈
int PushStack(sp *top, datatype data)
{
    sp p = malloc(sizeof(sl));
    p->data = data;
    p->poit = *top;
    *top = p;
}

// 出栈
int PopStack(sp *top)
{
    sp p = *top;
    *top = (*top)->poit;
    free(p);
}
// 栈长
int LongStack(sp top)
{
    int i = 0;
    while (top != NULL)
    {
        i++;
        top = top->poit;
    }
    return i;
}