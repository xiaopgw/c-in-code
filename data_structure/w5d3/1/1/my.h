#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>

//创建存储数据类型
typedef int datatype;

// 创建顺序表结构体
// 结构体需要数组，尾偏移，数组长度
typedef struct sequentilstack
{
    datatype *data;
    int all;
    int top;
}ss, *sp;

// 全部遍历
void ShowStack(sp p);
// 入栈
int PushStack(sp p, datatype data);
// 满
int FullStack(sp p);
// 创建一个空的数组存顺序栈
sp CreatSequeStack();
// 判空
int NullStack(sp p);
// 出栈
int PopStack(sp p);
// 求长度
int LengStack(sp p);

#endif