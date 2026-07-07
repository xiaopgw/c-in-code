#ifndef _MY_H
#define _MY_H

#define N 8

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef int datatype;
typedef struct linklistqueue
{
    datatype data;
    struct linklistqueue *next;
}sl, *sp;


#endif