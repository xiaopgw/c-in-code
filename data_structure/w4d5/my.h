#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>

#define N 64

typedef struct seplist
{
    int data[N];
    int last;
}ss, *sp;

extern int n;

int insert(int *p, int post, int data);
void traverse(int *arr);
int deletem(int *p, int post);
sp s();
int seplist_insert(sp p, int post, int data);
int seplist_delete(sp p, int post);
void seplist_traverse(sp p);
int seplist_IsFull(sp p);
int seplist_IsEp(sp p);
int seplist_ChangePost(sp p, int post, int data);
int seplist_searchdata(sp p, int data);


#endif