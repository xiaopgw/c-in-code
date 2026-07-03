#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>


typedef int datatype;

typedef struct linked_list
{
    datatype ele;
    struct linked_list *poit;
}sl, *sp;

sp HeadLinkedList();
sp LinkedList(sp *tail, datatype data);
void Traverse(sp p);
sp Insert(sp head, int post, int data);
sp delete(sp head, int post);
void DestroyList(sp head);
int Length(sp p);
int InsertHead(sp head, datatype data);
int DeleteHead(sp head);
//按值寻找节点
int FindByValue(sp head, datatype data);
//按位置查找
sp FindByPos(sp head, int post);
//修改
int ChangeByPos(sp head, int post, datatype data);
//按值删除
int DeleteDataLinkList(sp head, datatype data);
//逆转
void Reverse(sp head);


#endif