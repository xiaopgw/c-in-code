#include"my.h"
sp LinkedList(datatype data)
{
    sp p = (sp)malloc(sizeof(sl));
    p->ele = data;
    p->poit = NULL;
    return p;
}