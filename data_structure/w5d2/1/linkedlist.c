#include "my.h"
// 创建头节点
sp LinkedListHead()
{
    // 开辟头节点(malloc会返回NULL所以不用预初始化)
    sp p = malloc(sizeof(sl));
    // 判断开辟是否成功
    if (p == NULL)
    {
        perror("X->");
        return NULL;
    }
    // 初始化头节点
    p->poit = NULL;
    return p;
}
// 遍历链表
void ShowLinkList(sp p)
{
    //有头链表遍历
    while (p->poit != NULL)
    {
        p = p->poit;
        printf("%d ", p->data);
    }
    putchar(10);
    printf("++++++++++++++++++++++++++++++++\n");
}
// 计算链表长度(这里不包括头节点)
int LengthLinkList(sp p)
{
    int i = 0;
    //有头链表遍历，遍历一遍加一
    while (p->poit != NULL)
    {
        p = p->poit;
        i++;
    }
    return i;
}
// 清空链表
void CleanLinkList(sp head)
{
    //跳过头链表清空链表
    //判断链表现在是否指着null
    //当删除一个节点时需要有个亚节点，存当前节点，把他删除
    //在删除前需要把前一个节点连接到要删除的节点后面的节点
    while (head->poit != NULL)
    {
        sp p = head->poit;
        head->poit = p->poit;
        free(p);
    }
}
// 在指定位置插入函数
sp InsertLinkList(sp head, int post, datatype data)
{
    for (int i = 0; i < post; i++)
    {
        head = head->poit;
    }
    sp p = malloc(sizeof(sl));
    p->data = data;
    p->poit = head->poit;
    head->poit = p;
    return p;
}
// 头插尾插（这么爽的吗）
int InsertLinkListHead_Tail(sp head, datatype data)
{
    sp p = malloc(sizeof(sl));
    p->data = data;
    p->poit = head->poit;
    head->poit = p;
    while (head->poit != NULL)
    {
        head = head->poit;
    }
    p = malloc(sizeof(sl));
    p->data = data;
    p->poit = NULL;
    head->poit = p;
}
//删除指定偏移量的位置
int DeleteLinkListPost(sp head, int post)
{
    for (int i = 0; i < post; i++)
    {
        head = head->poit;
    }
    sp p = head->poit;
    head->poit = p->poit;
    free(p);
    return 0;
}
// 删除指定所有元素
int DeleteLinkList(sp head, datatype data)
{
    sp p = head;
    while (p->poit != NULL)
    {
        if (p->poit->data == data)
        {
            sp q = p->poit;
            p->poit = q->poit;
            free(q);
        }
        else
        p = p->poit;
    }
    return -1;
}
// 修改指定偏移量位置的元素
sp ChangeLinklistData(sp head, int post, datatype data)
{
    for (int i = 0; i <= post; i++)
    {
        head = head->poit;
    }
    head->data = data;
    return head;
}
// 查找指定元素的位置
int SearchLinkListData(sp head, datatype data)
{
    int i = 0;
    while (head->poit != NULL)
    {
        head = head->poit;
        if (head->data == data)
        {
            return i;
        }
        i++;
    }
}
// 指定位置查元素
datatype SearchLinkListPost(sp head, int post)
{
    for (int i = 0; i <= post; i++)
    {
        head = head->poit;
    }
    return head->data;
}
// 转置链表
void ReverseLinkList(sp head)
{
    sp zhong = head->poit;
    sp tou = head;
    tou->poit = NULL;
    while (zhong != NULL)
    {
        sp wei = zhong->poit;
        zhong->poit = tou->poit;
        tou->poit = zhong;
        zhong = wei;
    }
}
// 旧改
//按值删除
int DeleteDataLinkList(sp head, datatype data)
{
    sp p = head->poit;
    while (p->poit != NULL)
    {
        if(p->data == data)
        {
            head->poit = p->poit;
            free(p);
            p = head->poit;
        }
        else
        {
            head = head->poit;
            p = head->poit;
        }
    }
    printf("目标删除链表里的%d\n", data);
    return 0;
}
// 我又写了一个新的，主要是他删不掉最后一个节点，
// 或者一到最后一个节点就会崩，我无所谓链表入口的丢失