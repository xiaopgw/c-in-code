### 选择填空
1. break语句的正确的用法是（）
A. 无论在任何情况下，都终端程序的执行，退出到系统下一层
B. 在多重循环中，只能退出最近靠近的那一层循环语句
C. 跳出多重循环
D. 只能修改控制变量

2. 有以下程序段
int n = 0, p;
do
{
    scanf("%d", &p);n++;
}while(p!=12345 && n < 3);
此处do-while循环的结束条件是().
A. P的值不等于12345或者n的值小于3
B. P的值等于12345或者n的值大于等于3
C. P的值等于12345并且n的值大于等于3    
D. P的值不等于12345并且n的值小于3

3. 语句while(!E)中表达式!E等价于()
A. E == 1    B. E != 0    C. E != 1    D. E == 0

4. int a[5][4], * p = a[0];则*(p+2*4+3)等于
A. a[2][0]  B. a[2][1]  C. a[2][2]  D. a[2][3]

5. 以下对二维数组a的正确说明是（）
A. int a[][3] = { 0 };
B. int a[3][] = { {1}, {2}, {3} };
C. int a[1][3] = { 1, 2, 3, 4 };
D. int a[2][3] = { {1, 2}, {3, 4}, {5, 6} };

6. 若有定义int i = 2, a[10], *p = &a[i];则与 *p++等价的是
A. a[i++]   B. a[i]++   C. a[i]   D. a[++i]

7. 创建文件:直接在本目录的上级目录下创建一个名dir1的文件夹，并在dir1文件夹下创建一个名为file1的文件:

8. 查看当前绝对路径的指令

9. 静态列出进程名称包含python的所有进程列表:
    
10. 使用命令搜索/usr目录下，文件名中包换name字符串的所有文件。

11. 在vim文档编辑状态下，插入指令及保存并退出的步骤

12. 查看虚拟机磁盘空间使用情况

13. 解压tmp.tar.gz文件的指令 

14. 以下程序的结果输出是什么
    int a[] = {2, 4, 5};
    int *p = a;
    int *q = &a[2];
    那么a[q-p]是什么

15. int x = 21, y = 36;
    x = y++ + x++;
    y = ++y + ++x;
    printf("%d%d\n", x, y);
    x为     y为

16. 若定义char a[] = {"bcd\0ghi"},*p = a;则printf("%c", *p + 4)的输出结果为
    
17. 以下程序的输出结果为
    #include <stdio.h>
    void swap(int a, int b)
    {
        int c;
        c = a; a = b; b = c;
    }
    void main()
    {
        int a, b;
        a = 10; b = 2;
        swap(a, b);
        printf("a = %d, b = %d\n", a, b);
    }

18. 全局变量和局部变量可以重命名吗

19. 下面这段代码能编译通过吗？如果不行，问题在哪？
```
int* getNum() 
{
    int a = 10;
    return &a;
}
```

20. 以下代码有什么问题？


Apply
struct student {
    int id;
    char name[32];
};

int main() {
    struct student *p;
    p->id = 10;    
    return 0;
}

21. 以下代码有什么问题？


Apply
typedef int myint;
myint a = 10;

typedef struct student {
    int id;
} stu;

stu s = {1};

typedef stu new_stu;
new_stu s2 = {2};

22. C语言程序的三种基本程序是
    
23. 以下关于字符串的叙述中正确的是（）
A. 空串比空格打头的字符串小
B. 两个字符串中的字符个数相同时才能进行字符串大小的比较
C. 可以用关系运算符对字符串的大小进行比较
D. C语言中有字符串类型的常量和变量

24. 若要将当前目录中的myfile.txt文件压缩成myfile.txt.tar.gz则实现的命令为()
A. tar -cvf myfile.txt myfile.txt.tar.gz
B. tar -zcvf myfile.txt.tar.gz myfile.txt
C. tar -zcvf myfile.txt myfile.txt.tar.gz
D. tar -cvf myfile.txt.tar.gz myfile.txt

25. 有以下程序
main()
{
    char *p[10] = {"abc", "aabdfg","dcdbe","abbd","cd"};
    printf("%d\n",strlen(p[4]));
}

26. char *RetMenory(void)
{
    char p[] = "hello world";
    return p;
}
void Test(void)
{
    char *str = NULL;
    str = RetMemory();
    puts(str);
}
运行结果（）
A. 语法有错误，不能编译
B. hello world
C. 结果不可预知
D. hello world+乱码

### 编程题
1. 已知char *str[10] = {"abcABCaa"}, 实现此字符中内容字符大小写转换后，使用排序进行升序排序，最终输出str。

2. 编写函数实现mySwap函数，及实现两个字符交换。要求内部要添加对空指针内容的提示。原型：void mySwap (char *a1, char *a2);
编写完成后，使用此数组char str[] = *hello world; 测试mySwap函数。

4. 使用for嵌套语句产生下列图案：
A
_\AB
_\_\ABC
_\_\_\ABCD
_\_\_\_\ABCDE
_\_\_\_\_\ABCDEF

4. 写一个名为 operate 的函数，接收两个整数 a, b 和一个函数指针数组 ops（长度3），依次调用数组中的三个函数，分别打印结果。

5. 综合题：用条件编译 + 函数指针数组写一个"计算器"的雏形：

定义两个宏 MODE_ADD 和 MODE_SUB，值分别为 1 和 2
如果定义了 MODE_ADD，数组中包含 add；如果定义了 MODE_SUB，数组中包含 sub
通过改变宏定义，编译出不同版本的计算器

### BUG

---

### 薄弱知识点记录 (2026-06-29) [知识点: break vs return / 指针别名 / 链表遍历边界]
**问题1**: 用 `return -1` 代替 `break` 退出输入循环，导致打印循环无法执行
**根源**: 不清楚 break 只跳出当前循环，return 直接结束整个函数
**掌握状态**: 待复习

**问题2**: 不理解 `ptail = hp` 后为什么修改 ptail->poit 会影响 hp
**根源**: 对"两个指针指向同一块内存就是别名"的理解不够深入
**掌握状态**: 待复习

**问题3**: 链表遍历时先移动指针再打印导致段错误或漏打/多打数据
**根源**: 遍历时对"当前指针指向什么"的边界条件不清晰
**掌握状态**: 待复习
---