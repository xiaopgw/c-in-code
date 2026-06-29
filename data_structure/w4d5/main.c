#include "my.h"
int n = 0;
int main(int argc, char const *argv[])
{
    sp p = s();
    int post = 5/*下标5*/, data = 64;
    p->last = 9;
    for (int i = 1; i <= 10; i++)
    {
        p->data[i - 1] = i;
    }
    seplist_insert(p, post, data);
    seplist_delete(p, post);
    seplist_traverse(p);
    seplist_ChangePost(p, post, data);
    while (1)
    {
        scanf("%d", &data);
        printf("%d\n", seplist_searchdata(p, data));
        seplist_traverse(p);
    }
    printf("\n---------------------------\n");

    // int arr[64] = {1,2,3,4,5,6,7,8,9,10};
    // n = 9;
    // insert(arr, post, data);
    // traverse(arr);
    // while(1)
    // {
    //     scanf("%d", &post);
    //     printf("\n");
    //     deletem(arr, post);
    //     traverse(arr);
    // }
    return 0;
}
