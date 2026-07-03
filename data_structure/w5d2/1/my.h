#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;
typedef struct linkedlist
{
    datatype data;
    struct linkedlist *poit;
}sl, *sp;

// 创建头节点
sp LinkedListHead();
// 在指定位置插入函数
sp InsertLinkList(sp head, int post, datatype data);
// 遍历链表
void ShowLinkList(sp p);
// 计算链表长度(这里不包括头节点)
int LengthLinkList(sp p);
// 清空链表
void CleanLinkList(sp head);
// 头插尾插（这么爽的吗）
int InsertLinkListHead_Tail(sp head, datatype data);
//删除指定偏移量的位置
int DeleteLinkListPost(sp head, int post);
// 删除指定所有元素
int DeleteLinkList(sp head, datatype data);
// 修改指定偏移量位置的元素
sp ChangeLinklistData(sp head, int post, datatype data);
// 查找指定元素位置
int SearchLinkListData(sp head, datatype data);
// 指定位置查元素
datatype SearchLinkListPost(sp head, int post);
// 转置链表
void ReverseLinkList(sp head);

#endif