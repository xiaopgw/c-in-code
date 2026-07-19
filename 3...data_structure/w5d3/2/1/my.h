#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;
typedef struct linkedstack
{
    datatype data;
    struct linkedstack *poit;
}sl, *sp;

// 初始化顶部指针
void CreateStack(sp *top);
// 入栈
int PushStack(sp *top, datatype data);
// 遍历
void ShowStack(sp top);
// 判空
int NullStack(sp top);
// 出栈
int PopStack(sp *top);
// 栈长
int LongStack(sp top);

#endif