#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>


typedef int datatype;

typedef struct linkedstack
{
    datatype data;              //数据
    struct linkedstack *poit;   //指针
}sl, *sp;

// 用指针创建空节点
void CreateEmptyLinkStack(sp *p);
// 头插
datatype PushStack(sl **head, datatype data);
// 遍历
int ShowStack(sp p);
// 出栈
datatype PopStack(sp *top);
// 清空
void DeleteStack(sp *top);
// 求长度
int LengStack(sl *top);

#endif