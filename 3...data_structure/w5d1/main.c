#include "my.h"
int main(int argc, char const *argv[])
{
    // sp hp = NULL, ptail = NULL, pnew = NULL;
    // hp = malloc(sizeof(sl));
    // ptail = hp;
    // if (hp == NULL)
    // {
    //     printf("N");
    //     return -1;
    // }
    // datatype num = 0;
    // while (1)
    // {
    //     scanf("%d", &num);
    //     if (num == -1)
    //         break;
    //     pnew = malloc(sizeof(sl));
    //     pnew->ele = num;
    //     pnew->poit = NULL;
    //     ptail->poit = pnew;
    //     ptail = pnew;
    // }
    // while (hp->poit != NULL)
    // {
    //     hp = hp->poit;
    //     printf("%d ", hp->ele);
    // }

    // sp q = NULL, h = NULL;
    // int i = 1;
    // q = LinkedList(100);
    // h = q;
    // while (i < 10)
    // {
    //     q->poit = LinkedList(101);
    //     printf("%d\n", q->ele);
    //     i++;
    // }
    // q = h;
    // while (q->poit != NULL)
    // {
    //     q = q->poit;
    //     printf("%c\n", q->ele);
    // }

    // LinkedList(sp p, datatype data);

    // printf("-------------------------\n");
    // sl H = {'\0', NULL};
    // sl A = {'a', NULL};
    // sl B = {'b', NULL};
    // sl C = {'c', NULL};
    // sl D = {'d', NULL};
    // sl E = {'e', NULL};
    // A.poit = &B;
    // B.poit = &C;
    // C.poit = &D;
    // D.poit = &E;
    // H.poit = &A;
    // sp p = &H;
    // while (p->poit != NULL)
    // {
    //     p = p->poit;
    //     printf("%c ", p->ele);
    // }


    // sp hp = NULL, ptail = NULL, pnow = NULL;
    // hp = malloc(sizeof(sl));
    // if (hp == NULL)
    //     perror("N");
    // ptail = hp;
    // int i = 10;
    // while (1)
    // {
    //     i--;
    //     if (i < 0)
    //         break;
    //     pnow = malloc(sizeof(sl));
    //     if (pnow == NULL)
    //     perror("N");
    //     pnow->ele = i;
    //     ptail->poit = pnow;
    //     ptail = pnow;
    // }
    // while (hp->poit != NULL)
    // {
    //     hp = hp->poit;
    //     printf("%d ", hp->ele);
    // }
    // putchar (10);



    #define N 100;
    sp tou = NULL, wei = NULL, xin = NULL;
    tou = malloc(sizeof(sl));
    if (tou == NULL)
        perror("错误警告");
    wei = tou;
    datatype n = 107;
    while (1)
    {
        n--;
        if (n < 97)
            break;
        xin = malloc(sizeof(sl));
        xin->ele = n;
        wei->poit = xin;
        wei = xin;
    }
    while (tou->poit != NULL)
    {
        tou = tou->poit;
        putchar(tou->ele);
        putchar(32);
    }
    putchar(10);

    return 0;
}
