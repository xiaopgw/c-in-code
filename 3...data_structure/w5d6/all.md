26051 数据结构
学习方法：
1.心态一定要好，做好攻坚克难的准备。
2.一定要多动手敲代码，即使有bug也尝试自己去调试实在解决不了也得求助老师同学。遇到问题不好解决可以先记下来，然后练习的时候或者课间问， 要跟上课堂进度。
3.代码不要死记硬背，重点记住逻辑。可以通过梳理已经做过的练习来提高编程能力。
4.可以用自己的方法实现功能，但是课上讲的必须要掌握，不能光写自己的方法老师讲的就不听了。
5.如果一上来代码写不出来，先自己在纸上画图梳理逻辑或者归纳数学规律，遍梳理遍手写代码框架，然后再去虚拟机上敲出来验证。
6.这门课一定要结合着画图去理解，课后自己也要画图去复盘逻辑，知道每行代码对照着图里的哪一个步骤。要达到能自己画着图给别人讲明白的程度。最终能达到脑海中有图然后熟练讲出来的程度。

大纲
数据结构、算法(理解)
线性表: 顺序表(数组)、链表(单向链表、单向循环链表、双向链表、双向循环链表)、栈(顺序栈、链式栈)、队列(循环队列、链式队列)
树: 特性、二叉树(性质、创建、遍历)
排序方法、查询方法(原理、思路)

为什么学数据结构
1.C语言如何写程序
学数据结构是为了简洁、高效的写程序。
2.如果遇到一个实际问题，需要写代码实现相应功能，需要解决两个方面问题:
(1)如何表达数据之间的逻辑接关系以及怎么存储到计算机中?
数据结构: 数据的逻辑结构以及存储操作。
数据: 不再是单纯的数字，而是类似于集合的概念。
结构：数据之前的关系
（2）采用什么方法解决?
采用算法去解决

==> 数据结构 + 算法 = 程序
问题 --> 数据结构 + 算法 = 程序 --> 解决问题

1.数据结构基础知识
1.1 什么是数据结构
数据的逻辑结构以及存储操作(数据的运算)
数据结构没有那么复杂，它就教会你一件事情: 如何更有效地存储数据。

1.2 数据
数据：不再是单纯的数字，而是类似于集合的概念。
数据元素: 是数据的基本单位，由若干个数据项组成。
数据项：数据的最小单位，描述数据元素的有用的信息。
数据元素又叫节点

例如：
计算机处理的对象(数据)已不再是单纯的数值：
图书管理中的数据，如下表所列:

数据：图书
数据元素：每一本书
数据项：编号、书名、作者等

1.3 逻辑结构
数据元素并不是孤立存在的，它们之间存在某种关系(或联系、结构)，元素和元素之间的关系:
●线性关系
线性结构
 -> 一对一 -> 线性表: 顺序表、链表、栈、队列

●层次关系
树形结构 
--> 一对多 --> 树： 二叉树

●网状关系
图状结构 --> 多对多 --> 图



例题：
田径比赛的时间安排问题



1.4 存储结构
数据的逻辑结构在计算机中的具体实现
1.4.1 顺序存储
特点：内存连续，用数组实现，随机存取，每个元素占用空间较少。
数组：内存连续

1.4.2 链式存储
特点：内存不连续，通过指针实现。
链表实现:
结构体:


#include <stdio.h>
struct node_t
{
    int data;            // 数据域：存放节点的数据的成员
    struct node_t *next; // 指针域：保存下一个节点的地址的成员(自身结构体类型指针)
};

int main(int argc, char const *argv[])
{
    // 定义3个节点
    struct node_t A = {1, NULL};
    struct node_t B = {2, NULL};
    struct node_t C = {3, NULL};

    // 连接三个节点
    A.next = &B; // 让A中的指针保存B的地址，就可以让A链接B节点了
    B.next = &C; // 让B中的指针域保存C的地址，就可以让B链接C节点了

    // 访问三个节点
    printf("%d\n", A.data);
    printf("%d\n", A.next->data);
    printf("%d\n", A.next->next->data);

    return 0;
}

 

1.4.3 索引存储
在存储数据的同时，建立一张附加的索引表。
索引存储 = 索引表 + 数据文件

这样查找一个电话就可以先查找索引表，再查找对应的数据文件，加快了查询的速度。但是如果删除或添加某个数据也要操作对应的索引表。
1.4.4 散列存储
数据存储按照和关键码之间的关系进行存取，关系由自己决定，比如关键码是key,存储的位置也就是关系是key+1。获取关键数据，通过元素的关键码和关系来返回值获取。
存的时候按照关系存
取的时候按照关系取

1.5 操作
增 删 改 查

2.算法基础知识
算法就是解决问题思想方法，数据结构是算法的基础。
数据结构 + 算法 = 程序
2.2 算法的设计
算法的设计: 取决于数据的逻辑结构
算法的实现: 依赖于数据的存储结构

2.3 特性
有穷性: 步骤是有限
确定性: 每个步骤都是明确的含义，无二义性
可行性：规定时间内能完成
输入
输出

2.4 评价算法好坏
正确性
易读性
健壮性: 容错处理
高效性: 执行效率，通过重复执行语句的次数来判断，也就是通过时间复杂度(时间处理函数)来判断。

时间复杂度:
语句频度： 用时间规模函数表达式
时间规模函数: T(n) = O(f(n))
T(n)  //时间规模的时间函数
O		//时间数量级
n		//问题规模，例如: a[100], n=100
f(n)		//算法可执行语句重复执行的次数

称O(f(n)) 为算法的渐进时间复杂度，简称时间复杂度。
渐进时间复杂度用大写O来表示，所以也被称为大O表示法。直白的讲，时间复杂度就是把时间规模函数T(n)简化为一个数量级，如n，n^2，n^3。

例子1:
求1+2+3+4+ ... +n的和
算法1: 
int sum=0;
for(int i=1;i<=n;i++)
{
    sum+=i;
}
 
f(n) = n
==>T(n) = O(n)

算法2:
利用等差数列前n项和公式：Sn=n*a1+n(n-1)d/2  或 Sn=n(a1+an)/2 (d是公差） 
int sum = (1+n)*n/2;
 
f(n) = 1
==>T(n) = O(1) 

例2：
int i,j;
for(i=0;i<n;i++)
{
	 for(j=0;j<n;j++)
    {
	    printf("ok\n");       //n*n次
    }
}

T(n)=O(n^2)

例3：
int i,j;
for(i=0;i<n;i++)
{
    for(j=0;j<=i;j++)
    {
        printf("ok\n");
    }
}

1 + 2 + 3 + ... + n
f(n) = (1+n)*n/2 = n/2 + n^2/2
//只保留最高项，除以最高项系数得到n^2
 T(n) = O(n^2)

计算大O的方法:
(1)根据问题规模n写出表达式f(n)
(2)如果有常数项，将其置为1   //f(n)=8  ==> O(1)
(3)只保留最高项，其他项舍去
(4)如果最高项系数不为1，除以最高项系数
f(n) = 3*n^4 + 2*n^3 + 6*n^7 +10
==> O(n^7)

3.线性表
线性表是最基本、最简单、也是最常用的一种数据结构，可以存储逻辑关系为线性的数据。线性表（linear list）是数据结构的一种，一个线性表是n个具有相同特性的数据元素的有限序列。
包含：顺序表(数组)、链表(单向链表、单向循环链表、双向链表、双向循环链表)、栈(顺序栈、链式栈)、队列(循环队列、链式队列)
逻辑结构: 线性结构
存储结构：顺序存储(顺序表，用数组) 或 链式存储(链表，通过指针实现)
特点：一对一，每个节点最多一个前驱和一个后继，首个节点无前驱，尾节点无后继。
3.1 顺序表
顺序表存储数据的具体实现方案是：将数据全部存储到一整块内存空间中，数据元素之间按照次序挨个存放。
举个简单的例子，将 {1,2,3,4,5} 这些数据使用顺序表存储，数据最终的存储状态如下图所示：

3.1.1 顺序表的特性
特点：内存连续
逻辑结构： 线性结构
存储结构： 顺序存储
3.1.2 操作数组
例题:
int a[100]={1,2,3,4,5,6,7,8};
函数命名规则：
下划线法：create_empty_seqlist
小驼峰法：createEmptySeqList
大驼峰法：CreateEmptySeqList
#include <stdio.h>

//(1)插入数组元素
/*
    功能：向数组的第几个位置插数据，insert:插入
    函数：void insertIntoA(int *p,int n, int post, int data);
    参数：
    int *p: 保存数组首地址
    int n: 有效数据元素的个数
    int post: 插入元素下标
    int data: 数据
*/
void insertIntoA(int *p, int n, int post, int data)
{
    // 1.从最后一个元素开始到插入位置元素往后移动一个单位
    for (int i = n - 1; i >= post; i--) // i=3, >= 4
        p[i + 1] = p[i];                // p[5]=p[4]
    // 2.将数据存入到指定位置
    p[post] = data;
}

//(2)遍历数组
/*
    功能：遍历数组中的有效元素
    函数：void showA(int *p,int n);
    参数：
    int *p:保存数组收地址
    int n:有效数据元素的个数
*/
void showA(int *p, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

//(3)删除数组元素
/*  功能：删除数组中指定元素,delete:删除
    函数：void deleteIntoA(int *p,int n, int post);
    参数：
    int *p: 保存数组首地址
    int n: 有效数据元素的个数
    int post: 删除元素下标
*/
void deleteIntoA(int *p, int n, int post)
{
    // 1. 从删除的后一个元素开始到最后一个元素往前移动一个单位
    for (int i = post + 1; i <= n - 1; i++)
        p[i - 1] = p[i];
}

int main(int argc, char const *argv[])
{
    int a[100] = {1, 2, 3, 4, 5, 6, 7, 8};
    insertIntoA(a, 8, 4, 100);
    showA(a, 9);
    deleteIntoA(a, 9, 4);
    showA(a, 8);

    return 0;
}
 

3.1.3 添加全局变量last表示最后一个有效元素下标
#include <stdio.h>
int last = 7; // 代表最后一个有效元素下标，last=n-1(也就是有效元素个数-1)
//(1)插入数组元素
/*
    功能：向数组的第几个位置插数据，insert:插入
    函数：void insertIntoA(int *p,int post, int data);
    参数：
    int *p: 保存数组首地址
    int post: 插入元素下标
    int data: 数据
*/
void insertIntoA(int *p, int post, int data)
{
    // 1.从最后一个元素开始到插入位置元素往后移动一个单位
    for (int i = last; i >= post; i--)
        p[i + 1] = p[i];
    // 2.将数据存入到指定位置
    p[post] = data;
    // 3. 让last加一
    last++;
}

//(2)遍历数组
/*
    功能：遍历数组中的有效元素
    函数：void showA(int *p);
    参数：
    int *p:保存数组收地址
*/
void showA(int *p)
{
    for (int i = 0; i <= last; i++)
        printf("%d ", p[i]);
    printf("\n");
}

//(3)删除数组元素
/*  功能：删除数组中指定元素,delete:删除
    函数：void deleteIntoA(int *p,int post);
    参数：
    int *p: 保存数组首地址
    int post: 删除元素下标
*/
void deleteIntoA(int *p, int post)
{
    // 1. 从删除的后一个元素开始到最后一个元素往前移动一个单位
    for (int i = post + 1; i <= last; i++)
        p[i - 1] = p[i];
    // 2. 让last减一
    last--;
}

int main(int argc, char const *argv[])
{
    int a[100] = {1, 2, 3, 4, 5, 6, 7, 8};
    insertIntoA(a, 4, 100);
    showA(a);
    deleteIntoA(a, 4);
    showA(a);

    return 0;
}

 

3.1.4 顺序表最终实现
封装结构体: 包含存数据的数组和表示最后有效元素下表的last


#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef int datatype;
typedef struct seqlist
{
    datatype data[N];
    int last;
} seqlist_t, *seqlist_p;

// 创建空顺序表 create：创建 empty:空的 seqlist:顺序表
seqlist_p CreateEpSeqlist()
{
    // 1.动态申请顺序表类型空间
    seqlist_p p = (seqlist_p)malloc(sizeof(seqlist_t));
    if (NULL == p)
    {
        perror("create err"); // 打印前面函数的错误信息
        return NULL;          // 错误返回
    }
    // 2.初始化结构体空间
    p->last = -1;
    // 3.返回结构体空间地址
    return p;
}

int main(int argc, char const *argv[])
{
    seqlist_p p = CreateEpSeqlist();

    return 0;
}


 
作业：
1.吸收今天所学内容，代码至少敲3遍截图发群里。
2.把顺序表代码分文件编程实现，写个makefile管理
3.复习C语言
4.有能力的继续实现顺序表插入功能

录制文件：https://meeting.tencent.com/crm/Nbax7kR8a3 
录制文件：https://meeting.tencent.com/crm/Ke1obYG446 

3.1.5 分文件编程实现
seqlist.h
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define N 10
typedef int datatype;
typedef struct seqlist
{
    datatype data[N];
    int last;
} seqlist_t, *seqlist_p;

// 创建空顺序表
seqlist_p CreateEpSeqlist();
// 向顺序表的指定位置插入
int InsertIntoSeqlist(seqlist_p p, int post, int data);
// 判断顺序表是否为满，满返回1,未满返回0
int IsFullSeqlist(seqlist_p p);
// 遍历顺序表sequence顺序list表
void ShowSeqlist(seqlist_p p);
// 判断顺序表是否为空
int IsEpSeqlist(seqlist_p p);
// 删除顺序表中指定位置的数据，post为删除位置
int DeleteIntoSeqlist(seqlist_p p, int post);
// 修改指定位置上数据
int ChangePostSeqList(seqlist_p p, int post, int data);
// 查找指定数据出现的位置,返回下标，未找到返回-1
int SearchDataSeqList(seqlist_p p, int data);
#endif

 
seqlist.c
#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

// 创建空顺序表 create：创建 empty:空的 seqlist:顺序表
seqlist_p CreateEpSeqlist()
{
    // 1.动态申请顺序表类型空间
    seqlist_p p = (seqlist_p)malloc(sizeof(seqlist_t));
    if (NULL == p)
    {
        perror("create err"); // 打印前面函数的错误信息
        return NULL;          // 错误返回
    }
    // 2.初始化结构体空间
    p->last = -1; // 有效元素个数为0，所以有效元素下标为0-1=-1
    // 3.返回结构体空间地址
    return p;
}

// 判断顺序表是否为满，满返回1,未满返回0，full:满的
int IsFullSeqlist(seqlist_p p)
{
    return p->last + 1 == N;
}

// 向顺序表的指定位置插入
int InsertIntoSeqlist(seqlist_p p, int post, int data)
{
    // 容错判断
    if (IsFullSeqlist(p) || post < 0 || post > p->last + 1)
    {
        printf("insert err\n");
        return -1; // 错误返回
    }
    // 从最后一个元素开始到插入位置元素往后移动一个单位
    for (int i = p->last; i >= post; i--)
        p->data[i + 1] = p->data[i];
    // 存入数据
    p->data[post] = data;
    // 让last加一让有效元素下标多一个
    p->last++;
    return 0;
}

// 遍历顺序表sequence顺序list表
void ShowSeqlist(seqlist_p p)
{
    for (int i = 0; i <= p->last; i++)
        printf("%d ", p->data[i]);
    printf("\n");
}

// 判断顺序表是否为空 empty:空的
int IsEpSeqlist(seqlist_p p)
{
    return p->last == -1;
}

// 删除顺序表中指定位置的数据，post为删除位置
int DeleteIntoSeqlist(seqlist_p p, int post)
{
    // 1.容错判断
    if (IsEpSeqlist(p) || post < 0 || post > p->last)
    {
        printf("delete err\n");
        return -1;
    }
    // 2.将删除位置后一个元素开始到最后一个元素往前移动一个单位
    for (int i = post + 1; i <= p->last; i++)
        p->data[i - 1] = p->data[i];
    // 3.让last减一
    p->last--;
    return 0;
}

// 修改指定位置上数据， change:改变
int ChangePostSeqList(seqlist_p p, int post, int data)
{
    // 1.容错判断
    if (IsEpSeqlist(p) || post < 0 || post > p->last)
    {
        printf("change err\n");
        return -1;
    }
    // 2. 修改指定位置数据
    p->data[post] = data;

    return 0;
}

// 查找指定数据出现的位置,返回下标，未找到返回-1, search:查找
int SearchDataSeqList(seqlist_p p, int data)
{
    for (int i = 0; i <= p->last; i++)
    {
        if (p->data[i] == data)
            return i;
    }
    return -1; // 没找到返回-1
}

 
main.c
#include <stdio.h>
#include "seqlist.h"

int main(int argc, char const *argv[])
{
    seqlist_p p = CreateEpSeqlist();
    InsertIntoSeqlist(p, 0, 1);
    InsertIntoSeqlist(p, 1, 2);
    InsertIntoSeqlist(p, 2, 3);
    ShowSeqlist(p); // 1 2 3
    DeleteIntoSeqlist(p, 1);
    ShowSeqlist(p); // 1 3
    ChangePostSeqList(p, 1, 100);
    ShowSeqlist(p); // 1 100
    printf("下标:%d\n", SearchDataSeqList(p, 1000));
    return 0;
}

 
makefile
CC=gcc
CFLAGS=-c -Wall
OBJS=main.o seqlist.o
seqlist:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) $< -o $@
.PHONY:clean
clean:
	$(RM) seqlist *.o

顺序表特点：
1.顺序表的内存空间连续。
2.顺序表长度固定。
3.在顺序表中插入或删除时都涉及到元素的移动，效率较低; 查找和修改效率较高。
  

3.2 链表
链表又称单链表、链式存储结构，用于存储逻辑关系为“一对一”的数据。
和顺序表不同同，使用链表存储数据，不强制要求数据在内存中集中存储，各个元素可以分散存储在内存中。


链表存储数据间逻辑关系的实现方案是：为每一个元素配置一个指针，每个元素的指针都指向自己的直接后继元素，如下图所示：



所以在链表中，每个数据元素可以配有一个指针用于找到下一个元素即节点，这意味着，链表上的每个“元素”都长下图这个样子：


3.2.1 链表的特性
逻辑结构：线性结构
存储结构：链式存储结构
特点：内存不连续，通过指针链接。
操作：增删改查
struct node_t
{
    int data;  //数据域
    struct node_t *next;  //指针域
};

 
3.2.2 单向链表
有头链表: 存在一个头节点，头节点指针域有效，数据域无效。
无头链表: 每一个节点的数据域和指针域都有效。

遍历无头单向链表
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

    // 3.定义一个头指针(用于遍历链表)，指向第一个节点
    link_node_p p = &A;

    // 4. 遍历无头单向链表
    while (p != NULL)
    {
        printf("%c ", p->data); // a b c d
        p = p->next;
    }
    printf("\n");

    return 0;
}
 


遍历有头单向链表
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

 


链表尾插法练习
写一个有头单向链表，用于保存输入的学生成绩，实现一输入学生成绩就创建一个新的节点，将成绩保存起来。再将该节点链接到链表的尾，直到输入-1结束。
要求：每个链表的节点由动态内存分配得到 , 也就是用malloc。
过程：
1.malloc申请空间link_node_t大小作为头节点
2.将新节点放到链表尾部



#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node_t
{
    datatype data;
    struct node_t *next;
} link_node_t, *link_node_p;

int main(int argc, char const *argv[])
{
    int score;
    link_node_p ptail = NULL; // 尾指针，记录链表尾节点
    link_node_p pnew = NULL;  // 记录新节点
    // 1. 创建头节点，数据域无效，指针域置空
    link_node_p p = (link_node_p)malloc(sizeof(link_node_t));
    if (NULL == p)
    {
        perror("p malloc err");
        return -1;
    }
    // 初始化头节点
    p->next = NULL;
    // 让尾指针指向头节点
    ptail = p;

    // 2. 循环输入学生成绩直到-1结束，创建新节点保存学生成绩，链接到链表尾部。
    while (1)
    {
        scanf("%d", &score);
        if (score == -1)
            break;
        // 1).新建节点
        pnew = (link_node_p)malloc(sizeof(link_node_t));
        if (NULL == pnew)
        {
            perror("pnew malloc err");
            return -1;
        }
        // 2).初始化新节点，数据域存放学生成绩，指针域置空
        pnew->data = score;
        pnew->next = NULL;
        // 3).将新节点链接到链表尾部
        ptail->next = pnew;
        // 4).移动尾指针到新节点
        ptail = pnew;
    }
    // 3. 遍历链表
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");

    return 0;
}

 


作业：
1.吸收今天所学内容代码至少敲2遍截图发群里。
2.视频作业: 同位互相讲解各个模块逻辑，汇总到组长群。

录制文件：https://meeting.tencent.com/crm/KPLVmO8W8e 

有头链表的函数操作
linklist.h
#ifndef __LINKLIST_H__
#define __LINKLIST_H__
typedef int datatype;
typedef struct node_t
{
    datatype data;
    struct node_t *next;
} link_node_t, *link_node_p;

// 创建一个空的有头单向链表
link_node_p createEmptyLinkList();
// 计算链表的长度。
int lengthLinkList(link_node_p p);
// 链表指定位置插入数据
int insertIntoPostLinkList(link_node_p p, int post, datatype data);
// 遍历单向链表
void showLinkList(link_node_p p);
// 删除单向链表中指定位置的数据 post 代表的是删除的位置
int deletePostLinkList(link_node_p p, int post);
// 判断链表是否为空
int isEmptyLinkList(link_node_p p);
// 清空单向链表
void clearLinkList(link_node_p p);
//查找指定数据出现的位置 data被查找的数据 //search 查找
int searchDataLinkList(link_node_p p, datatype data);
//修改链表中指定的数据
int changePostLinkList(link_node_p p, int post, datatype data);
//删除单向链表中出现的指定数据,data代表将单向链表中出现的所有data数据删除
int deleteDataLinkList(link_node_p p, datatype data);
// 转置链表
void reverseLinkList(link_node_p p);

#endif

 
linklist.c
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// 创建一个空的有头单向链表
link_node_p createEmptyLinkList()
{
    // 1.开辟头节点空间
    link_node_p p = (link_node_p)malloc(sizeof(link_node_t));
    if (NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    // 2. 初始化头节点
    p->next = NULL;
    // 3.返回头节点地址
    return p;
}

// 计算链表的长度。
int lengthLinkList(link_node_p p)
{
    int len = 0;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 链表指定位置插入数据
int insertIntoPostLinkList(link_node_p p, int post, datatype data)
{
    // 1. 容错判断
    if (post < 0 || post > lengthLinkList(p))
    {
        printf("insert err\n");
        return -1;
    }
    // 2. 新建节点并初始化
    link_node_p pnew = (link_node_p)malloc(sizeof(link_node_t));
    if (NULL == pnew)
    {
        perror("pnew malloc err");
        return -1;
    }
    pnew->data = data;

    // 3.将指针p(形参)移动到插入节点的前一个位置(不会影响主函数的头指针p,因为动的是形参)
    for (int i = 0; i < post; i++)
        p = p->next;

    // 4. 链接新节点到链表
    pnew->next = p->next;
    p->next = pnew;

    return 0;
}

// 遍历单向链表
void showLinkList(link_node_p p)
{
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}

int isEmptyLinkList(link_node_p p)
{
    return p->next == NULL;
}

// 删除单向链表中指定位置的数据 post 代表的是删除的位置
int deletePostLinkList(link_node_p p, int post)
{
    // 1.容错判断
    if (isEmptyLinkList(p) || post < 0 || post >= lengthLinkList(p))
    {
        printf("delete err\n");
        return -1;
    }
    // 2.将指针p移动到删除位置前一个节点
    for (int i = 0; i < post; i++)
        p = p->next;
    // 3.设指针pdel记录要删除节点
    link_node_p pdel = p->next;
    // 4.前后跨过要删除节点
    p->next = pdel->next;
    // 5.释放要删除节点
    free(pdel);

    return 0;
}

// 清空单向链表, clear:清除
// 思想：循环删除头节点的后一个节点，直到链表为空
void clearLinkList(link_node_p p)
{
    link_node_p pdel = NULL;
    while (p->next != NULL)
    {
        pdel = p->next;
        p->next = pdel->next;
        free(pdel);
    }
}

// 查找指定数据出现的位置 data被查找的数据 //search 查找
int searchDataLinkList(link_node_p p, datatype data)
{
    int post = 0; // 记录查找的位置
    // 遍历有头链表
    while (p->next != NULL)
    {
        p = p->next;
        if (p->data == data)
            return post;
        post++;
    }
    return -1; // 没找到返回-1
}

// 修改链表中指定的数据
int changePostLinkList(link_node_p p, int post, datatype data)
{
    // 1.容错判断
    if (isEmptyLinkList(p) || post < 0 || post >= lengthLinkList(p))
    {
        printf("change err\n");
        return -1;
    }
    // 2. 将指针移动到要修改节点
    for (int i = 0; i <= post; i++)
        p = p->next;
    // 3. 修改节点中数据
    p->data = data;

    return 0;
}

// 删除单向链表中出现的指定数据,data代表将单向链表中出现的所有data数据删除
// 思想：利用两个指针，保证p一直在q前面，q相当于即用于遍历又用于删除操作。删除之后别忘了让q继续指向p的下一个节点用来继续向后遍历。
int deleteDataLinkList(link_node_p p, datatype data)
{
    // 先跨过头节点
    link_node_p q = p->next;
    // 相当于用q遍历无头单向链表
    while (q != NULL)
    {
        if (q->data == data) // 判断是否是要删除的节点
        {
            // 1. 删除节点
            //(1) 让p跨过q指向的要删除节点
            p->next = q->next;
            //(2) 释放要删除节点
            free(q);
            // 2. 让q指向p的下一个节点继续向后遍历
            q = p->next;
        }
        else // 继续遍历
        {
            // 让q和p都向后移动一个单位
            q = q->next;
            p = p->next;
        }
    }
    return 0;
}

// 转置链表
void reverseLinkList(link_node_p p)
{
    link_node_p t = NULL;    // 为了临时保存节点，不然头插完链表找不到了
    link_node_p q = p->next; // 保存头节点的后一个节点
    p->next = NULL;          // 断开头节点
    while (q != NULL)        // 相当于遍历无头单向链表，进行头插
    {
        // 让t记录q的下一个节点(不然头插完之后就找不到链表了)
        t = q->next;
        // 头插: 先连后面再连前面，把q插到p后面
        q->next = p->next;
        p->next = q;
        // 让q找t
        q = t;
    }
}

 
main.c
#include <stdio.h>
#include "linklist.h"

int main(int argc, char const *argv[])
{
    link_node_p p = createEmptyLinkList();
    for (int i = 0; i < 3; i++)
        insertIntoPostLinkList(p, i, i + 1);
    showLinkList(p); // 1 2 3

    reverseLinkList(p);
    showLinkList(p); //3 2 1 

    deletePostLinkList(p, 1);
    showLinkList(p); // 1 3
    printf("post: %d\n", searchDataLinkList(p, 2));  //-1

    changePostLinkList(p, 1, 100);
    showLinkList(p); // 1 100
    insertIntoPostLinkList(p, 2, 1);
    showLinkList(p); // 1 100 1
    deleteDataLinkList(p, 1);
    showLinkList(p); // 100

    // clearLinkList(p);
    // if (isEmptyLinkList(p))
    //     printf("empty!\n");
    return 0;
}


 
makefile
CC=gcc
CFLAGS=-c -Wall
OBJS=main.o linklist.o
linklist:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) $< -o $@
.PHONY:clean
clean:
	$(RM) linklist *.o


按指定位置插入节点： 

按指定位置删除节点:

按数据删除节点: 


转置：


作业：
1.吸收今天所学内容，代码至少敲2遍，复习顺序表代码敲去遍。
2.录制视频互相讲解各个模块逻辑汇总组长群。
3.尽力实现链表转置
4.复习函数内开辟堆区空间的方法(返回值和二级指针)
录制文件：https://meeting.tencent.com/crm/2pQpkqzxdd 

3.2.3单向循环链表
约瑟夫环问题，是一个经典的循环链表问题，题意是：已知 n 个人（分别用编号 1，2，3，…，n 表示）围坐在一张圆桌周围，从编号为 k 的人开始顺时针报数，数到 m 的那个人出列；他的下一个人又从 1 开始，还是顺时针开始报数，数到 m 的那个人又出列；依次重复下去，直到圆桌上剩余一个人。
 
用解决约瑟夫环问题进行杀猴子：
思想：用头指针移动到要杀的猴子的前一个，然后跨过指向猴子的节点。
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node_t
{
	int data;
	struct node_t *next;
}link_node_t,*link_node_p;

int main(int argc, const char *argv[])
{
	int i;
	link_node_p pdel = NULL;//用于指向被删除节点
	link_node_p ptail = NULL;//永远指向当前链表的尾 
	link_node_p pnew = NULL;//永远指向新创建的节点
	link_node_p h = NULL;
	int all_num = 7;//猴子总数 
	int start_num = 2; //从几号猴子开始数
	int kill_num = 3;//数到几杀死猴
	printf("请您入猴子总数 起始号码 数到几杀死:\n");
	scanf("%d%d%d",&all_num,&start_num,&kill_num);
	//1.创建出一个单向循环链表
	//(1)创建有all_num个节点的单向链表
	h = (link_node_p)malloc(sizeof(link_node_t));
	if(NULL == h)
	{
		perror("malloc failed");
		return -1;
	}
	h->data = 1;
	h->next = NULL;
	ptail = h;//尾指针指向当前的第一个节点
	for(i = 2; i <= all_num; i++)
	{
		//创建新的节点
		pnew = (link_node_p)malloc(sizeof(link_node_t));
		if(NULL == pnew)
		{
			perror("malloc failed");
			return -1;
		}
		//将新节点装上数据
		pnew->data = i;
		pnew->next = NULL;
		//将新节点链接到链表尾 
		ptail->next = pnew;//链接到链表的尾
		ptail = pnew;//尾指针继续指向当前链表的尾 
	}
	//(2)将头指针保存到链表的尾形成单向循环链表
	ptail->next = h;//形成单向循环链表 
#if 0 //用于调试程序
	while(1)
	{
		printf("%d\n",h->data);
		h = h->next;
		sleep(1);
	}
#endif
	//2.开始杀猴子 
	//(1)将头指针移动到开始猴子的号码处 
	for(i = 1; i < start_num; i++)
		h = h->next;
        printf("start :%d\n",h->data);
	//(2)循环进行杀猴子
	while(h != h->next)//条件不成的时候，就剩一个猴子,只有一个节点
	{
		//将头指针移动到即将删除节点的前一个节点
		for(i = 1; i < kill_num-1; i++)
			h = h->next;

		pdel = h->next;
		//跨过删除节点
		h->next = pdel->next;
		printf("kill is -------------%d\n",pdel->data);
		free(pdel);
		pdel = NULL;
		//杀死猴子猴，从下一个节点开始继续开始数,将头指针移动到开始数的地方
		h = h->next;
	}
	printf("king is=================== %d\n",h->data);
	return 0;
}	


 
总结：顺序表和链表的区别?
(1)顺序表是顺序存储结构，内存连续，通过数组实现； 链表是链式存储结构，内存不连续，通过指针链接。
(2)顺序表长度固定；链表长度不固定。
(3)顺序表查找和修改可以通过下标找到对应的元素效率高一些，但是插入和删除涉及到元素的移动效率低一些；链表是插入和删除效率高，查找和修改效率低。
(4)顺序表元素占用空间相对较小；链表元素占用空间相对较大，因为还有一个指针域。

笔试题： 1. 关于链表，描述不正确的选项是（）（鲁科安全）
[A] 在运行期间可以动态添加
[B] 物理空间不连续，空间开销大
[C] 查找元素不需要顺序查找
[D] 可以在任意节点位置插入元素
答案: C

2.若频繁的对线性表进行插入和删除操作，宜采用__ 链表____; 该存储结构特特点是利用___指针__来表示数据元素之间的逻辑关系。（鲁科安全）

3.给定一个链表，编程实现链表反转 (请写到背面) (中航安为) (H3CC语言题目 南京)(上海诺行信息技术有限公司)

3.3 栈 stack
3.3.1什么是栈

栈是只能在一端进行插入和删除操作的线性表(又称为堆栈)，进行插入和删除操作的一端称为栈顶，另一端称为栈底。
特点：栈是先进后出FILO(First In Last Out)
或者后进先出LIFO(Last In First Out)

3.3.2 顺序栈
特性
逻辑结构：线性结构
存储结构：顺序存储结构
操作: 创建、入栈、出栈、判空、判满

代码实现
创空:

入栈：

出栈:


seqstack.h
#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

typedef int datatype;
typedef struct seqstack // 顺序栈结构体
{
    datatype *data; // 指向栈的存储空间的指针
    int maxlen;     // 栈的最大长度(数组元素最大个数)
    int top;        // 栈顶节点下标(相当于之前顺序标的last)
} seqstack_t, *seqstack_p;

// 创建空顺序栈,len代表创建栈的空间的最大长度
seqstack_p createEmptySeqStack(int len);

// 入栈,data代表入栈的数据
int pushStack(seqstack_p p, datatype data);

// 判断是否为满,满返回1 未满返回0
int isFullSeqStack(seqstack_p p);

// 判断栈是否为空
int isEmptySeqStack(seqstack_p p);

// 出栈
int popSeqStack(seqstack_p p);


// 求栈的长度
int lengthSeqStack(seqstack_p p);

#endif

 
seqstack.c
#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"

// 创建空顺序栈,len代表创建栈的空间的最大长度
seqstack_p createEmptySeqStack(int len)
{
    // 1. 开辟顺序栈结构体大小空间
    seqstack_p p = (seqstack_p)malloc(sizeof(seqstack_t));
    if (NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    // 2. 初始化顺序栈结构体
    p->data = (datatype *)malloc(sizeof(datatype) * len);
    if (NULL == p->data)
    {
        perror("data malloc err");
        return NULL;
    }
    p->maxlen = len;
    p->top = -1; // 类似于之前顺序表last表示最后一个有效元素下标，此时有效元素个数为0，所以下标就是0-1=-1

    // 3.返回栈的地址
    return p;
}

// 判断是否为满,满返回1 未满返回0
int isFullSeqStack(seqstack_p p)
{
    return p->top + 1 == p->maxlen;
}

// 入栈,data代表入栈的数据
int pushStack(seqstack_p p, datatype data)
{
    // 1. 判满: p->top+1 == p->maxlen
    if (isFullSeqStack(p))
    {
        printf("push err\n");
        return -1;
    }
    // 2. 将top往上移动一个单位
    p->top++;
    // 3. 将数据存入
    p->data[p->top] = data;
    return 0;
}

// 判断栈是否为空
int isEmptySeqStack(seqstack_p p)
{
    return p->top == -1;
}

// 出栈
int popSeqStack(seqstack_p p)
{
    // 1. 判空: p->top==-1;
    if (isEmptySeqStack(p))
    {
        printf("pop err\n");
        return -1;
    }
    // 2. 让top减一
    p->top--;
    // 3. 返回出栈数据(也就是此时top+1位置数据)
    return p->data[p->top + 1];
}

// 求栈的长度
int lengthSeqStack(seqstack_p p)
{
    return p->top + 1;
}

 
main.c
#include <stdio.h>
#include "seqstack.h"
int main(int argc, char const *argv[])
{
    seqstack_p p = createEmptySeqStack(5);

    for (int i = 1; i <= 6; i++)
        pushStack(p, i);
    // 最后一次会报push err，因为已经满了不能再入栈了

    printf("len=%d\n", lengthSeqStack(p)); //len=5

    while (!isEmptySeqStack(p))
        printf("%d\n", popSeqStack(p));
    // 5 4 3 2 1 后进先出
    return 0;
}


 
练习：
软通动力校园招聘笔试题
1. 若进栈顺序为 1,2,3,4 一下四种情况不可能出现的出栈序列是( ) 
 	A.  1,4,3,2    //入1 出1 入234出4 出3 出2
 	B.  2,3,4,1     //入1 2 出 2 入3 出3 入4 出4 出1
 	C.  3,1,4,2
 	D.  3,4,2,1  //入1 2 3 出3 入4出4 出2 出1 
2.下列叙述正确的是(  )
A. 线性表是线性结构
B. 栈与队列是非线性结构
C. 线性链表是非线性结构 
D.二叉树是线性结构

3. 下列关于栈叙述正确的是( )
    A.在栈中只能插入数据
    B.在栈中只能删除数据
    C.栈是先进先出的线性表
    D.栈是先进后出的线性表

4.请问下面的程序有问题吗？如果有问题在哪儿？
#include <stdio.h>
#include <stdlib.h>

void get_mem(int *q) //q=NULL
{
    q = (int *)malloc(sizeof(int)); //修改q的指向到堆区，不会影响主函数的p。并且开辟的空间不够。
}

int main(int argc, char const *argv[])
{

    int i;
    int *p = NULL;
    get_mem(p); //函数调用后p还是指向NULL，后面访问NULL所以段错误
    /* 该函数调用逻辑等同于: 
    int *q=p;
    q=malloc()
    */
    for (i = 0; i < 10; i++)
        p[i] = i;

    for (i = 0; i < 10; i++)
        printf("%d\n", p[i]);

    free(p);

    return 0;
}


错误：相当于值传递，修改函数的形参不会影响主函数的p。并且开辟空间大小不够用。

修改：可以通过传递二级指针或者返回值。
#include <stdio.h>
#include <stdlib.h>

void get_mem(int **q)  //q=&p
{
    *q = (int *)malloc(sizeof(int)*10); //*q=*&p=p
}

int main(int argc, char const *argv[])
{

    int i;
    int *p = NULL;
    get_mem(&p);  //函数调用结束后p真的指向堆区了
    /* 该函数调用的逻辑相当于:
    int **q=&p;
    *q=malloc();
    */
    for (i = 0; i < 10; i++)
        p[i] = i;

    for (i = 0; i < 10; i++)
        printf("%d\n", p[i]);

    free(p);

    return 0;
}

 
3.3.2 链式栈
特性
逻辑结构：线性结构
存储结构：链式存储结构
操作：创建、入栈、出栈、判空
顺序栈和链式栈的区别：存储结构不同，实现的方式也不同，顺序栈用顺序表也就是数组实现，而链式用链表实现。

代码实现
入栈：


出栈:


linkstack.h
#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

typedef int datatype;
typedef struct linkstack
{
    datatype data;
    struct linkstack *next;

} linkstack_t, *linkstack_p;
// 创建空链式栈
void createEmptyLinkStack(linkstack_t **p);

// 入栈, data是入栈的数据
int pushLinkStack(linkstack_t **ptop, datatype data);

// 判断栈是否为空
int isEmptyLinkStack(linkstack_t *top);

// 出栈
datatype popLinkStack(linkstack_t **ptop);

//求栈的长度
int lengthLinkStack(linkstack_t *top);
#endif

 
linkstack.c
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

// 创建空链式栈
void createEmptyLinkStack(linkstack_t **p) // p=&top
{
    *p = NULL; //*p=*&top=top
}

// 入栈, data是入栈的数据
// 需要传递二级指针，因为要改变栈顶指针top,所以需要传递&top，函数内通过*ptop找到top来修改其指向，本质是地址传递
int pushLinkStack(linkstack_t **ptop, datatype data)
{
    // 1. 创建新节点存入数据
    linkstack_p pnew = (linkstack_p)malloc(sizeof(linkstack_t));
    if (NULL == pnew)
    {
        perror("pnew err");
        return -1;
    }
    pnew->data = data;
    // 2. 链接新节点到链表
    pnew->next = *ptop;
    // 3. 让top指向新节点
    *ptop = pnew; //*ptop就是top
    return 0;
}

// 判断栈是否为空
int isEmptyLinkStack(linkstack_t *top)
{
    return top == NULL;
}

// 出栈
datatype popLinkStack(linkstack_t **ptop)
{
    // 1. 判空：top==NULL
    if (isEmptyLinkStack(*ptop))
    {
        printf("pop err\n");
        return -1;
    }
    // 2. 指针pdel保存要删除的节点
    linkstack_p pdel = *ptop;
    // 3. 设变量temp保存要出栈数据
    datatype temp = (*ptop)->data; // temp=pdel->data;
    // 4. 将top往后移动一个单位
    *ptop = (*ptop)->next; //*ptop=pdel->next;
    // 5. 释放要删除的节点
    free(pdel);
    // 6. 返回出栈数据
    return temp;
}

// 求栈的长度
int lengthLinkStack(linkstack_t *top)
{
    int len = 0;
    while (top != NULL)
    {
        len++;
        top = top->next;
    }
    return len;
}


 
main.c
#include <stdio.h>
#include "linkstack.h"

int main(int argc, char const *argv[])
{
    linkstack_p top;
    createEmptyLinkStack(&top); // top = NULL;
    for (int i = 1; i < 6; i++)
        pushLinkStack(&top, i);

    printf("len=%d\n", lengthLinkStack(top));  //len=5

    while (!isEmptyLinkStack(top))
    {
        printf("%d\n", popLinkStack(&top));
        // 5 4 3 2 1
    }

    return 0;
}

 

3.4 队列 Queue
3.4.1 什么是队列
队列是只允许再两端进行插入和删除操作的线性表，在队尾插入，在队头删除，插入的一段被称为“队尾”，删除的一端被称为“队头”。队列包括顺序队列(循环队列)、链式队列。
结构：先进先出FIFO 
操作：创建、入列、出列、判断是否为空、判断是否为满、清空。


3.4.2 循环队列
逻辑结构：线性结构
存储结构：顺序存储结构
操作: 创建、入列、出列、判空、判满

作业：
1.吸收今天所学内容，代码至少2遍，截图。
2.录制视频：画图讲解各个模块逻辑
VIP： 录制视频顺序表和链表代码遍敲遍讲

录制文件：https://meeting.tencent.com/crm/2pQ37yZBfb 


代码实现
入队：


出队：


长度：

sequeue.h
#ifndef __SEQUEUE_H__
#define __SEQUEUE_H__
#define N 6
typedef int datatype;
typedef struct // 循环队列结构体
{
    datatype data[N];
    int rear;  // 队尾节点下标
    int front; // 队头节点下标
} sequeue_t, *sequeue_p;
//循环队列中，假设数组元素个数为N，那么循环队列中最多存入数据个数为N-1，因为牺牲了一个元素用于判满。

// 创建一个空的队列
sequeue_t *createEmptySequeue();

// 判断队列是否为满
int isFullSequeue(sequeue_p p);

// 入列 data代表入列的数据
int inSequeue(sequeue_p p, datatype data);

//判断队列是否为空
int isEmptySequeue(sequeue_p p);

// 出列
datatype outSequeue(sequeue_p p);

// 求队列长度
int lengthSequeue(sequeue_p p);


#endif

 
sequeue.c
#include <stdio.h>
#include <stdlib.h>
#include "sequeue.h"

// 创建一个空的队列
sequeue_p createEmptySequeue()
{
    // 1.开辟队列结构体空间
    sequeue_p p = (sequeue_p)malloc(sizeof(sequeue_t));
    if (NULL == p)
    {
        perror("create err");
        return NULL;
    }
    // 2.初始化结构体空间
    p->front = 0;
    p->rear = 0;

    // 3.返回地址
    return p;
}

// 判断队列是否为满
int isFullSequeue(sequeue_p p)
{
    return (p->rear + 1) % N == p->front;
}

// 入列 data代表入列的数据
int inSequeue(sequeue_p p, datatype data)
{
    // 1. 判满: (尾巴+1)%N==头
    if (isFullSequeue(p))
    {
        printf("in err\n");
        return -1;
    }
    // 2. 将数据存入
    p->data[p->rear] = data;
    // 3. 将尾往后移动一个单位
    p->rear = (p->rear + 1) % N;

    return 0;
}

// 判断队列是否为空
int isEmptySequeue(sequeue_p p)
{
    return p->front == p->rear;
}

// 出列
datatype outSequeue(sequeue_p p)
{
    // 1. 判空: 头==尾
    if (isEmptySequeue(p))
    {
        printf("out err\n");
        return -1;
    }
    // 2. 设临时变量temp保存出队数据
    datatype temp = p->data[p->front];
    // 3. 将front往后移动一个单位(同入队)
    p->front = (p->front + 1) % N;
    // 4. 返回出队数据
    return temp;
}

// 求队列长度
int lengthSequeue(sequeue_p p)
{
    return (p->rear - p->front + N) % N;
}

 
main.c
#include <stdio.h>
#include "sequeue.h"

int main(int argc, char const *argv[])
{
    sequeue_p p = createEmptySequeue();
    for (int i = 1; i <= 6; i++)
        inSequeue(p, i);
    // 最后一次调用报in err，因为已经满了

    printf("len = %d\n",lengthSequeue(p));

    while (!isEmptySequeue(p))
        printf("%d\n", outSequeue(p));
    // 1 2 3 4 5先进先出
    return 0;
}


 
循环队列，如果数组元素个数为N，那么队列中最多可以存储多少个数据?
N-1
为什么?
答：因为在入队时需要先判满，判满我们用的方法是如果尾的下一个和同相等就是满，那么会舍弃掉一个元素空间用于判满。

3.4.3 链式队列
逻辑结构：线性结构
存储结构：链式存储结构
操作：创建、入列、出列、判空

代码实现
可以通过把头指针和尾指针封装成一个结构体实现，因此需要两个结构体，一个是来年表节点的结构体，另一个就是头尾指针的结构体。有了头尾指针结构体，就能操作整个链式队列。

创空:


入队： 还是和之前尾插方法一样


出队: 


linkqueue.h
#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__
typedef int datatype;
// 链表节点结构体
typedef struct node_t
{
    datatype data;
    struct node_t *next;
} link_node_t, *link_node_p;

// 队列结构体
typedef struct
{
    link_node_p front; // 队列头指针
    link_node_p rear;  // 队列尾指针
} linkqueue_t, *linkqueue_p;

// 创建一个空的链式队列
linkqueue_p createEmptyLinkQueue();
// 入列 data代表入列的数据
int inLinkQueue(linkqueue_p p, datatype data);
// 判断队列是否为空
int isEmptyLinkQueue(linkqueue_p p);
// 出列
datatype outLinkQueue(linkqueue_p p);
// 求队列长度的函数
int lengthLinkQueue(linkqueue_p p);
#endif
 

linkqueue.c
#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

// 创建一个空的链式队列
linkqueue_p createEmptyLinkQueue()
{
    // 1.开辟队列结构体大小空间
    linkqueue_p p = (linkqueue_p)malloc(sizeof(linkqueue_t));
    if (NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    // 2.初始化队列结构体
    p->front = p->rear = (link_node_p)malloc(sizeof(link_node_t));
    if (NULL == p->front)
    {
        perror("p->front err");
        return NULL;
    }
    // 3.初始化头节点
    p->front->next = NULL;

    // 4. 返回队列地址
    return p;
}

// 入列 data代表入列的数据
int inLinkQueue(linkqueue_p p, datatype data)
{
    // 1. 新建节点并初始化
    link_node_p pnew = (link_node_p)malloc(sizeof(link_node_t));
    if (NULL == pnew)
    {
        perror("pnew err");
        return -1;
    }
    pnew->data = data;
    pnew->next = NULL;
    // 2. 将新节点链接到链表(尾插)
    p->rear->next = pnew;
    // 3. 移动尾指针到新节点
    p->rear = pnew;

    return 0;
}

// 判断队列是否为空
int isEmptyLinkQueue(linkqueue_p p)
{
    return p->front == p->rear;
}

// 出列
datatype outLinkQueue(linkqueue_p p)
{
    // 1.判空
    if (isEmptyLinkQueue(p))
    {
        printf("out err\n");
        return -1;
    }
    // 2.将pdel指向要释放的节点
    link_node_p pdel = p->front;
    // 3. 将头指针向后移动一个单位(为了做新的头节点)
    p->front = p->front->next;
    // 4. 释放pdel所指节点
    free(pdel);
    // 5. 返回此时头指针所指节点中的数据
    return p->front->data;
}

// 求队列长度的函数
int lengthLinkQueue(linkqueue_p p)
{
    int len = 0;
    link_node_p t = p->front; // 不能真的动头指针，所以再设一个指针遍历链表求长度
    while (t->next != NULL)
    {
        len++;
        t = t->next;
    }
    return len;
}

 
main.c
#include <stdio.h>
#include "linkqueue.h"

int main(int argc, char const *argv[])
{
    linkqueue_p p = createEmptyLinkQueue();
    for (int i = 1; i < 6; i++)
        inLinkQueue(p, i);

    printf("len=%d\n", lengthLinkQueue(p));

    while (!isEmptyLinkQueue(p))
        printf("%d\n", outLinkQueue(p));
    // 1 2 3 4 5先进先出
    return 0;
}

 
3.5 双向链表


逻辑结构：线性结构
存储结构：链式存储结构
操作：增删改查

代码实现
封装结构体：可以用两个结构体，思想上有点像链式队列。
  
插入：


删除：

按数据删除：


doublelist.h
#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__
typedef int datatype;
typedef struct node_t // 节点结构体
{
    datatype data;        // 数据域
    struct node_t *next;  // 后继指针
    struct node_t *prior; // 前驱指针
} link_node_t, *link_node_p;

// 封装头尾指针和长度的结构体
// 思想上像链式队列
typedef struct
{
    link_node_p head; // 头指针
    link_node_p tail; // 尾指针
    int len;          // 链表长度
} double_list_t, *double_list_p;

// 创建一个空的双向链表
double_list_p createEmptyDoubleLinkList();

// 向双向链表的指定位置插入数据 post位置， data数据
int insertIntoDoubleLinkList(double_list_p p, int post, datatype data);

// 遍历双向链表
void showDoubleLinkList(double_list_p p);

// 判断链表是否为空
int isEmptyDoubleLinkList(double_list_p p);

// 删除双向链表指定位置数据
int deletePostDoubleLinkList(double_list_p p, int post);

// 查找指定数据出现的位置,没找到返回-1 data被查找的数据
int searchPostDoubleLinkList(double_list_p p, datatype data);


// 修改指定位置的数据,post修改的位置 data被修改的数据
int changeDataDoubleLinkList(double_list_p p, int post, datatype data);
#endif

doublist.c
#include <stdio.h>
#include <stdlib.h>
#include "doublelinklist.h"

// 创建一个空的双向链表
double_list_p createEmptyDoubleLinkList()
{
    // 1.开辟双向链表结构体空间
    double_list_p p = (double_list_p)malloc(sizeof(double_list_t));
    if (NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    // 2.初始化上面的结构体
    p->head = p->tail = (link_node_p)malloc(sizeof(link_node_t));
    if (NULL == p->head)
    {
        perror("p->head err");
        return NULL;
    }
    p->len = 0;
    // 3.初始化头节点
    p->head->next = NULL;
    p->head->prior = NULL;

    return p;
}

// 向双向链表的指定位置插入数据 post位置， data数据
int insertIntoDoubleLinkList(double_list_p p, int post, datatype data)
{
    // 1. 容错判断
    if (post < 0 || post > p->len)
    {
        printf("insert err\n");
        return -1;
    }
    // 2. 新建一个节点，并初始化
    link_node_p pnew = (link_node_p)malloc(sizeof(link_node_t));
    if (NULL == pnew)
    {
        perror("pnew err");
        return -1;
    }
    pnew->data = data;
    pnew->next = pnew->prior = NULL;

    // 3. 将新节点插入，分情况讨论：尾插还是中间插入
    if (post == p->len) // 尾插
    {
        //(1) 链接新节点到链表(两根)
        pnew->prior = p->tail;
        p->tail->next = pnew;
        //(2) 移动尾指针到新节点
        p->tail = pnew;
    }
    else // 中间插入
    {
        link_node_p temp;
        //(1) 将指针temp移动到插入位置，分前后半段
        if (post <= p->len / 2) // 前半段
        {
            temp = p->head;
            for (int i = 0; i <= post; i++)
                temp = temp->next;
        }
        else // 后半段
        {
            temp = p->tail;
            for (int i = p->len - 1; i > post; i--)
                temp = temp->prior;
        }
        //(2) 链接新节点到链表(4根，可以先前再后)
        pnew->prior = temp->prior;
        pnew->prior->next = pnew;
        pnew->next = temp;
        temp->prior = pnew;
    }
    // 4. 长度加一
    p->len++;
    return 0;
}

// 遍历双向链表
void showDoubleLinkList(double_list_p p)
{
    printf("正向遍历: ");
    link_node_p temp = p->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");

    printf("反向遍历: ");
    temp = p->tail;
    while (temp != p->head)
    {
        printf("%d ", temp->data);
        temp = temp->prior;
    }
    printf("\n");
}

// 判断链表是否为空
int isEmptyDoubleLinkList(double_list_p p)
{
    return p->len == 0;
}

// 删除双向链表指定位置数据
int deletePostDoubleLinkList(double_list_p p, int post)
{
    // 1.容错判断
    if (isEmptyDoubleLinkList(p) || post < 0 || post >= p->len)
    {
        printf("delete err\n");
        return -1;
    }
    // 2. 删除操作：尾删还是中间删除
    if (post == p->len - 1) // 尾删
    {
        //(1) 将尾指针往前移动一个单位
        p->tail = p->tail->prior;
        //(2) 释放要删除节点
        free(p->tail->next);
        //(3) 将此时尾指针所指节点置空
        p->tail->next = NULL;
    }
    else // 中间删除
    {
        link_node_p temp;
        //(1) 将指针temp移动到要删除节点，分前后半段（同插入）
        if (post <= p->len / 2) // 前半段
        {
            temp = p->head;
            for (int i = 0; i <= post; i++)
                temp = temp->next;
        }
        else // 后半段
        {
            temp = p->tail;
            for (int i = p->len - 1; i > post; i--)
                temp = temp->prior;
        }
        //(2) 前后跨过要删除节点
        temp->next->prior = temp->prior;
        temp->prior->next = temp->next;
        //(3) 释放要删除节点
        free(temp);
    }
    // 3.将长度减一
    p->len--;
    return 0;
}

// 查找指定数据出现的位置,没找到返回-1 data被查找的数据
int searchPostDoubleLinkList(double_list_p p, datatype data)
{
    link_node_p temp = p->head;
    int i = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->data == data)
            return i;
        i++;
    }
    return -1;
}

// 修改指定位置的数据,post修改的位置 data被修改的数据
int changeDataDoubleLinkList(double_list_p p, int post, datatype data)
{
    // 1.容错判断
    if (isEmptyDoubleLinkList(p) || post < 0 || post >= p->len)
    {
        printf("change err\n");
        return -1;
    }
    // 2. 设指针移动到要修改接待你位置：分前后半段
    link_node_p temp;
    if (post <= p->len / 2) // 前半段
    {
        temp = p->head;
        for (int i = 0; i <= post; i++)
            temp = temp->next;
    }
    else // 后半段
    {
        temp = p->tail;
        for (int i = p->len - 1; i > post; i--)
            temp = temp->prior;
    }
    // 3.修改节点数据
    temp->data = data;

    return 0;
}

// 删除双向链表中的指定数据 data代表删除所有出现的data数据
void deleteDataDoubleLinkList(double_list_p p, datatype data)
{
    link_node_p temp = p->head->next;
    while (temp != NULL) // 相当于遍历无头单向链表
    {
        if (temp->data == data) // 判断成功则删除节点,分尾删还是中间删除
        {
            if (temp == p->tail) // 尾删
            {
                //(1) 将尾指针往前移动一个单位
                p->tail = p->tail->prior;
                //(2) 将最后一个节点释放
                free(p->tail->next);
                //(3) 将此时尾指针所指节点的next置空
                p->tail->next = NULL;
                //(4) 将temp置空，出循环
                temp = NULL;
            }
            else // 中间删除
            {
                //(1) 指针pdel指向要删除的节点
                link_node_p pdel = temp;
                //(2) 将temp往后移动一个单位下次继续遍历
                temp = temp->next;
                //(3) 前后跨过要删除节点
                pdel->next->prior = pdel->prior;
                pdel->prior->next = pdel->next;
                //(4) 释放要删除节点
                free(pdel);
            }
            // 让长度减一
            p->len--;
        }
        else // temp往后移动一个单位
        {
            temp = temp->next;
        }
    }
}

main.c
#include <stdio.h>
#include "doublelinklist.h"

int main(int argc, char const *argv[])
{
    double_list_p p = createEmptyDoubleLinkList();

    insertIntoDoubleLinkList(p, 0, 1);
    insertIntoDoubleLinkList(p, 1, 2);
    insertIntoDoubleLinkList(p, 2, 3);
    insertIntoDoubleLinkList(p, 1, 100);

    showDoubleLinkList(p);
    deletePostDoubleLinkList(p, 3);
    showDoubleLinkList(p);

    printf("post:%d\n", searchPostDoubleLinkList(p, 100));

    changeDataDoubleLinkList(p, 1, 6);
    showDoubleLinkList(p);
    insertIntoDoubleLinkList(p, 3, 1);
    showDoubleLinkList(p); //1 6 2 1 
    deleteDataDoubleLinkList(p, 1); //6 2
    showDoubleLinkList(p);

    return 0;
}


   
作业：
1.吸收今天所学内容，代码至少敲两遍截图发群里。
2.VIP：链表和顺序表代码遍敲边讲。

录制文件：https://meeting.tencent.com/crm/2MDQapny4e 

3.6 双向循环
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node_t
{
	datatype data;
	struct node_t * prior;
	struct node_t * next;
}link_node_t,*link_node_p;

typedef struct doublelinklist
{
	link_node_p head;
	link_node_p tail;
}double_list_t,*double_list_p;

int main(int argc, const char *argv[])
{
	int i;
	int all_num = 8;//猴子总数
	int start_num = 3;//从3号猴子开始数
	int kill_num = 3;//数到几杀死猴子 
	link_node_p h = NULL;
	link_node_p pdel = NULL;//用来指向被杀死猴子的节点
	printf("请您输入猴子的总数，开始号码，出局号码:\n");
	scanf("%d%d%d",&all_num,&start_num,&kill_num);
	//1.创建一个双向的循环链表
	double_list_p p = (double_list_p)malloc(sizeof(double_list_t));//申请头指针和尾指针
	if(NULL == p)
	{
		perror("malloc failed");
		return -1;
	}
	p->head = p->tail = (link_node_p)malloc(sizeof(link_node_t));
	if(NULL == p->tail)
	{
		perror("p->tail malloc failed");
		return -1;
	}
	p->head->data = 1;
	p->head->prior = NULL;
	p->head->next = NULL;
	//将创建n个新的节点，链接到链表的尾
	for(i = 2; i <= all_num; i++)
	{
		link_node_p pnew = (link_node_p)malloc(sizeof(link_node_t));
		if(NULL == pnew)
		{
			perror("pnew malloc failed");
			return -1;
		}
		pnew->data = i;
		pnew->prior = NULL;
		pnew->next = NULL;
		//(1)将新的节点链接到链表的尾
		p->tail->next = pnew;
		pnew->prior = p->tail;
		//(2)尾指针向后移动，指向当前链表的尾
		p->tail = pnew;
	}
	//(3)形成双向循环链表 
	p->tail->next = p->head;
	p->head->prior = p->tail;
	//调试程序 
#if 0
	while(1)
	{
		printf("%d\n",p->head->data);
		p->head = p->head->next;
		sleep(1);
	}
#endif
	//2.循环进行杀死猴子
	h = p->head;
	//(1)先将h移动到start_num处，也就是开始数数的猴子号码处
	for(i = 1; i < start_num; i++)
		h = h->next;
        printf("start is:%d\n",h->data);
	while(h->next != h)//当h->next == h 就剩一个节点了，循环结束
	{
		//(2)将h移动到即将杀死猴子号码的位置
		for(i = 1; i < kill_num; i++)
			h = h->next;
		//(3)进行杀死猴子，经过上面的循环后，此时的h指向即将杀死的猴子
		h->prior->next = h->next;
		h->next->prior = h->prior;
		pdel = h;//pdel指向被杀死猴子的位置
		printf("kill is -------%d\n",pdel->data);
		h = h->next;//需要移动，从杀死猴子后的下一个位置开始数
		free(pdel);
	}
	printf("猴王是%d\n",h->data);
	return 0;
}	

 

请完成如下双向链表的删除过程: （云尖软件开发笔试试题）

A.p-> next=p->prior->next;
p->prior=p->next->prior;
free(p);
B. p->prior = p->next;
p->nest = p->prior;
free(p);
C. p->prior->next = p->next;
p->next >prior = p->prior:
free(p);
D.p->prior->next = p->next->prior;
p->next->prior=p->prior->next;
free(p);
答案: C


面试题：单向链表与双向（循环）链表的区别：
在存储空间方面：单链表需要的存储空间比双向链表的要少，因为双向链表不仅保存有指向下一个节点的指针，还保存有指向上一个节点的指针，需要较大的空间来存储双向链表的指针域。
在处理时间方面：双向链表的插入与删除操作比单链表的效率高，因为如果在后半段删除或者插入可以从后往前遍历到插入或删除位置然后进行操作。


4. 树
4.1什么是树?
树(Tree)是(n>=0)个节点的有限集合T，它满足两个条件：
(1) 有且仅有一个特定的称为根（Root）的节点。
(2)其余的节点可以分为m（m≥0）个互不相交的有限集合T1、T2、……、Tm，其中每一个集合又是一棵树，并称为其根的子树（Subtree）。

树的特性：层次关系，一对多，每个节点最多有一个前驱，但是可以有多个后继。(根节点无前驱，叶节点无后继)
关于树的节点：和链表类似，树存储结构中也将存储的各个元素称为 "结点"。

4.2 关于树的一些术语
(1)度数：一个节点的子树的个数 （一个节点有几个孩子为该节点度数）      
(2)树度数：树中节点的最大度数
(3)叶节点或终端节点: 度数为零的节点        
(4)分支节点：度数不为零的节点 （A B C D E H）
(5)内部节点：除根节点以外的分支节点 （去掉根和叶子）
(6)节点层次:  根节点的层次为1，根节点子树的根为第2层，以此类推
(7)树的深度或高度: 树中所有节点层次的最大值



4.3 二叉树
最多只能有俩孩子的数，并且分为左孩子和右孩子。


4.3.1 什么是二叉树
二叉树（Binary Tree）是n（n≥0）个节点的有限集合，它或者是空集（n＝0）， 或者是由一个根节点以及两棵互不相交的、分别称为左子树和右子树的二叉树组成。
二叉树与普通有序树不同，二叉树严格区分左孩子和右孩子，即使只有一个子节点也要区分左右。

4.3.2 二叉树的特性(重点)
(1)二叉树第k（k>=1）层上的节点最多为2的k-1次幂节点 //2^(k-1)
(2)深度为k（k>=1）的二叉树最多有2的k次幂-1个节点  //满二叉树的时候最多节点数2^k-1
(3)在任意一棵二叉树中，树叶的数目比度数为2的节点的数目多一。
设度数为0的节点数为n0，度数为1的节点数为n1以及度数为2的节点数为n2，则：
总节点数为各类节点之和:  n=n0 + n1 + n2
总节点数为所有子节点数加一：n=n0*0+n1*1+n2*2+1=n1 + 2*n2 + 1
上面公式减去下面公式得： 
0 = n0 - n2 - 1 
==> n0 = n2+1

4.3.3 满二叉树和完全二叉树
满二叉树: 深度为k（k>=1）时节点数为2^k - 1(2的k次幂-1)
完全二叉树:	只有最下面两层有度数小于2的节点，且最下面一层的叶节点集中在最左边的若干位置上。(先挂树的左边向右, 从上向下挂)

4.3.4 二叉树的存储结构
(1)二叉树顺序存储
顺序存储结构：完全二叉树的编号方法从上到下，从左到右，设根节点编号为1，完全二叉树的节点数为n，某节点编号为i。
●当i>1(不是根节点时)，有父节点，父节点编号为i/2
●当2*i<=n时，有左孩子，其编号2*i，否则没有左孩子，本身就是叶节点
●当2*i+1<=n时，有右孩子，其编号2*i+1,否则没有右孩子。

有n个节点的完全二叉树可以用有n+1 个元素的数组进行顺序存储，节点号和数组下标一一对应，下标为零的元素不用。
利用以上特性，可以从下标获得节点的逻辑关系。不完全二叉树通过添加虚节点构成完全二叉树，然后用数组存储，
这要浪费一些存储空间。

看图：


(2)二叉树的遍历(重点)
前序: 根 -> 左 -> 右
中序: 左 -> 根 -> 右
后序: 左 -> 右 -> 根

例如：

前序：A B C D E F G H K
中序：B D C A E H G K F
后序：D C B H K G F E A

练习：
已知遍历结果如下，试画出对应的二叉树。
前序:  A B C E H F I J D G K
中序： A H E C I F J B D K G


练习：
(2) 深度为8的二叉树，其最多有( 	2^8-1	 ) 个节点，第8层最多有(  2^7  )个节点 
(网易) 
(3) 数据结构中，沿着某条路线，一次对树中每个节点做一次且仅做一次访问，对二叉树的节点从1开始进行连续编号，要求每个节点的编号大于其左、右孩子的编号，同一节点的左右孩子中，其左孩子的编号小于其右孩子的编号，可采用(   )次序的遍历实现编号(网易)
A 先序		B 中序  	C 后序		D 从根开始层次遍历  
	
(4)一颗二叉树的 前序： A B D E C F, 中序：B D A E F C 问树的深度是 (  ) (网易)
A  3		B  4		C  5		D  6


4.3.5 二叉树的链式存储
用链表实现，基于完全二叉树的规律来构建树，按照完全二叉树的编号方法，从上到下，从左到右。
总结点是n, 第i个节点：
左子节点编号: 当2*i<=n时，有左孩子，其编号2*i
右子节点编号: 当2*i+1<=n时，有右孩子,其编号2*i+1
可以根据左右二点编号来判断是否对二叉树构建完成：


#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_t
{
    int data;                   // 数据域
    struct tree_node_t *lchild; // 左子
    struct tree_node_t *rchild; // 右子
} bitree_node_t, *bitree_node_p;

// 创建二叉树,用递归函数
bitree_node_p CreateBitree(int i, int n) // i:根节点编号, n:总节点数
{
    // 1.创建根节点空间
    bitree_node_p r = (bitree_node_p)malloc(sizeof(bitree_node_t));
    if (NULL == r)
    {
        perror("r malloc err");
        return NULL;
    }
    // 2.初始化根节点
    r->data = i;
    if (2 * i <= n) // 判断是否有左子
        r->lchild = CreateBitree(2 * i, n);
    else
        r->lchild = NULL;

    if (2 * i + 1 <= n) // 判断是否有右子
        r->rchild = CreateBitree(2 * i + 1, n);
    else
        r->rchild = NULL;

    return r;
}

// 前序: 根 左 右
void PreOrder(bitree_node_p r)
{
    if (r == NULL)
        return; // 结束无返回值的函数

    printf("%d ", r->data); // 根
    if (r->lchild != NULL)  // 左
        PreOrder(r->lchild);
    if (r->rchild != NULL) // 右
        PreOrder(r->rchild);
}

// 中序
void InOrder(bitree_node_p r)
{
    if (r == NULL)
        return; // 结束无返回值的函数

    if (r->lchild != NULL) // 左
        InOrder(r->lchild);

    printf("%d ", r->data); // 根

    if (r->rchild != NULL) // 右
        InOrder(r->rchild);
}

// 后序
void PostOrder(bitree_node_p r)
{
    if (r == NULL)
        return; // 结束无返回值的函数

    if (r->lchild != NULL) // 左
        PostOrder(r->lchild);

    if (r->rchild != NULL) // 右
        PostOrder(r->rchild);

    printf("%d ", r->data); // 根
}
int main(int argc, char const *argv[])
{
    bitree_node_p root = CreateBitree(1, 5);
    printf("前序: ");
    PreOrder(root);
    printf("\n");
    printf("中序: ");
    InOrder(root);
    printf("\n");
    printf("后序: ");
    PostOrder(root);
    printf("\n");
    return 0;
}

 
7.4 层次遍历
层次遍历（队列思想）一定要懂
-






https://www.runoob.com/w3cnote/ten-sorting-algorithm.html 


录制文件：https://meeting.tencent.com/crm/2VbPQPavfb 

