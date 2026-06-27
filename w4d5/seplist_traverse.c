#include "my.h"
void seplist_traverse(int *arr, int last)
{
    for (int i = 0; i < last + 1; i++)
    {
        printf("%d ", arr[i]);
    }
}