# 顺序表

## 一、顺序表的定义

顺序表（Sequential List）是一种**线性结构**，采用**顺序存储**方式。顺序表中的元素在内存中是连续存放的，本质上就是**数组**，但在数组的基础上增加了对数据的管理信息（如有效元素个数 last）。

顺序表的特点是 **内存连续**、**长度固定**、**随机存取**。

> 顺序表 = 数组 + last（最后一个有效元素的下标）

---

## 二、顺序表的结构体定义

### 2.1 你最初写的形式（w4d5）

```c
#define N 64

typedef struct seplist
{
    int data[N];          // 静态数组，容量固定
    int last;             // 最后一个有效元素的下标
}ss, *sp;
```

**关键解释：**
- `data[N]`：数组空间，`N` 是最大容量（这里 64）
- `last`：**最后一个有效元素的下标**，不是"长度"！

### 2.2 last 的工作原理

```
初始状态：last = -1   （空表，没有元素）
    [  ] [  ] [  ] [  ] [  ] [  ] ... [  ]
    last = -1

插入 1 2 3：last = 2
    [ 1 ] [ 2 ] [ 3 ] [  ] [  ] [  ] ... [  ]
                        last=2

插入第4个元素：last = 3
    [ 1 ] [ 2 ] [ 3 ] [ 4 ] [  ] [  ] ... [  ]
                              last=3
```

**核心关系：**
- 空表：`last == -1`
- 满表：`last == N - 1`
- 有效元素个数：`last + 1`
- 有效元素范围：`data[0] ~ data[last]`

---

## 三、顺序表的核心操作

### 3.1 创建顺序表

```c
sp s()
{
    sp p = (sp)malloc(sizeof(ss));
    if (p == NULL) return NULL;
    p->last = -1;          // 初始化为空表
    return p;
}
```

### 3.2 判空和判满

```c
int seplist_IsEp(sp p)
{
    return p->last == -1;       // 空表
}

int seplist_IsFull(sp p)
{
    return p->last == N - 1;    // 满了
}
```

### 3.3 遍历

```c
void seplist_traverse(sp p)
{
    for (int i = 0; i <= p->last; i++)  // 注意：i <= last
    {
        printf("%d ", p->data[i]);
    }
}
```

**这里有个容易犯的错误：** 遍历条件必须是 `i <= p->last`，不能是 `i < N`。如果写成 `i < N`，会把数组后面没有初始化的垃圾值也打印出来——这是你在顺序栈里遇到过的同样的问题。

### 3.4 插入（指定位置）

```c
int seplist_insert(sp p, int post, int data)
{
    // 1. 检查位置合法性
    if (post < 0 || post > p->last + 1 || seplist_IsFull(p))
        return -1;
    
    // 2. 从最后一个元素开始，逐个后移
    for (int i = p->last + 1; i > post; i--)
    {
        p->data[i] = p->data[i - 1];
    }
    
    // 3. 在空出来的位置插入新元素
    p->data[post] = data;
    
    // 4. last 加 1
    return (p->last)++;
}
```

**插入过程图示（在 post=2 处插入 99）：**

```
插入前：last=4
  [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [  ] [  ] ...
  last=4

后移过程：
  步骤1：data[5] = data[4]  =>  [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 5 ] [  ] ...
  步骤2：data[4] = data[3]  =>  [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 4 ] [ 5 ] [  ] ...
  步骤3：data[3] = data[2]  =>  [ 1 ] [ 2 ] [ 3 ] [ 3 ] [ 4 ] [ 5 ] [  ] ...

插入 99 到 data[2]：
  [ 1 ] [ 2 ] [ 99 ] [ 3 ] [ 4 ] [ 5 ] [  ] ...
  last=5
```

**为什么移动方向是从后往前？**
如果从前往后移：`data[2]=data[3]`，第一步就把 `data[3]` 的值覆盖到 `data[2]` 了，后面的数据就丢了。

**为什么 post 的范围是 `0` 到 `last + 1`？**
- `post=0`：插入到第一个位置（相当于头插）
- `post=last+1`：插入到最后一个位置后面（相当于尾插）
- `post` 超出这个范围或表满时，插入无效

### 3.5 删除（指定位置）

```c
int seplist_delete(sp p, int post)
{
    // 1. 检查位置合法性
    if (post < 0 || post > p->last || seplist_IsEp(p))
        return -1;
    
    // 2. 从 post 位置开始，逐个前移
    for (int i = post; i < p->last; i++)
    {
        p->data[i] = p->data[i + 1];
    }
    
    // 3. 把最后一个位置清零（可选，但推荐）
    p->data[p->last] = 0;
    
    // 4. last 减 1
    return (p->last)--;
}
```

**删除过程图示（删除 post=2 的元素）：**

```
删除前：last=5
  [ 1 ] [ 2 ] [ 99 ] [ 3 ] [ 4 ] [ 5 ] [  ] ...
  last=5

前移过程：
  步骤1：data[2] = data[3]  =>  [ 1 ] [ 2 ] [ 3 ] [ 3 ] [ 4 ] [ 5 ] [  ] ...
  步骤2：data[3] = data[4]  =>  [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 4 ] [ 5 ] [  ] ...
  步骤3：data[4] = data[5]  =>  [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 5 ] [  ] ...
  步骤4：data[5] = 0         =>  [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 0 ] [  ] ...
  last=4
```

**删除后的 data[last+1] 为什么最好清零？**
- 不清零：只是逻辑上不属于有效数据了，但内存里还留着，遍历时用 `<= last` 就没问题
- 清零的好处：调试的时候容易发现 bug，如果某次遍历不小心用了 `i < N`，打印出来的垃圾值至少是 0 而不是随机大数

### 3.6 按位置修改

```c
int seplist_ChangePost(sp p, int post, int data)
{
    if (post < 0 || post > p->last || seplist_IsEp(p))
        return -1;
    p->data[post] = data;
    return p->last;
}
```

### 3.7 按值查找

```c
int seplist_searchdata(sp p, int data)
{
    for (int i = 0; i <= p->last; i++)
    {
        if (p->data[i] == data)
            return i;          // 返回下标
    }
    return -1;                  // 没找到
}
```

---

## 四、顺序表的操作总结

| 操作 | 实现要点 | 时间复杂度 |
|------|---------|-----------|
| 创建 | malloc 分配空间，last = -1 | O(1) |
| 判空 | last == -1 | O(1) |
| 判满 | last == N - 1 | O(1) |
| 遍历 | for 从 0 到 last | O(n) |
| 插入 | 从后往前移动元素，再赋值 | O(n) |
| 删除 | 从前往后移动元素 | O(n) |
| 修改 | 直接数组赋值 | O(1) |
| 按值查找 | for 循环逐个比较 | O(n) |
| 取长度 | last + 1 | O(1) |

注意：**插入和删除的时间复杂度是 O(n)**，这是顺序表最大的短板。如果要频繁插入删除，应该用链表。

---

## 五、你的代码中值得注意的地方

### 5.1 你在 w4d5 的 insert.c 中的写法

```c
// 你的写法
for (int i = 0; i < n - post + 1; i++)
{
    p[n - i + 1] = p[n - i];
}
```

这个写法等价于从后往前移，是可行的。但 `n - post + 1` 这个计算不够直观，我更喜欢 `w4d5/seplist.c` 里的写法：

```c
// 更直观的写法
for (int i = p->last + 1; i > post; i--)
{
    p->data[i] = p->data[i - 1];
}
```

从 `last+1` 开始，到 `post+1` 结束，每次把前一个元素移到当前位置——更符合"从后往前搬"的直觉。

### 5.2 你用了全局变量 n

在 `insert.c` 和 `traverse.c` 中你用了全局变量 `n` 表示有效元素个数，而 `seplist.c` 中用 `p->last` 表示。这两个是不一致的：

```c
// insert.c 和 traverse.c 中用全局变量
int n = 0;
int insert(int *p, int post, int data) { ... n += 1; }

// seplist.c 中用结构体成员
int seplist_insert(sp p, int post, int data) { ... (p->last)++; }
```

两种方式：
- 全局变量方式：适用于操作一个固定的数组，简单但不够灵活（只能操作一个数组）
- 结构体方式：将数据和元信息封装在一起，可以用多个顺序表，推荐使用

你已经从全局变量方式过渡到了结构体方式，这是正确的进步方向。

---

## 六、顺序表 vs 数组

你可能觉得顺序表就是数组，为什么要包一层结构体？

```
数组：              int arr[64];    // 只存裸数据，没有"有多少个有效元素"的信息
顺序表：struct seplist {
           int data[64];
           int last;               // 告诉你：从 0 到 last 是有效数据
       };
```

**用数组做增删改查的痛点：**
- 不知道数组里当前有多少个有效元素
- 每次插入删除需要自己算偏移、手动管理 last
- 无法在函数参数中同时传递数组和长度

**顺序表解决了这些问题：**
- last 告诉你边界
- 插入删除的代码封装在函数里，调用者只需说"在第几个位置插入什么"
- 结构体作为一个整体传递，不用传两个参数

---

## 七、总结

```
顺序表的本质：数组 + last（最后一个有效元素下标）

核心公式：
  空表条件：    last == -1
  满表条件：    last == N - 1
  有效元素个数：last + 1
  有效元素范围：data[0] ~ data[last]

插入：从后往前搬，在空位赋值，last++
删除：从前往后搬，last--

特性：
  - 优点：内存连续，随机访问 O(1)
  - 缺点：插入删除 O(n)，容量固定

注意事项：
  - 遍历条件：i <= last，不是 i < N
  - post 范围：插入是 0~last+1，删除是 0~last
  - 删除后建议 data[last] = 0 清零