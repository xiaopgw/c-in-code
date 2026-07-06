#include"my.h"
int main(int argc, char const *argv[])
{
    // dblinkanchor_p link =  createdbLinkhead();
    // for (int i = 0; i < 8; i++)
    // {
    //     pushdblink(link, i, i + 1);
    // }
    // Popdblink(link, 3);
    // Showbdlink(link);

    // // destroy_list(link);
    // // Showbdlink(link);

    // // 释放整个链表不包括头
    // destroy_list_nohead(link);
    // Showbdlink(link);;
    

    // sp tree = createtree(1, 5);
    // putchar(10);
    // Showtree(tree);
    
    dblinkanchor_p link2 = createdbLinkhead2(); 
    for (int i = 0; i < 8; i++)
    {
        pushdblink2(link2, i, i + 1);
    }
    pushdblink2(link2, 1, 64);
    pushdblink2(link2, 2, 32);
    pushdblink2(link2, 4, 16);
    pushdblink2(link2, 8, 8);
    putchar(10);
    Showbdlink2(link2);
    return 0;
}
