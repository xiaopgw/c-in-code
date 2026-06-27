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
int seplist_insert(int *p, int *last, int post, int data);
int seplist_delete(int *p, int *last, int post);
void seplist_traverse(int *arr, int last);




#endif