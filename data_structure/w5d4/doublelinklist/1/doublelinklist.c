#include"my.h"
// 创空有头链表
dboffset_p CreateLinklist()
{
    // 创空指针，
    dboffset_p link = malloc(sizeof(dboffset_t));
    if (link == NULL)
    {
        perror("X->");
        return NULL;
    }
    link->len = 0;
    //指向双向链表头
    link->front = link->rear = malloc(sizeof(dbqueue_t));
    if (link->front == NULL)
    {
        perror("X->");
        return NULL;
    }
    return link;
}
// 狠狠的插入
int PushLinkList(dboffset_p link, int post, datatype data)
{
    if (post < 0 || post > link->len)
    {
        printf("X\n");
        return -1;
    }
    
    // 创建节点
    dbqueue_p pnew = malloc(sizeof(dbqueue_t));
    if (pnew == NULL)
    {
        perror("X->");
        return -1;
    }
    // 初始化节点
    pnew->data = data;
    // 判断post是否在结尾
    if (post == link->len)
    {
        // 把尾节点的后指针指向新节点
        link->rear->next = pnew;
        // 新节点的前指针指向尾节点
        pnew->prev = link->rear;
        // 尾指针指向新节点
        link->rear = pnew;
        // 新节点后指针指向空
        pnew->next = NULL;
        // len++
        link->len++;
        // printf("-w-");
        return 0;
    }
    
    // 判断post是在前半段还是后半段
    if (post <= link->len / 2)
    {
        // 前半段
        // 遍历到post
        dbqueue_p head = link->front;
        for (int i = 0; i <= post; i++)
        {
            head = head->next;
        }
        // 在post节点把新节点的前指针指向post节点前
        pnew->prev = head->prev;
        // post前节点的后指针指向post
        head->prev->next = pnew;
        // 新节点后指针指向post节点
        pnew->next = head;
        // post前指针指向新节点
        head->prev = pnew;
        // printf("-f-");
    }
    else
    {
        // 后半段遍历到post
        dbqueue_p head = link->rear;
        for (int i = link->len - 1; i > post; i--)
        {
            head = head->prev;
        }
        // 在post节点把新节点的前指针指向post节点前
        pnew->prev = head->prev;
        // post前节点的后指针指向post
        head->prev->next = pnew;
        // 新节点后指针指向post节点
        pnew->next = head;
        // post前指针指向新节点
        head->prev = pnew;
        // printf("-r-");
    }
    link->len++;
    // 判断完后len++
    return 0;
}
// 遍历
void ShowDoubleLinkList(dboffset_p link)
{
    dbqueue_p head = link->front;
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    }
    putchar(10);
}
// 狠狠的抽出
int PopLinkList(dboffset_p link, int post)
{
    if (post < 0 || post >= link->len)
    {
        printf("X\n");
        return -1;
    }
    // 判断post是否在结尾
    if (post == link->len - 1)
    {
        dbqueue_p tail = link->rear;
        link->rear = tail->prev;
        link->rear->next = NULL;
        link->len--;
        free(tail);
        return 0;
    }
    // 判断post是在前半段还是后半段
    if (post <= link->len / 2)
    {
        // 前半段
        // 遍历到post
        dbqueue_p head = link->front;
        for (int i = 0; i <= post; i++)
        {
            head = head->next;
        }
        head->next->prev = head->prev;
        head->prev->next = head->next;
        free(head);
    }
    else
    {
        // 后半段遍历到post
        dbqueue_p head = link->rear;
        for (int i = link->len - 1; i > post; i--)
        {
            head = head->prev;
        }
        head->next->prev = head->prev;
        head->prev->next = head->next;
        free(head);
    }
    link->len--;
    // 判断完后len++
    return 0;
}