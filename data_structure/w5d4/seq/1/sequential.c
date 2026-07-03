#include"my.h"
// 创空
sequeue_p CreateQueue()
{
    // 创建数组
    sequeue_p queue = malloc(sizeof(seqeue_t));
    if (queue == NULL)
    {
        perror("X->");
        return NULL;
    }
    
    // 初始化
    queue->data = malloc(sizeof(datatype) * N);
    if (queue->data == NULL)
    {
        perror("X->");
        return NULL;
    }
    queue->maxlen = N;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}
// 判满
int FullQueue(sequeue_p queue)
{
    // 尾加一后取余等于头
    return (queue->rear + 1) % N == queue->front;
}
// 入队列
int PushQueue(sequeue_p queue, datatype data)
{
    // 这是一个循环队列数组
    // 判满
    if (FullQueue(queue))
    {
        printf("X\n");
        return -1;
    }
    // 插入数据
    queue->data[queue->rear] = data;
    // 尾移动
    queue->rear = (queue->rear + 1) % N;
    return data;
}
// 判空
int EmptyQueue(sequeue_p queue)
{
    return queue->front == queue->rear;
}
// 出队列
int DeleteQueue(sequeue_p queue)
{
    // 判空
    if (EmptyQueue(queue))
    {
        printf("X\n");
        return -1;
    }
    // 从头移出数据
    queue->data[queue->front] = 0;
    // 头移动
    queue->front = (queue->front + 1) % N;
}
// 遍历
void ShowQueue(sequeue_p queue)
{
    for (int i = queue->front; i < queue->rear; i = (i + 1) % N)
    {
        printf("%d ", queue->data[i]);
    }
}