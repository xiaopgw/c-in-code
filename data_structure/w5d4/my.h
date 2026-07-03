#ifndef _MY_H
#define _MY_H

#define N 8

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef int datatype;
// typedef struct seqqueue
// {
//     datatype *data;
//     int maxlen;
//     int rear;
//     int front;
// }ss, *sp;
// typedef struct linkedstack
// {
//     datatype data;
//     struct linkedstack *next;
// }sl, *sq;
// typedef struct linkqueue
// {
//     sq front;
//     sq rear;
// }sfr, *pfr;

// sp CreateSeqStack();
// // 入列
// int PushSeqStack(sp p, datatype data);
// // 判满
// int FullSeqStack(sp p);
// // 遍历
// int ShowSeqStack(sp p);
// // 出列
// int PopSeqStack(sp p);
// // 队列长度
// int LongSeqStack(sp p);

// // 创空
// pfr CreateLinkStack();
// // 入列
// sq PushLinkedStack(pfr fr, datatype data);
// // 遍历
// void ShowLinkedStack(pfr fr);
// // 判空
// int NullLinkStack(pfr fr);
// // 出列
// int PopLinkStack(pfr fr);
// // 计算长度
// int LongLinkedStack(pfr fr);


typedef struct double_node
{
    datatype data;
    struct double_node *prev;
    struct double_node *next;
}dbnode_t, *dbnode_p;
typedef struct 
{
    dbnode_p head;
    dbnode_p tail;
    int len;
}dbpoint_t, *dbpoint_p;

// 创空
dbpoint_p CreateDoubleLinkedList();
// 插入
int PushDoubleLinkedList(dbpoint_p top, int post, datatype data);
// 遍历
void ShowDoubleLinkedList(dbpoint_p top);
// 删除
int DeleteBoubleLinkedList(dbpoint_p top, int post);

#endif