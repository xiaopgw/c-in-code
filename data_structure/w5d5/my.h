#ifndef _MY_H
#define _MY_H

#define N 8

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef int datatype;
typedef struct binarytreelinklist
{
    datatype data;
    struct binarytreelinklist *lchild;
    struct binarytreelinklist *rchild;
}binnode_t, *binnode_p;

// binnode_p PushBinary();
binnode_p CreateBinary(datatype data, int n);
// 遍历
binnode_p ShowBinary(binnode_p root, int n);

#endif