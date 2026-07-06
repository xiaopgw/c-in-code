#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

//1.创建一个空的队列
linkqueue_t *createEmptyLinkQueue()
{
	linkqueue_t *p = (linkqueue_t *)malloc(sizeof(linkqueue_t));
	if(NULL == p)
	{
		perror("createEmptyLinkQueue p malloc failed");
		return NULL;
	}//申请空间就是为了装东西
	//申请链表的头节点空间，让rear和front都指向头结点
	p->front = p->rear = (linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
	if(NULL == p->rear)
	{
		perror("p->rear malloc failed");
		return NULL;
	}
	p->rear->next = NULL;//或者用p->front->next = NULL;因为p->rear 和 p->front 指向同一个位置即头节点
	return p;
}
//2.入列 data代表入列的数据
int inLinkQueue(linkqueue_t *p,datatype_linkqueue data)
{
	//1.创建一个新的节点，用来保存即将插入的数据
	linkqueue_list_t pnew = (linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
	if(NULL == pnew)
	{
		perror("inLinkQueue pnew malloc failed");
		return -1;
	}
	//2.将入列的数据放入到新的节点中
	pnew->data = data;
	pnew->next = NULL;
	//3.将新节点链链接到链表的尾巴
	p->rear->next = pnew;//新节点链接到链表的尾
	p->rear = pnew;//rear移动，因为rear永远指向当前链表的尾
	return 0;
}
//3.出列 
datatype_linkqueue outLinkQueue(linkqueue_t *p)
{
	linkqueue_list_t pdel = NULL;//指向被删除的节点
	//1.容错判断
	if(isEmptyLinkQueue(p))
	{
		printf("isEmptyLinkQueue !!\n");
		return NULL;
	}
	//2.出列数据
	//(1)定义pdel指向即将被删除的节点就是front指向的节点，出列每次删除的都是front指向的那个节点
	pdel = p->front;
	//(2)将front向后移动一个位置
	p->front = p->front->next;
	//(3)释放被删除节点
	free(pdel);
	pdel = NULL;
	//(4)将数据出列
	return p->front->data;
}
//4.判断队列是否为空
int isEmptyLinkQueue(linkqueue_t *p)
{
	return p->front == p->rear;
}
//5.求队列长度的函数
int lengthLinkQueue(linkqueue_t *p)
{
	int len = 0;
	linkqueue_list_t h = p->front;//将链表的头指针保存的地址给h,如果直接用front，求长度之后会找不到链表的头，用h的移动代替front的移动
	//求长度，相当于遍历有头的单向链表
	while(h->next != NULL)
	{
		h = h->next;
		len++;
	}
	return len;
}
//6.清空队列
void clearLinkQueue(linkqueue_t *p)
{
	while(!isEmptyLinkQueue(p))//只要不为空，就出列
		outLinkQueue(p);
}
