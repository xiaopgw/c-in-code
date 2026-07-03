#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>

#define N 8

typedef int datatype;
// 循环数组
// 创建数组结构体
typedef struct sequentailqueue
{
    datatype *data;
    int maxlen;
    int front;
    int rear;
} seqeue_t, *sequeue_p;

// 创空
sequeue_p CreateQueue();
// 判满
int FullQueue(sequeue_p queue);
// 入队列
int PushQueue(sequeue_p queue, datatype data);
// 判空
int EmptyQueue(sequeue_p queue);
// 出队列
int DeleteQueue(sequeue_p queue);
// 遍历
void ShowQueue(sequeue_p queue);

#endif