#include "my.h"
sp HeadLinkedList()
{
    sp p = malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return NULL;
    }
    p->ele = 0;
    p->poit = NULL;
    return p;
}
sp LinkedList(sp *tail, datatype data)
{
    sp p = (sp)malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return NULL;
    }
    p->ele = data;
    p->poit = NULL;
    (*tail)->poit = p;
    (*tail) = p;
    return p;
}
void Traverse(sp p)
{
    while (p->poit != NULL)
    {
        p = p->poit;
        printf("%d ", p->ele);
    }
    putchar(10);
    printf("=========================\n");
}
sp Insert(sp head, int post, int data)
{

    sp tail = head;
    if(post < 0 || post > Length(head) + 1)
    {
        perror("X->");
        return NULL;
    }
    for (int i = 0; i < post; i++)
    {
        tail = tail->poit;
    }
    sp new = malloc(sizeof(sl));
    new->ele = data;
    new->poit = NULL;
    new->poit = tail->poit;
    tail->poit = new;
    return new;
}
//删除post位置的节点
sp delete(sp head, int post)
{
    //判定post是否存在链表内
    if(post < 0 || post > Length(head))
        perror("X->");
    //把位置移动到post的前一个的位置
    for (int i = 0; i < post; i++)
        head = head->poit;
    //创建一个临时指针指向要删除的节点
    //把前一个位置的指针域指到删除节点的后面一个位置
    sp p = head->poit;
    head->poit = p->poit;
    free(p);
    return p;
}
void DestroyList(sp head)
{
    while (head->poit != NULL)
    {
        sp p = head->poit;
        head->poit = p->poit;
        free(p);
    }
}
int InsertHead(sp head, datatype data)
{
    sp p = malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return -1;
    }
    p->ele = data;
    p->poit = NULL;
    p->poit = head->poit;
    head->poit = p;
    return 0;
}
int Length(sp p)
{
    int i = 0;
    while (p->poit != NULL)
    {
        p = p->poit;
        i++;
    }
    return i;
}
int DeleteHead(sp head)
{
    sp p = head->poit;
    head->poit = (head->poit)->poit;
    free(p);
}
int DelethHead2(sp head)//这个函数是错误的，只是为了比较用，我永远都不会使用这个函数，并且不需要把他放到头函数里面
{
    sp p = head;
    head->poit = (head->poit)->poit;
    free(p->poit);//这时上面的head已经把poit的指向换到第二个节点了， 此时的p的poit也是指向的第二个节点而不是我们要删的第一个节点
}
int IsEmpty(sp head)
{
    if(head->poit == NULL)
        return 0;
    return 1;
}
//按值寻找节点
// sp FindByValue(sp head, datatype data)
// {
//     //当指针域为NULL时退出循环，因为用的是有头遍历
//     while (head->poit != NULL)
//     {
//         //没找到则移动到下一个节点
//         head = head->poit;
//         //找到目标值则返回目标节点地址
//         if (head->ele == data)
//             return head;
//     }
//     return NULL;
// }
//按值寻找节点2
int FindByValue(sp head, datatype data)
{
    int post = 0;
    //当指针域为NULL时退出循环，因为用的是有头遍历
    while (head->poit != NULL)
    {
        //没找到则移动到下一个节点
        head = head->poit;
        //找到目标值则返回目标节点地址
        if (head->ele == data)
        {
            printf("按值查找函数，查找的值是%d\n", data);
            return post;
        }
        post++;
    }

    return -1;
}
//按位置查找
sp FindByPos(sp head, int post)
{
    //判断post是否存在在链表
    if (post < 0 || post > Length(head))
    return NULL;
    //循环找位置
    for (int i = 0; i <= post; i++)
    {
        head = head->poit;
    }
    printf("按位置查找函数，查找偏移%d\n", post);
    return head;
}
//修改
int ChangeByPos(sp head, int post, datatype data)
{
    //判断post是否存在在链表
    if (post < 0 || post > Length(head))
    return -1;
    //循环找位置
    for (int i = 0; i <= post; i++)
    {
        head = head->poit;
    }
    head->ele = data;
    return 0;
}
//按值删除
int DeleteDataLinkList(sp head, datatype data)
{
    //跨过头节点
    sp p = head->poit;
    while (p != NULL)
    {
        if(p->ele == data)
        {
            head->poit = p->poit;
            free(p);
            p = head->poit;
        }
        else
        {
            p = p->poit;
            head = head->poit;
        }
    }
    printf("目标删除链表里的%d\n", data);
    return 0;
}
//逆转
void Reverse(sp head)
{
    sp h = head;
    sp p = head->poit;
    sp t = NULL;
    h->poit = NULL;
    while (p != NULL)
    {
        t = p->poit;
        p->poit = h->poit;
        h->poit = p;
        p = t;
    }
}
