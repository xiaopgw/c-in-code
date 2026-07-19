# 链式表（链表）

## 一、链表的定义

链表（Linked List）是一种**线性结构**，采用**链式存储**方式。链表中的元素称为**节点（Node）**，每个节点包含数据域和指针域，通过指针将各个节点串联在一起。

相比顺序表（数组），链表的最大特点是**内存空间不连续**、**长度不固定**、**插入删除不需要移动元素**。

### 1.1 节点的结构

```c
typedef struct node
{
    datatype data;        // 数据域：存储数据
    struct node *next;    // 指针域：存储下一个节点的地址
}node_t, *node_p;
```

---

## 二、有头链表 vs 无头链表

**有头链表（带头节点）：**
```
头节点 -> 节点1 -> 节点2 -> 节点3 -> NULL
  ^
  head
```
- 头节点的 `data` 无效（不存数据），`next` 指向第一个有效节点
- 创建链表时先创建头节点，后续操作**不需要**修改 head 指针本身（因为 head 的指针域变了，但 head 变量不变）
- 操作统一，对空链表和非空链表不需要写两套代码

**无头链表（不带头节点）：**
```
节点1 -> 节点2 -> 节点3 -> NULL
  ^
  head
```
- 每个节点都有有效数据
- 插入第一个节点和删除第一个节点时，head 指针本身的值会变，**需要**二级指针（`sp *head`）
- 对空链表和非空链表需要分别处理

**你目前写的是有头链表**（`HeadLinkedList()` 创建头节点），这是一个好的选择。

---

## 三、链表的核心操作

### 3.1 创建头节点

```c
sp HeadLinkedList()
{
    sp p = malloc(sizeof(sl));
    if (p == NULL) return NULL;
    p->ele = 0;       // 数据域无效，随便给
    p->poit = NULL;   // 指针域初始化为 NULL
    return p;
}
```

### 3.2 遍历（有头遍历）

```c
void Traverse(sp p)
{
    // 方法1：p->next != NULL
    while (p->poit != NULL)
    {
        p = p->poit;
        printf("%d ", p->ele);
    }
}
```

**有头遍历 vs 无头遍历的区别，你自己也在笔记里标记过这个问题，这里统一一下：**

| 遍历方式 | 条件 | 先走再打印 | 适用场景 |
|---------|------|-----------|---------|
| `while (p->next != NULL)` | 跳到下一个节点后判断该节点的 next 是否为 NULL | 先 p=p->next 再打印 | 有头链表 |
| `while (p != NULL)` | 直接判断当前节点是否为 NULL | 先打印再 p=p->next | 无头链表 |

简单记法：
- 有头链表：先跳过头节点，从第一个有效节点开始，所以条件看 `p->next != NULL`
- 无头链表：直接从 head 开始遍历，所以条件看 `p != NULL`

### 3.3 尾插法

```c
sp LinkedList(sp *tail, datatype data)
{
    sp p = malloc(sizeof(sl));
    p->ele = data;
    p->poit = NULL;
    (*tail)->poit = p;  // 当前尾节点指向新节点
    *tail = p;          // 更新尾指针
    return p;
}
```

关键点：
- 需要一个 `tail` 指针始终指向最后一个节点，这样尾插 O(1)
- 为什么 `tail` 是二级指针？因为我们要修改 tail 本身的值（让它指向新节点）

### 3.4 头插法

```c
int InsertHead(sp head, datatype data)
{
    sp p = malloc(sizeof(sl));
    p->ele = data;
    p->poit = head->poit;   // 新节点指向原来的第一个节点
    head->poit = p;          // 头节点指向新节点
    return 0;
}
```

头插法插入后，新节点成为第一个有效节点。整个过程：
```
初始： head -> [A] -> [B] -> NULL
头插 C：head -> [C] -> [A] -> [B] -> NULL
```

### 3.5 指定位置插入

```c
sp Insert(sp head, int post, datatype data)
{
    // 1. 检查 post 范围
    // 2. 循环到 post 位置的前一个节点
    // 3. 创建新节点，接入链表
}
```

插入逻辑的核心代码：
```c
new->poit = tail->poit;    // 新节点指向目标位置的节点
tail->poit = new;           // 前一个节点指向新节点
```

这两句顺序不能反——如果先把 `tail->poit = new` 执行了，就丢失了原来后面的节点地址。

### 3.6 指定位置删除

```c
sp delete(sp head, int post)
{
    // 1. 检查 post 范围
    // 2. 循环到 post 位置的前一个节点
    // 3. 用一个临时指针保存要删除的节点
    sp p = head->poit;
    head->poit = p->poit;   // 跳过删除节点
    free(p);                 // 释放空间
}
```

### 3.7 按值删除（所有匹配项）

```c
int DeleteDataLinkList(sp head, datatype data)
{
    sp p = head->poit;
    while (p != NULL)
    {
        if (p->ele == data)
        {
            head->poit = p->poit;
            free(p);
            p = head->poit;  // 继续检查同一位置的节点
        }
        else
        {
            p = p->poit;
            head = head->poit;
        }
    }
}
```

这个实现是**删除所有匹配的元素**。注意这里 `head` 作为局部指针变量使用，每删除一个后 `p = head->poit` 重新指向当前位置，继续检查。

### 3.8 按位置查找

```c
sp FindByPos(sp head, int post)
{
    for (int i = 0; i <= post; i++)
    {
        head = head->poit;
    }
    return head;
}
```

注意循环条件是 `i <= post`，因为要跳过 head 找到第 post 个节点。你也可以写成 `for (int i = 0; i < post + 1; i++)`。

### 3.9 逆转链表

```c
void Reverse(sp head)
{
    sp h = head;          // 保存头节点
    sp p = head->poit;    // p 指向第一个有效节点
    sp t = NULL;          // 临时指针
    h->poit = NULL;       // 把头节点断开
    
    while (p != NULL)
    {
        t = p->poit;       // 保存下一个节点
        p->poit = h->poit; // 当前节点指向已逆转部分的第一个
        h->poit = p;       // 头节点指向当前节点（头插）
        p = t;             // p 指向原来的下一个节点
    }
}
```

逆转本质就是**遍历一遍链表，不断做头插法**。这个算法你写得很好。

图示：
```
原链表： head -> [1] -> [2] -> [3] -> [4] -> NULL
第一步： head->poit = NULL, p = [1]
         head -> NULL    [1] -> [2] -> [3] -> [4] -> NULL
                         p

第1轮头插：t = [2], [1]->poit = NULL, head->poit = [1], p = [2]
         head -> [1] -> NULL     [2] -> [3] -> [4] -> NULL
                                 p

第2轮头插：t = [3], [2]->poit = [1], head->poit = [2], p = [3]
         head -> [2] -> [1] -> NULL     [3] -> [4] -> NULL
                                        p

第3轮头插：t = [4], [3]->poit = [2], head->poit = [3], p = [4]
         head -> [3] -> [2] -> [1] -> NULL     [4] -> NULL
                                               p

第4轮头插：t = NULL, [4]->poit = [3], head->poit = [4], p = NULL
         head -> [4] -> [3] -> [2] -> [1] -> NULL
```

---

## 四、链表操作的边界情况

| 操作 | 正常情况 | 边界情况 |
|------|---------|---------|
| 尾插 | 链表非空时正常插入 | 链表只有头节点时，tail == head |
| 头插 | 链表有多个节点 | head->poit == NULL 时也是一样的逻辑 |
| 指定位置插入 | 插到中间 | post=0（头插）、post=Length（尾插） |
| 指定位置删除 | 删除中间节点 | post=0（头删）、post=Length-1（尾删） |
| 按值删除 | 删除一个匹配 | 删除多个匹配 / 没有匹配 / 所有节点都被删光 |
| 逆转 | 多个节点 | 链表为空或只有一个有效节点 |

---

## 五、关于命名问题

你在代码里用的是 `poit`（point 的拼写错误），链表节点的指针域**行业惯例统一用 `next`**。

```c
struct linked_list *poit;   // 你的写法
struct linked_list *next;   // 标准写法
```

建议以后统一改过来，好处是：
1. 别人读你代码时一眼就能看出是指针域
2. 看网上的教程/开源代码时不用额外转换命名
3. 面试时不会被这个细节扣印象分

---

## 六、链表 vs 顺序表

| 对比维度 | 顺序表（数组） | 链表 |
|---------|--------------|------|
| 内存 | 连续空间 | 不连续空间 |
| 插入/删除 | 需要移动元素 O(n) | 只需修改指针 O(1) |
| 查找 | 按下标随机访问 O(1) | 需要遍历 O(n) |
| 空间利用率 | 无额外指针开销 | 每个节点多一个指针 |
| 扩容 | 扩容成本高（realloc+搬移） | 天然动态，无需扩容 |

**什么时候用链表？**
- 插入删除频繁、查找较少
- 数据量不确定，需要动态增长

**什么时候用顺序表？**
- 查找频繁、插入删除较少
- 数据量固定或可预估

---

## 七、总结

```
链表的本质：线性结构 + 链式存储

有头链表：
  - 有一个不存数据的头节点，操作统一
  - 头指针本身不变，修改的是头节点的指针域

核心操作：
  - 头插：新节点 -> head->next ; head -> 新节点
  - 尾插：遍历到末尾，tail->next = 新节点
  - 指定位置插入：找到位置前一个，接入新节点
  - 指定位置删除：找到位置前一个，跳过目标，free
  - 按值删除：遍历匹配，free 节点
  - 逆转：遍历一遍，每次都做头插

遍历口诀：
  - 有头链表：while (p->next != NULL) { p = p->next; 处理 }
  - 无头链表：while (p != NULL) { 处理; p = p->next; }
```

你的链表实现整体是正确的，功能齐全。建议：
1. `poit` 改为 `next`（统一命名规范）
2. `delete` 函数没有处理 post 校验失败的情况（你只打印了错误，没有返回）
3. `DeleteHead` 没有返回值（缺少 return）