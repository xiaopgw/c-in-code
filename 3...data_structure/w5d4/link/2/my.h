#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;
// 创建节点结构体
typedef struct linklistqueue
{
    datatype data;
    struct linklistqueue *next;
}linkqueue_t, *linkqueue_p;
// 创建指头指针和指尾指针结构体
typedef struct linklistoffset
{
    linkqueue_p front;
    linkqueue_p rear;
}linkoffset_t, *linkoffset_p;
 
// 创建空有头链表
linkoffset_p CreateQueue();
// 入队列
int PushQueue(linkoffset_p queue, datatype data);
// 判空
int EmptyQueue(linkoffset_p queue);
// 出队列
int PopQueue(linkoffset_p queue);
// 遍历
void ShowQueue(linkoffset_p queue);
#endif