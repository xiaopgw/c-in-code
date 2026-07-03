#include "my.h"
int main(int argc, char const *argv[])
{
    sp top;
    CreateStack(&top);
    for (int i = 0; i < 10; i++)
    {
        PushStack(&top, i + 1);
    }
    ShowStack(top);
    //chu
    printf("%d\n", PopStack(&top));
    ShowStack(top);
    // 栈长
    printf("%d\n", LongStack(top));
}
