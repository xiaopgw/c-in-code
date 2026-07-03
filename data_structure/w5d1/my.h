#ifndef _MY_H
#define _MY_H

#include<stdio.h>
#include<stdlib.h>


typedef char datatype;

typedef struct linked_list
{
    datatype ele;
    struct linked_list *poit;
}sl, *sp;

sp LinkedList(datatype data);

#endif