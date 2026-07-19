#include"my.h"
// 遍历
void ShowQueue(linkoffset_p queue)
{
    // 有头遍历
    linkqueue_p head = queue->front;
    while(head->next != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    }
    putchar(10);
}
// 创建空有头链表
linkoffset_p CreateQueue()
{
    linkoffset_p queue = malloc(sizeof(linkoffset_t));
    queue->front = queue->rear = malloc(sizeof(linkqueue_t));
    queue->front->next = NULL;
    return queue;
}
// 入队列
int PushQueue(linkoffset_p queue, datatype data)
{
    linkqueue_p tail = malloc(sizeof(linkqueue_t));
    tail->next = NULL;
    tail->data = data;
    queue->rear->next = tail;
    queue->rear = tail;
}
// 判空
int EmptyQueue(linkoffset_p queue)
{
    // 头尾指向同一个节点
    return queue->front == queue->rear;
}
// 出队列
int PopQueue(linkoffset_p queue)
{
    linkqueue_p head = queue->front;
    queue->front = queue->front->next;
    free(head);
    
}
