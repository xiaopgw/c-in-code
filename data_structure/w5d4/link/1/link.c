#include"my.h"
// 创建空有头链表
linkoffset_p CreateQueue()
{
    // 创建指针指向链表头
    linkoffset_p queue = malloc(sizeof(linkoffset_t));
    if (queue == NULL)
    {
        perror("X->");
        return NULL;
    }
    queue->front = queue->rear = malloc(sizeof(linkqueue_t));
    if (queue->front == NULL)
    {
        perror("X->");
        return NULL;
    }
    // 初始化
    queue->front->data = -64;
    queue->front->next = NULL;
    return queue;
}
// 入队列
int PushQueue(linkoffset_p queue, datatype data)
{
    // 链表尾插
    // 开节点
    linkqueue_p pnew = malloc(sizeof(linkqueue_t));
    if (pnew == NULL)
    {
        perror("X->");
        return -1;
    }
    pnew->data = data;
    // 节点插入尾，尾指向新节点，新节点指向N
    queue->rear->next = pnew;
    queue->rear = pnew;
    pnew->next = NULL;
    return 0;
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
    if (EmptyQueue(queue))
    {
        printf("X\n");
        return -1;
    }
    
    // 存头
    linkqueue_p head = queue->front;
    // 把第一个节点变为头
    queue->front = queue->front->next;
    free(head);
    return 0;
}
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