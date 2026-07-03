#include "my.h"
int main(int argc, char const *argv[])
{
    sp top;
    datatype data;
    CreateEmptyLinkStack(&top);
    for (int i = 0; i < 10; i++)
    {
        PushStack(&top, i + 1);
    }
    ShowStack(top);
    PopStack(&top);
    ShowStack(top);
    // 求长度
    printf("长度%d\n", LengStack(top));
    // 清空
    DeleteStack(&top);
    ShowStack(top);

}
