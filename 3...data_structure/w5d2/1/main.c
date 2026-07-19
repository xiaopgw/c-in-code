#include "my.h"
int main(int argc, char const *argv[])
{
    sp head = LinkedListHead();
    sp tail = head;
    int post = 2;
    datatype data = 64;
    for (int i = 0; i < 10; i++)
    {
        InsertLinkList(head, i, i + 1);
    }
    ShowLinkList(head);

    //清空链表
    CleanLinkList(head);
    //计算链表长度
    printf("这里计算了一遍链表长度，一共%d个元素\n", LengthLinkList(head));
    for (int i = 0; i < 10; i++)
    {
        InsertLinkList(head, i, i + 1);
    }
    // 头插尾插
    InsertLinkListHead_Tail(head, data);
    ShowLinkList(head);
    // 删除目标相同元素
    DeleteLinkList(head, data);
    ShowLinkList(head);
    //删除指定偏移量的位置
    DeleteLinkListPost(head, post);
    ShowLinkList(head);
    // 修改指定偏移量位置的元素
    ChangeLinklistData(head, post, data);
    ShowLinkList(head);

    // 查找指定元素位置
    printf("位置在%d\n", SearchLinkListData(head, data));
    // // 指定位置查元素
    printf("元素是%d\n", SearchLinkListPost(head, post));
    // 转置链表
    ReverseLinkList(head);
    ShowLinkList(head);
}
