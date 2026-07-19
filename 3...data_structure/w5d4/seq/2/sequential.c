#include"my.h"
// 遍历
void ShowQueue(sequeue_p queue)
{
    for (int i = queue->front; i < queue->rear; i = (i + 1) % N)
    {
        printf("%d ", queue->data[i]);
    }
}
// 判满
int FullQueue(sequeue_p queue)
{
    // 尾加一后取余等于头
    return (queue->rear + 1) % N == queue->front;
}
// 判空
int EmptyQueue(sequeue_p queue)
{
    return queue->front == queue->rear;
}

// 创空
sequeue_p CreateQueue()
{
    sequeue_p queue = malloc(sizeof(seqeue_t));
    queue->data = malloc(sizeof(datatype) * N);
    queue->maxlen = N;
    return queue;
}

// 入队列
int PushQueue(sequeue_p queue, datatype data)
{
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % N;
}

// 出队列
int DeleteQueue(sequeue_p queue)
{
    queue->front = (queue->front + 1) % N;
}
