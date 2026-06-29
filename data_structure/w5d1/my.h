#include<stdio.h>
#include<stdlib.h>

#define N 100;

typedef char datatype;

typedef struct linked_list
{
    datatype ele;
    struct linked_list *poit;
}sl, *sp;

sp LinkedList(datatype data);