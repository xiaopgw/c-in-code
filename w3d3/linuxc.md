# 大纲
C   结构体  共用体  枚举    指针函数    函数指针    函数指针数组
Linux   shell
# 结构体
构造数据类型
格式

struct 结构体名
{
    数据类型 成员变量1;
    数据类型 成员变量2;
    数据类型 成员变量3;
};
```c
struct star
{
    int id;
    char s;
    float height;
    char arr[32];
};
```
数据类型 struct star
成员变量类型:基本数据类型、数组、指针, 不能是函数
## 结构体变量
数据类型    变量名;
### 定义
#### 定义结构体数据类型的同时，直接定义结构体变量名
```c
struct l
{
    int a;
    int b;
}c;
```

#### 先定义结构体，后定义结构体变量
```c
struct l
{
    int a;
    int b;
};
int main()
{
    struct l c;
}
```

#### 无标签结构体
```c
struct 
{
    int a;
    int b;
}c;
```

### 初始化
#### 定义时赋值
```c
struct l
{
    int a;
    int b;
};
int main()
{
    struct l c = {1, 2};
}
```

#### 定义后 再赋值
```c
struct l
{
    int a;
    char b[32];
};
int main()
{
    struct l c;
    c.a = 1;
    strcpy(c.b, "hello world");
}
```

### 访问
```c
scanf("%d %s", &c.a, c.b);
printf("%d%s", c.a, c.b);
```

### 字节大小
```c
struct l
{
    int a;
    char b[32];
};
int main()
{
    struct l c;
    printf("%d\n", sizeof(c));
}
```
64位操作系统，默认value值为8，和结构体中成员变量sizeof最大值比较，取较小值，按较小值的整数倍开辟空间。
### 结构体数组
定义
```c
struct l
{
    int a;
    char b[32];
}c[2];
int main()
{
    struct l d[3];
}
```
初始化
```c
struct l
{
    int a;
    char b[32];
}d[2];
int main()
{
    struct l c[2] = {{1, "tai"}, {2, "shan"}};

        d[0].a = 1;
        strcpy(d[0].b, "hello");

        d[1].a = 2;
        strcpy(d[1].b, "world");
}
```
### 结构体指针
```c
struct l
{
    int a;
    char b[32];
}d[2];
int main()
{
    struct l c[2] = {{1, "tai"}, {2, "shan"}};
    struct l *p = c;
    //遍历
    for (int i = 0; i < 2; i++)
    {
        scanf("%d %s", &(p[i].a), (p + i)->b);
        printf("%d %s", (*(p + i)).a, (*(p + i)).b);
    }
}
struct star
```
# 重定义
typedef int gaga;
int a;等同于gaga a;

可以用在typedef上以缩小结构体名字的长度

# 共用体
union 共用体名
{
    成员列表;
}
```c
struct l
{
    int a;
    char b;
}d;
```
共用体成员共用一块地址
# 枚举
enum a
{
    v1,
    v2,
    v3,
    v4,
    v5
};
顺序挨个排序加一（方便阅读）

#储存类型
## auto 修饰变量
## static 修饰变量和函数
    放在静态区
    .data   已初始化的全局变量和静态变量
    .bss    未初始化的全局变量和静态变量
修饰变量，声明周期会被延长至整个程序
修饰全局变量和函数，会被限制在本文件中使用


- [大纲](#大纲)
- [结构体](#结构体)
  - [结构体变量](#结构体变量)
    - [定义](#定义)
      - [定义结构体数据类型的同时，直接定义结构体变量名](#定义结构体数据类型的同时直接定义结构体变量名)
      - [先定义结构体，后定义结构体变量](#先定义结构体后定义结构体变量)
      - [无标签结构体](#无标签结构体)
    - [初始化](#初始化)
      - [定义时赋值](#定义时赋值)
      - [定义后 再赋值](#定义后-再赋值)
    - [访问](#访问)
    - [字节大小](#字节大小)
    - [结构体数组](#结构体数组)
    - [结构体指针](#结构体指针)
- [重定义](#重定义)
- [共用体](#共用体)
- [枚举](#枚举)
  - [auto 修饰变量](#auto-修饰变量)
  - [static 修饰变量和函数](#static-修饰变量和函数)



好，根据你的笔记内容给你出题。

一、结构体基础
1. 以下代码能编译通过吗？如果不能，问题在哪？


Apply
struct student {
    int id;
    char name[32];
    float score;
    void print() {
        printf("%d\n", id);
    }
};
2. 下面几种定义方式有什么区别？


Apply
// 方式A
struct { int a; int b; } x;

// 方式B
struct s { int a; int b; };

// 方式C
struct s { int a; int b; } y;
哪种方式以后不能再定义新的该结构体变量？

二、初始化
3. 以下代码输出什么？


Apply
struct data {
    int a;
    int b;
};

int main() {
    struct data d = {10};
    printf("%d %d\n", d.a, d.b);
    return 0;
}
4. 以下代码正确吗？


Apply
struct data {
    int a;
    char b[32];
};

int main() {
    struct data d;
    d.b = "hello";   // 这一行
    return 0;
}
三、字节大小
5. 64位系统下，以下结构体分别占多少字节？


Apply
// 结构体A
struct A {
    char a;
    int b;
    char c;
};

// 结构体B
struct B {
    int b;
    char a;
    char c;
};
为什么它们大小不同？这个现象叫什么？

6. 你的笔记里写"默认value值为8"，这个value值是什么？如果我用 #pragma pack(1) 会有什么效果？

四、结构体指针
7. 以下代码三种访问方式等价吗？哪种写法最常用？


Apply
struct student {
    int id;
    char name[32];
};

int main() {
    struct student s = {1, "tom"};
    struct student *p = &s;

    // 方式1
    printf("%d", (*p).id);

    // 方式2
    printf("%d", p->id);

    // 方式3
    printf("%d", s.id);
}
8. 以下代码有什么问题？


Apply
struct student {
    int id;
    char name[32];
};

int main() {
    struct student *p;
    p->id = 10;    // 这一行
    return 0;
}
五、重定义
9. 以下代码有什么问题？


Apply
typedef int myint;
myint a = 10;

typedef struct student {
    int id;
} stu;

stu s = {1};

typedef stu new_stu;
new_stu s2 = {2};
这段代码能编译通过吗？stu 和 new_stu 是类型名还是变量名？

六、共用体
10. 以下代码输出什么？（假设 int 占4字节）


Apply
union data {
    int a;
    char b;
};

int main() {
    union data u;
    u.a = 0x12345678;
    printf("%x\n", u.b);
    return 0;
}
11. 共用体和结构体的核心区别是什么？什么场景适合用共用体？

七、枚举
12. 以下代码输出什么？


Apply
enum color {
    RED,
    GREEN,
    BLUE
};

enum color {
    MON,
    TUE,
    WED
};
这段代码能编译通过吗？

13. 以下代码：


Apply
enum week {
    MON = 1,
    TUE,
    WED = 5,
    THU,
    FRI
};
TUE、THU、FRI 的值分别是多少？

八、static
14. 以下代码输出什么？


Apply
void fun() {
    static int count = 0;
    count++;
    printf("%d ", count);
}

int main() {
    for (int i = 0; i < 5; i++) {
        fun();
    }
    return 0;
}
15. 以下两个文件编译链接，能通过吗？



Apply
// a.c
static int g_val = 10;

// b.c
extern int g_val;
int main() {
    printf("%d\n", g_val);
    return 0;
}
