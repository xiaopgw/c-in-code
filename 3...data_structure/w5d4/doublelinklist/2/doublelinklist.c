#include"my.h"
// 创空有头链表
dboffset_p CreateLinklist()
{
    dboffset_p link = malloc(sizeof(dboffset_t));
    link->front = link->rear = malloc(sizeof(dbqueue_t));
    link->front->next = NULL;
    link->front->prev = NULL;
    link->len = 0;
}
// 狠狠的插入
int PushLinkList(dboffset_p link, int post, datatype data)
{
    dbqueue_p p = malloc(sizeof(dbqueue_t));
    p->data = data;

    if(post == link->len)
    {
        p->next = NULL;
        p->prev = link->rear;
        link->rear->next = p;
        link->rear = p;
        link->len++;
        printf("-w-");
        return -1;
        
    }
    if (post <= link->len / 2)
    {
        dbqueue_p q = link->front;
        for (int i = 0; i <= post; i++)
        {
            q = q->next;
        }
        p->prev = q->prev;
        p->next = q;
        q->prev->next = p;
        q->prev = p;
        printf("-f-");
    }
    else
    {
        dbqueue_p q = link->rear;
        for (int i = link->len - 1; i > post; i--)
        {
            q = q->prev;
        }
        p->prev = q->prev;
        p->next = q;
        q->prev->next = p;
        q->prev = p;
    }
    link->len++;
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