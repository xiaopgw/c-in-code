#include "my.h"
int main(int argc, char const *argv[])
{
    datatype val = 0;
    // 进栈
    sp stack = CreateEmptySeqStack(8);
    for (int i = 0; i < 7; i++)
    {
        PushStack(stack, i + 1);
    }
    ShowSepStack(stack);
    // 出栈
    printf("读取出栈的数为%d\n", PopStack(stack));
    printf("读取栈的数为%d\n", TopStack(stack));
    RealShowSepStack(stack);
    printf("计算的数据长度是%d\n", LongSepStack(stack));
    //释放空间
    DestroySeqStack(stack);
}
