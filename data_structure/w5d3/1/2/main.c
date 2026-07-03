#include "my.h"
int main(int argc, char const *argv[])
{
    // 创建一个空的数组存顺序栈
    sp stack = CreatSequeStack();
    // 入栈
    for (int i = 0; i < 7; i++)
    {
        PushStack(stack, i + 1);
    }
    printf("最后的数据%d\n", PushStack(stack, 8));
    ShowStack(stack);
    // 出栈
    printf("删除的数据%d\n", PopStack(stack));
    ShowStack(stack);
    // 求长度
    printf("长度%d\n", LengStack(stack));
}
