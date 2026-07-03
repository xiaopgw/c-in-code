#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>


typedef int datatype;

typedef struct sequerntialstack
{
    datatype *data; //空间首地址
    int maxlen;     //空间大小
    int top;        //最后一个元素的下标
}ss, *sp;

//创建空的顺序栈
sp CreateEmptySeqStack(int len);
// 判满
int FullSepStack(sp p);
// 判空
int NullSepStack(sp p);
// 入栈
int PushStack(sp p, datatype data);
// 出栈
int PopStack(sp p);
// 遍历
void ShowSepStack(sp p);
// 真实数据遍历
void RealShowSepStack(sp p);
// 计算数据长度
int LongSepStack(sp p);
// 读取栈，不改变长度
int TopStack(sp p);
// 释放所有空间
void DestroySeqStack(sp p);

#endif