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