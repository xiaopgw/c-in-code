#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// char *mystrstr(char *p, const char *q);

// struct snake1
// {
//     int head;
//     int body1;
//     int body2;
//     int tail;
//     float alllong;
//     char name[32];
// };
// void mystruct();
// typedef struct snake2
// {
//     int head;
//     char name[32];
//     float height;
// } ss;

// void myss(ss *p);
// void *fun(char **q)
// {
//     *q = (char *)malloc(10);
//     strcpy(*q, "hello");
// }
enum
{
    n1,
    n2,
    n3,
    n4,
    n5,
};

int main()
{
    printf("%d\n", n1);
    // char *p = NULL;
    // fun(&p);
    // printf("%s\n", p);
    // free(p);
    // return 0;
    // fun();
    // ss s;
    // ss *b = &s;
    // scanf("%d", *(&((b + 1)->head)));
    // scanf("%s", (b + 2)->name);
    // struct snake1 s = {1, 2, 3, 4, 3.8, "lucky"};
    // scanf("%d%lf%s", &s2.head, &s2.alllong, s2.name);
    // printf("%d%d%d%d %.1lf %s\n", s2.head, s2.body1, s2.body2, s2.tail, s2.alllong, s2.name);
    // printf("%ld\n", sizeof(s2));
    // struct snake2 s3[4] =
    // {
    //     {1, "lucky1", 48},
    //     {2, "lucky2", 49},
    //     {3, "luchy3", 50},
    // };
    // s3[3].head = 4;
    // strcpy (s3[3].name, "lucky4");
    // // scanf("%c", &s3[3].a);
    // for (int i = 0; i < 4; i++)
    //     printf("%d %s %c\n", s3[i].head, s3[i].name, s3[i].a);
    // printf("%c\n", s3[3].a);

    // typedef struct snake2 ss;
    // ss s4 = {5, "lucky5", 'E'};
    // ss *a4 = &s4;
    // printf("%d\n", a4 -> head);
    // printf("%s\n", (*a4).name);
    // ss *a3 = s3;
    // scanf("%d %s %c", &(a3[1].head), (*(a3 + 1)).name, &((a3 + 1) -> a));
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d %s %c\n", a3[i].head, (*(a3 + i)).name, (a3 + i) -> a);
    // }

    // char arr1[32] = "hello world", arr2[32] = "lo";
    // if (mystrstr(arr1, arr2) == NULL)
    // {
    //     printf("NULL");
    // }
    // else printf("%s\n", mystrstr(arr1, arr2));
    // ss s[4];
    // ss *p = s;
    // int len = sizeof(s) / sizeof(s[0]);
    // for (int i = 0; i < len; i++)
    // {
    //     scanf("%d %s %f", &p[i].head, (*(p + i)).name, &((p + i) -> height));
    //     printf("%d %s %.1f\n", (p + i) -> head, (p + i) -> name, (*(p + i)).height);
    // }
    // myss(s);
    // mystruct();
}

// void myss(ss *p)
// {
//     for (size_t i = 0; i < 4; i++)
//     {
//         scanf("%d %s %f", &p[i].head, (p + i)->name, &(*(p + i)).height);
//         printf("%d, %s, %.1f", (p + i)->head, p[i].name, p[i].height);
//     }
// }















// char *mystrstr(char *p, const char *q)
// {
//     int m = strlen(p);
//     int n = strlen(q);
//     for (int i = 0; p[i] != 0; i++)
//     {
//         int j = 0;
//         for (; q[j] != 0; j++)
//         {
//             if (p[i + j] != q[j])
//             {
//                 break;
//             }
//         }
//         if (q[j] == 0)
//         return p + i;
//     }
//     return NULL;
// }
// char *mtstrstr2(char *p, char *q)
// {

// }
