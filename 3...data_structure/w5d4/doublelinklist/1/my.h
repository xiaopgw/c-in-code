#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;
// 双向链表
typedef struct doublelinklist
{
    datatype data;
    struct doublelinklist *prev;
    struct doublelinklist *next;
}dbqueue_t, *dbqueue_p;
// 头尾指针
typedef struct doublelinkoffset
{
    int len;
    dbqueue_p front;
    dbqueue_p rear;
}dboffset_t, *dboffset_p;

 // 创空有头链表
dboffset_p CreateLinklist();
// 狠狠的插入
int PushLinkList(dboffset_p link, int post, datatype data);
// 遍历
void ShowDoubleLinkList(dboffset_p link);
// 狠狠的抽出
int PopLinkList(dboffset_p link, int post);

#endif