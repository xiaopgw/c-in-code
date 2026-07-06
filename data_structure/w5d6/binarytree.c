#include "my.h"
// // 创建双向链表头
// dblinkanchor_p createdbLinkhead()
// {
//     dblinkanchor_p dblink = malloc(sizeof(dblinkanchor_t));
//     if (dblink == NULL)
//     {
//         perror("X->");
//         return NULL;
//     }
//     // printf("1\n");
//     dblink->front = dblink->rear = malloc(sizeof(dbprintnode_t));
//     dblink->front->next = NULL;
//     dblink->rear->prev = NULL;
//     dblink->len = 0;
//     return dblink;
// }
// // 插入节点
// int pushdblink(dblinkanchor_p link, int post, datatype data)
// {

//     // 判断节点存不存在
//     if (post < 0 || post > link->len)
//     {
//         printf("X");
//         return -1;
//     }
//     // printf("2\n");
//     // 创建新节点
//     dbprintnode_p pnew = malloc(sizeof(dbprintnode_t));
//     if (pnew == NULL)
//     {
//         printf("X");
//         return -1;
//     }
//     pnew->data = data;
//     // 判断要加入节点的位置
//     if (post == link->len)
//     {
//         // printf("1\n");
//         // 在尾
//         pnew->next = NULL;
//         pnew->prev = link->rear;
//         link->rear->next = pnew;
//         link->rear = pnew;
//         link->len++;

//         return 0;
//     }
//     // 在中
//     if (post <= link->len / 2)
//     {
//         // 在中前半
//         dbprintnode_p head = link->front;
//         for (int i = 0; i <= post; i++)
//         {
//             head = head->next;
//         }
//         pnew->prev = head->prev;
//         pnew->next = head;
//         head->prev->next = pnew;
//         head->prev = pnew;
//     }
//     else
//     {
//         // 在中后半
//         dbprintnode_p head = link->rear;
//         for (int i = 0; i < (link->len - 1 - post); i++)
//         {
//             head = head->prev;
//         }
//         pnew->prev = head->prev;
//         pnew->next = head;
//         head->prev->next = pnew;
//         head->prev = pnew;
//     }
//     link->len++;
//     return 0;
// }
// // 删除节点
// int Popdblink(dblinkanchor_p link, int post)
// {
//     // 判断节点存不存在
//     if (post < 0 || post >= link->len)
//     {
//         printf("X");
//         return -1;
//     }
//     // 判断要加入节点的位置
//     if (post == link->len - 1)
//     {
//         // 在尾
//         dbprintnode_p tail = link->rear;
//         link->rear = tail->prev;
//         link->rear->next = NULL;
//         free(tail);
//         link->len--;
//         return 0;
//     }
//     // 在中
//     if (post <= link->len / 2)
//     {
//         // 在中前半
//         dbprintnode_p head = link->front;
//         for (int i = 0; i <= post; i++)
//         {
//             head = head->next;
//         }
//         head->next->prev = head->prev;
//         head->prev->next = head->next;
//         free(head);
//     }
//     else
//     {
//         // 在中后半
//         dbprintnode_p head = link->rear;
//         for (int i = 0; i < (link->len - 1 - post); i++)
//         {
//             head = head->prev;
//         }
//         head->next->prev = head->prev;
//         head->prev->next = head->next;
//         free(head);
//     }
//     link->len--;
//     return 0;
// }

// // 遍历
// void Showbdlink(dblinkanchor_p link)
// {
//     dbprintnode_p head = link->front;
//     while (head->next != NULL)
//     {
//         head = head->next;
//         printf("%d ", head->data);
//     }
//     printf("\n");
// }

// // 释放整个链表包括头
// void destroy_list(dblinkanchor_p link)
// {
//     while (link->front != NULL)
//     {
//         dbprintnode_p head = link->front;
//         link->front = head->next;
//         free(head);
//     }
// }
// // 释放整个链表不包括头
// void destroy_list_nohead(dblinkanchor_p link)
// {

//     while (link->front->next != NULL)
//     {

//         dbprintnode_p head = link->front->next;
//         link->front->next = head->next;
//         free(head);
//     }
// }
// // 按值查找
// int search_by_value(dblinkanchor_p link, datatype data)
// {
//     int l = 0;
//     dbprintnode_p head = link->front;
//     while (head->next != NULL)
//     {
//         head = head->next;
//         if (head->data == data)
//         {
//             printf("%d ", l);
//         }
//         l++;
//     }
//     return -1;
// }

// // 树创建
// // 利用完美二叉树创建
// // 只需要n的个数的创建，并且第一个只能是1
// sp createtree(int i, int n)
// {
//     // if (i * 2 > n)
//     // {
//     //     return NULL;
//     // }
//     // 开空间
//     sp tree = malloc(sizeof(st));
//     if (tree == NULL)
//     {
//         perror("X->");
//         return 0;
//     }
    
//     // 初始化
//     tree->data = i;
//     // printf("%d ", tree->data);
//     // 判断有没有左右子,
//     if (i * 2 <= n)
//     {
//         // 有则进行递归
//         // printf("%d ", tree->data);
//         tree->lc = createtree(i * 2, n);
//     }
//     else
//     {
//         tree->lc =  NULL;
//     }
//     if (i * 2 + 1 <= n)
//     {
//         // printf("%d ", tree->data);
//         // 有则进行递归
//         tree->rc = createtree(i * 2 + 1, n);
//     }
//     else
//     {
//         tree->rc =  NULL;
//     }
//     return tree;
// }

// // 遍历
// void Showtree(sp tree)
// {
//     if (tree == NULL)
//     {
//         return;
//     }
//     // 打印头
//     printf("%d ", tree->data);
//     // 判断有没有左子,
//     if (tree->lc != NULL)
//     {
//         // printf("-1-\n");
//         Showtree(tree->lc);
//     }
//     // 判断有没有右子
//     if (tree->rc != NULL)
//     {
//         // printf("-2-\n");
//         Showtree(tree->rc);
//     }
// }

// 创建双向链表头
dblinkanchor_p createdbLinkhead2()
{
    // printf("1");
    dblinkanchor_p link = malloc(sizeof(dblinkanchor_t));
    link->front = link->rear = malloc(sizeof(dbprintnode_p));
    link->front->next = link->rear->prev = NULL;
    link->len = 0;
    return link;
}
// 插入节点
int pushdblink2(dblinkanchor_p link, int post, datatype data)
{
    if (post < 0 || post > link->len)
    {
        return -1;
    }
    
    dbprintnode_p pnew = malloc(sizeof(dbprintnode_t));
    pnew->data = data;
    
    if (post == link->len)
    {
        pnew->next = NULL;
        pnew->prev = link->rear;
        link->rear->next = pnew;
        link->rear = pnew;
        link->len++;
        // printf("%d", link->len);
        return 0;
    }
    if (post <= link->len / 2)
    {
        // printf("%d", link->len);
        dbprintnode_p head = link->front;
        for (int i = 0; i <= post; i++)
        {
            head = head->next;
        }
        pnew->next = head;
        pnew->prev = head->prev;
        head->prev->next = pnew;
        head->prev = pnew;
        
    }
    else
    {
        // printf("%d", link->len);
        dbprintnode_p head = link->rear;
        for (int i = link->len - 1; i > post; i--)
        {
            head = head->prev;
        }
        pnew->next = head;
        pnew->prev = head->prev;
        head->prev->next = pnew;
        head->prev = pnew;
        
    }
    link->len++;
    return 0;
}
// 遍历
void Showbdlink2(dblinkanchor_p link)
{
    dbprintnode_p head = link->front;
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    }
    
}