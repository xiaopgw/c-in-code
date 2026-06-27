#include "my.h"
sp s()
{
    sp p = (sp)malloc(sizeof(ss));
    if(p == NULL)
    {
        perror("X-X");
        return NULL;
    }
    p->last = -1;
    return p;
}
