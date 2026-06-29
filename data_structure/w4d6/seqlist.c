#include<stdio.h>
#include<stdlib.h>
#define N 1
typedef char datapyte;
typedef struct seqlist
{
    datapyte arr[N];
    long last;
}st, *sp;

sp CreateEpSeqlist()
{
    sp p;
    // p = (sp)malloc(sizeof(st));
    p == NULL;
    if(p == NULL)
    {
        perror("输出");
        return NULL;
    }
    p->last = -1;
    return p;
}
int main(int argc, char const *argv[])
{
    sp p = CreateEpSeqlist();
    printf("%p\n", p);
    printf("%p\n", p->arr);
    printf("%p\n", &(p->last));
    printf("%p\n", &(p->arr[1]));
    return 0;
}
