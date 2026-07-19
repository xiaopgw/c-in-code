# 顺序表
## 特点
内存空间连续
顺序表长度固定
在顺序表中插入或删除是都设计到元素的移动，效率极低，查找和修改效率高
# 链表
线性结构
链式存储结构
内存不连续，通过指针链接
## 单项链表
有头链表：存在一个头节点，头节点指针域有效，数据域无效
无头链表：每一个节点的数据域和指针域都有效

遍历有头单项链表
#include <stdio.h>
typedef char datatype;
typedef struct node_t
{
    datatype data;       // 数据域：用来存储数据
    struct node_t *next; // 指针域：用来存储下一个节点的地址
} link_node_t, *link_node_p;

// link_node_t A; //等同于struct node_t A
// link_node_p p; //等同于struct node_t *p

int main(int argc, char const *argv[])
{
    // 1. 定义4个节点
    link_node_t A = {'a', NULL};
    link_node_t B = {'b', NULL};
    link_node_t C = {'c', NULL};
    link_node_t D = {'d', NULL};

    // 2. 将四个节点链接起来
    A.next = &B;
    B.next = &C;
    C.next = &D;

    // 3. 创建头节点，链接第一个节点
    link_node_t H = {'\0', &A};

    // 4.创建头指针，指向头节点
    link_node_p p = &H;

    // 5. 遍历有头单向链表
#if 0
    //方法一:
    //先跨越头节点
    p = p->next;
    // 遍历无头单向链表
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
#else
    // 方法二:
    while (p->next != NULL)
    {
        p = p->next;
        printf("%c ", p->data); // a b c d
    }
    printf("\n");
#endif
    return 0;
}
