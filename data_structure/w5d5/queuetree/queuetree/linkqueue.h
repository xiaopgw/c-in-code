#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include "bitree.h"

//将 bitree_t * 改名 为datatype_linkqueue 
typedef bitree_t * datatype_linkqueue;//把队列的数据域变成指向树节点的指针
typedef struct node
{
	datatype_linkqueue data;//数据域
	struct node *next;//指针域
}linkqueue_node_t,*linkqueue_list_t;

//linkqueue_list_t p === linkqueue_node_t *
typedef struct//将队列头指针和尾指针封装到一个结构体里
{
	linkqueue_list_t front;//相当于队列的头指针
	linkqueue_list_t rear;//相当于队列的尾指针
	//有了链表的头指针和尾指针，那么我们就可以操作这个链表
}linkqueue_t;

//1.创建一个空的队列
linkqueue_t *createEmptyLinkQueue();
//2.入列 data代表入列的数据
int inLinkQueue(linkqueue_t *p,datatype_linkqueue data);
//3.出列 
datatype_linkqueue outLinkQueue(linkqueue_t *p);
//4.判断队列是否为空
int isEmptyLinkQueue(linkqueue_t *p);
//5.求队列长度的函数
int lengthLinkQueue(linkqueue_t *p);
//6.清空队列
void clearLinkQueue(linkqueue_t *p);

#endif
