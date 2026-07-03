#include"my.h"
int main(int argc, char const *argv[])
{
    // sp seqstack = CreateSeqStack();
    // for (int i = 0; i < 8; i++)
    // {
    //     PushSeqStack(seqstack, i + 1);
    // }
    // // 遍历
    // ShowSeqStack(seqstack);
    // PopSeqStack(seqstack);
    // ShowSeqStack(seqstack);
    // printf("%d\n", LongSeqStack(seqstack));

    // pfr fr = CreateLinkStack();
    // for (int i = 0; i < 8; i++)
    // {
    //     PushLinkedStack(fr, i + 1);
    // }
    // ShowLinkedStack(fr);
    // // 出列
    // PopLinkStack(fr);
    // ShowLinkedStack(fr);
    // printf("%d\n", LongLinkedStack(fr));

    int post = 0, data = 64;
    // printf("1\n");
    dbpoint_p top = CreateDoubleLinkedList();
    // printf("2\n");
    // 插入
    for (int i = 0; i < 8; i++)
    {
        PushDoubleLinkedList(top, i, i + 1);
    }
    PushDoubleLinkedList(top, 4, data);
    PushDoubleLinkedList(top, 8, data);
    // 遍历
    ShowDoubleLinkedList(top);
    DeleteBoubleLinkedList(top, 4);
    ShowDoubleLinkedList(top);
    return 0;
}
