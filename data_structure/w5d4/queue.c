#include "my.h"
// sp CreateSeqStack()
// {
//     sp p = malloc(sizeof(ss));
//     if (p == NULL)
//     {
//         perror("X\n");
//         return NULL;
//     }
//     p->data = malloc(sizeof(datatype) * N);
//     p->maxlen = N;
//     p->front = 0;
//     p->rear = 0;
//     return p;
// }
// // 判满
// int FullSeqStack(sp p)
// {
//     return (p->rear + 1) % N == p->front;
// }
// // 入列
// int PushSeqStack(sp p, datatype data)
// {
//     if (FullSeqStack(p))
//     {
//         printf("X\n");
//         return -1;
//     }
//     p->data[p->rear] = data;
//     datatype l = p->data[p->rear];
//     p->rear = (p->rear + 1) % N;
//     return l;
// }
// // 遍历
// int ShowSeqStack(sp p)
// {
//     for (int i = p->front; i != p->rear; i = (i + 1) % N)
//     {
//         printf("%d ", p->data[i]);
//     }
//     printf("\n---------------------------\n");
// }
// // 判空
// int NullSepStack(sp p)
// {
//     return p->rear == p->front;
// }
// // 出列
// int PopSeqStack(sp p)
// {
//     if (NullSepStack(p))
//     {
//         printf("X\n");
//         return -1;
//     }
//     p->front = ((p->front) + 1) % N;
//     return 0;
// }
// // 队列长度
// int LongSeqStack(sp p)
// {
//     int len = 0;
//     for (int i = p->front; i != p->rear; i = (i + 1) % N)
//     {
//         len++;
//     }
//     return len;
// }

// // 创空
// pfr CreateLinkStack()
// {
//     sq head = malloc(sizeof(sl));
//     if (head == NULL)
//     {
//         perror("X\n");
//         return NULL;
//     }
//     head->next = NULL;
//     head->data = 0;
//     pfr fr = malloc(sizeof(sfr));
//     if (fr == NULL)
//     {
//         perror("X\n");
//         return NULL;
//     }
//     fr->front = fr->rear = head;
//     return fr;
// }
// // 入列
// sq PushLinkedStack(pfr fr, datatype data)
// {
//     sq top = malloc(sizeof(sl));
//     if (top == NULL)
//     {
//         perror("X\n");
//         return NULL;
//     }
//     top->data = data;
//     top->next = fr->rear->next;
//     fr->rear->next = top;
//     fr->rear = top;
//     return top;
// }
// // 遍历
// void ShowLinkedStack(pfr fr)
// {
//     sq head = fr->front;
//     while (head->next != NULL)
//     {
//         head = head->next;
//         printf("%d ", head->data);
//     }
//     printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
// }
// // 判空
// int NullLinkStack(pfr fr)
// {
//     return fr->front == fr->rear;
// }
// // 出列
// int PopLinkStack(pfr fr)
// {
//     if (NullLinkStack(fr))
//     {
//         printf("X\n");
//         return -1;
//     }
//     sq l = fr->front;
//     fr->front = l->next;
//     free(l);
//     return fr->front->data;
// }
// // 计算长度
// int LongLinkedStack(pfr fr)
// {
//     sq head = fr->front;
//     int i = 0;
//     while (head->next != NULL)
//     {
//         head = head->next;
//         i++;
//     }
//     return i;
// }

// 创空
dbpoint_p CreateDoubleLinkedList()
{
    dbpoint_p p = malloc(sizeof(dbpoint_t));
    p->head = p->tail = malloc(sizeof(dbnode_t));
    p->len = 0;
    p->head->next = NULL;
    p->head->prev = NULL;
    return p;
}
// 插入
int PushDoubleLinkedList(dbpoint_p top, int post, datatype data)
{
    if (post < 0 || post > top->len)
    {
        printf("X");
        return -1;
    }
    
    dbnode_p pnew = malloc(sizeof(dbnode_t));
    pnew->data = data;
    if (post == top->len)
    {
        top->tail->next = pnew;
        pnew->next = NULL;
        pnew->prev = top->tail;
        top->tail = pnew;
        top->len++;
        // printf("-w-\n");
        return 0;
    }
    if (post <= top->len / 2)
    {
        dbnode_p ppost = top->head;
        for (int i = 0; i <= post; i++)
        {
            ppost = ppost->next;
        }
        ppost->prev->next = pnew;
        pnew->prev = ppost->prev;
        pnew->next = ppost;
        ppost->prev = pnew;
        // printf("-z-\n");
    }
    else
    {
        dbnode_p qpost = top->tail;
        for (int i = top->len - 1; i > post; i--)
        {
            qpost = qpost->prev;
        }
        qpost->prev->next = pnew;
        pnew->prev = qpost->prev;
        pnew->next = qpost;
        qpost->prev = pnew;
        // printf("-f-\n");
    }
    top->len++;
}
// 遍历
void ShowDoubleLinkedList(dbpoint_p top)
{
    dbnode_p head = top->head;
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
        
    }
    printf("\n-------------------------------\n");
}
// 删除
int DeleteBoubleLinkedList(dbpoint_p top, int post)
{
    // 尾删，前删，后删
    if (post < 0 || post > top->len)
    {
        printf("X");
        return -1;
    }
    if (post == top->len)
    {
        dbnode_p tail = top->tail;
        top->tail = tail->prev;
        top->tail->next = NULL;
        free(tail);
        // printf("-w-\n");
        return 0;
    }
    if (post <= post / 2)
    {
        dbnode_p ppost = top->head;
        for (int i = 0; i <= post; i++)
        {
            ppost = ppost->next;
        }
        ppost->prev->next = ppost->next;
        ppost->next->prev = ppost->prev;
        free(ppost);
        // printf("-z-\n");
    }
    else
    {
        dbnode_p ppost = top->head;
        for (int i = top->len - 1; i > post; i--)
        {
            ppost = ppost->next;
        }
        ppost->prev->next = ppost->next;
        ppost->next->prev = ppost->prev;
        free(ppost);
        // printf("-f-p\n");
    }
    top->len--;
    return 0;
}