#ifndef _MY_H
#define _MY_H

#define N 8

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef int datatype;
typedef struct doublelinklist
{
    // 需要有两个指针和一个数据
    // 需要头尾指针指向头为节点
    // 需要一个长度
    datatype data;
    struct doublelinklist *prev;
    struct doublelinklist *next;
}dbprintnode_t, *dbprintnode_p;
typedef struct doublelinklistpoint
{
    dbprintnode_p front;
    dbprintnode_p rear;
    int len;
}dblinkanchor_t, *dblinkanchor_p;

// // 创建双向链表头
// dblinkanchor_p createdbLinkhead();
// // 插入节点
// int pushdblink(dblinkanchor_p link, int post, datatype data);
// // 删除节点
// int Popdblink(dblinkanchor_p link, int post);
// // 遍历
// void Showbdlink(dblinkanchor_p link);
// // 释放整个链表包括头
// void destroy_list(dblinkanchor_p link);
// // 按值查找
// int search_by_value(dblinkanchor_p link, datatype data);
// // 释放整个链表不包括头
// void destroy_list_nohead(dblinkanchor_p link);

// 创建双向链表头
dblinkanchor_p createdbLinkhead2();
// 插入节点
int pushdblink2(dblinkanchor_p link, int post, datatype data);
// 删除节点
// int Popdblink2(dblinkanchor_p link, int post);
// // 遍历
void Showbdlink2(dblinkanchor_p link);
// 释放整个链表包括头
// void destroy_list2(dblinkanchor_p link);
// // 按值查找
// int search_by_value2(dblinkanchor_p link, datatype data);
// // 释放整个链表不包括头
// void destroy_list_nohead2(dblinkanchor_p link);

// typedef struct tree
// {
//     // 树需要数据和左右子
//     datatype data;
//     struct tree *lc;
//     struct tree *rc;
// }st, *sp;

// // 树创建
// // 利用完美二叉树创建
// // 只需要n的个数的创建，并且第一个只能是1
// sp createtree(int i, int n);
// // 遍历
// void Showtree(sp tree);

#endif