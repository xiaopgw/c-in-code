#include "my.h"
int main(int argc, char const *argv[])
{
    sp head =  HeadLinkedList();
    sp tail = head;
    datatype i = 9;
    while (i >= 0)
    {
        sp q = LinkedList(&tail, i);
        i--;
    }
    Traverse(head);
    int post = 2, data = 64;
    Insert(head, post, data);
    Traverse(head);
    delete(head, post);
    Traverse(head);
    DestroyList(head);
    Traverse(head);
    head =  HeadLinkedList();
    tail = head;
    i = 9;
    while (i >= 0){sp q = LinkedList(&tail, i);i--;}
    Traverse(head);
    InsertHead(head, data);
    Traverse(head);
    DeleteHead(head);
    Traverse(head);
    int findbyvalue = FindByValue(head, 5);
    //按值查找
    if(findbyvalue != -1)
        printf("查找到的偏移是%d\n", findbyvalue);
    //按位置查找
    sp findbypos = FindByPos(head, 0);
    if (findbypos != NULL)
        printf("查找到的数是%d\n", findbypos->ele);
    //修改
    if (ChangeByPos(head, post, data) == -1)
        printf("errer\n");
    if (ChangeByPos(head, 7, data) == -1)
        printf("errer\n");
    if (ChangeByPos(head, 9, data) == -1)
        printf("errer\n");
    Traverse(head);
    //按值删除
    DeleteDataLinkList(head, data);
    Traverse(head);
    Reverse(head);
    Traverse(head);

}
