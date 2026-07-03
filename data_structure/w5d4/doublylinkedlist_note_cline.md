# 双向链表

## 一、单向链表 vs 双向链表的本质对比

你之前学的单向链表的节点：

```
单向链表节点：    data | next
                  数据域  指向后一个节点的指针
```

缺点很明显：**只能往前走，不能回头。**

- 遍历只能从头部到尾部
- 要删除一个节点，必须先知道它的前驱节点（否则链就断了）
- 想从尾部往头部走？做不到

双向链表的节点：

```
双向链表节点：    prev | data | next
                 指向前一个节点  指向后一个节点
```

多了一个 `prev` 指针，直译为"前驱"（previous 的缩写），指向它的前一个节点。

带来的好处：
- 可以双向遍历（从头到尾、从尾到头）
- 删除一个节点时，直接通过 `p->prev` 就能找到前驱，不需要额外遍历
- 某些操作逻辑上更对称、更直观

---

## 二、双向链表的结构体定义

```c
typedef int datatype;

typedef struct double_node
{
    datatype data;                 // 数据域
    struct double_node *prev;      // 指向前一个节点（前驱）
    struct double_node *next;      // 指向后一个节点（后继）
}dbnode_t, *dbnode_p;
```

对比单向链表的结构体：

```c
// 单向链表
typedef struct single_node
{
    datatype data;
    struct single_node *next;      // 只有 next，没有 prev
}snode_t, *snode_p;

// 双向链表
typedef struct double_node
{
    datatype data;
    struct double_node *prev;      // 多了 prev
    struct double_node *next;
}dbnode_t, *dbnode_p;
```

从内存角度看，双向链表每个节点多了一个指针（8 字节，64 位系统），代价是更大的内存开销；收益是更灵活的操作。

---

## 三、有头双向链表的链式结构示意图

```
NULL <--- [head] ---> <--- [1] ---> <--- [2] ---> <--- [3] ---> NULL
          prev next          prev next          prev next          prev next
          |                  |                  |                  |
          +--- 头节点 -------+                  |                  |
              data 无效，只起定位作用           |                  |
                                                +------------------+
                                             头节点的 next 指向节点1
                                             节点1 的 prev 指向头节点
                                             节点1 的 next 指向节点2
                                             节点2 的 prev 指向节点1
                                             节点3 的 next 指向 NULL
                                             节点3 的 prev 指向节点2
```

**关键规则：**
- 头节点的 `prev` 永远指向 `NULL`
- 第一个有效节点的 `prev` 指向头节点
- 最后一个有效节点的 `next` 指向 `NULL`
- `NULL` 是终止标记，表示"到头了"或"到尾了"

---

## 四、核心操作（完整代码 + 过程推演）

### 4.1 创建头节点

```c
dbnode_p create_head()
{
    dbnode_p head = malloc(sizeof(dbnode_t));
    if (head == NULL) return NULL;
    
    head->data = 0;       // 头节点数据域无效，随便给
    head->prev = NULL;    // 头节点的 prev 永远为 NULL
    head->next = NULL;    // 空链表时，next 也为 NULL
    return head;
}
```

初始化后的内存状态：

```
空链表：
  head -> [ 0 | NULL | NULL ]
            data  prev   next
```

### 4.2 尾插法

**思路：** 遍历到最后一个节点，在其后面插入新节点。

```c
dbnode_p insert_tail(dbnode_p head, datatype data)
{
    // 1. 创建新节点
    dbnode_p new_node = malloc(sizeof(dbnode_t));
    if (new_node == NULL) return NULL;
    new_node->data = data;
    new_node->prev = NULL;   // 先初始化
    new_node->next = NULL;
    
    // 2. 遍历到尾节点
    dbnode_p p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    // 此时 p 指向最后一个有效节点（或头节点，如果链表为空）
    
    // 3. 将新节点链接到末尾
    p->next = new_node;       // 原尾节点的 next 指向新节点
    new_node->prev = p;       // 新节点的 prev 指向原尾节点
    new_node->next = NULL;    // 新节点的 next 指向 NULL（已经是最后了）
    
    return new_node;
}
```

**过程推演：** 空链表开始，尾插 1、2、3

```
初始：  head -> [0|NULL|NULL]

尾插1： new_node = [1|NULL|NULL]
        p = head (p->next == NULL，直接到尾了)
        p->next = new_node
        new_node->prev = p
        head -> [0|NULL|*] ---> [1|*|NULL]
                               p->next  new_node

尾插2： new_node = [2|NULL|NULL]
        p 从 head 开始遍历，p->next 到节点1
        p->next = new_node
        new_node->prev = p (= 节点1)
        head -> [0] -> [1] <--> [2] -> NULL

尾插3： 同理
        head -> [0] -> [1] <--> [2] <--> [3] -> NULL
```

**与单向链表尾插的对比：**
- 单向链表尾插只需两步：`p->next = new_node; new_node->next = NULL;`
- 双向链表尾插多了一步：`new_node->prev = p;`（多维护一个 prev 指针）
- 除此之外流程完全一样

### 4.3 头插法

**思路：** 在头节点后面插入（插在第一个有效节点之前）。

```c
int insert_head(dbnode_p head, datatype data)
{
    // 1. 创建新节点
    dbnode_p new_node = malloc(sizeof(dbnode_t));
    if (new_node == NULL) return -1;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    // 2. 新节点指向原来的第一个有效节点
    new_node->next = head->next;
    new_node->prev = head;
    
    // 3. 如果链表非空，原来的第一个有效节点的 prev 要指向新节点
    if (head->next != NULL)
    {
        head->next->prev = new_node;
    }
    
    // 4. 头节点指向新节点
    head->next = new_node;
    
    return 0;
}
```

**关键点——第 3 步的分支判断：**
- 如果 `head->next == NULL`（链表为空），第 3 步不需要做
- 如果 `head->next != NULL`（链表非空），必须把原来第一个节点的 `prev` 从指向 `head` 改为指向 `new_node`

**过程推演：** 已有 `head -> [1] -> [2] -> NULL`，头插 0

```
头插前： head -> [0] <--> [1] <--> [2] -> NULL

步骤1： new_node->next = head->next  -> 节点1 的地址
步骤2： new_node->prev = head
        head -> [0] <--- [new] ---> [1] <--> [2] -> NULL
                    prev= head   next=节点1

步骤3： head->next != NULL，所以 head->next->prev = new_node
        即 节点1->prev = new_node
        head -> [0] <--> [new] <--> [1] <--> [2] -> NULL

步骤4： head->next = new_node
        完成！
```

**头插法修改的指针数量（链表非空时）：**
- 新节点的 prev 指向 head（1 个指针）
- 新节点的 next 指向原来的第一个节点（1 个指针）
- 原来的第一个节点的 prev 指向新节点（1 个指针）
- head 的 next 指向新节点（1 个指针）
- 一共修改了 **4 个指针**

而在单向链表中，头插只修改 **2 个指针**。多出来的 2 个指针操作（`new_node->prev = head` 和 `head->next->prev = new_node`）就是双向链表维护 prev 的代价。

### 4.4 指定位置插入

```c
int insert_by_pos(dbnode_p head, int pos, datatype data)
{
    // 1. 检查 pos 合法性（pos >= 0）
    if (pos < 0) return -1;
    
    // 2. 遍历到 pos 位置的前一个节点
    dbnode_p p = head;
    int i = 0;
    while (p->next != NULL && i < pos)
    {
        p = p->next;
        i++;
    }
    // 如果 pos 超过了链表长度，在后面追加
    // 此时 p 指向插入位置的前一个节点
    
    // 3. 创建新节点
    dbnode_p new_node = malloc(sizeof(dbnode_t));
    if (new_node == NULL) return -1;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    // 4. 链接新节点
    new_node->next = p->next;         // 新节点指向后一个节点
    new_node->prev = p;               // 新节点指向前一个节点
    
    if (p->next != NULL)              // 如果后一个节点存在
        p->next->prev = new_node;     // 后一个节点的 prev 指向新节点
    
    p->next = new_node;               // 前一个节点的 next 指向新节点
    
    return 0;
}
```

**重点：四步指针修改的顺序**
```
第1步：new_node->next = p->next    新节点先抓住后一个节点
第2步：new_node->prev = p          新节点再抓住前一个节点
第3步：if (p->next) p->next->prev = new_node  后一个节点放开 p，指向新节点
第4步：p->next = new_node          前一个节点放开后一个，指向新节点
```

**第 1 步必须在第 4 步之前做！**
如果先做 `p->next = new_node`，就丢失了原来 `p->next` 的地址（原来后一个节点找不到了），第 1 步就没法做了。

**过程推演：** 在 `head -> [1] <--> [2] <--> [4]` 的 pos=2（即第三个位置，32 位偏移）插入 3

```
插入前： head -> [0] <--> [1] <--> [2] <--> [4] -> NULL
                                          p        （p 在 pos=2 的前一个，即节点2）

步骤1： new_node->next = p->next = 节点4
步骤2： new_node->prev = p = 节点2

内存状态：  ... <--> [2] <--> [4] -> NULL
                       p
                       [3] ---> [4]
                        ^
                        |--- prev = 节点2

步骤3： p->next (= 节点4) != NULL，所以 p->next->prev = new_node
        即 节点4->prev = new_node

内存状态：  ... <--> [2] <--> [3] ---> [4] -> NULL
                                ^--- prev = 节点3

步骤4： p->next = new_node

完成：   head -> [0] <--> [1] <--> [2] <--> [3] <--> [4] -> NULL
```

### 4.5 指定位置删除

```c
int delete_by_pos(dbnode_p head, int pos)
{
    // 1. 检查链表是否为空
    if (head->next == NULL) return -1;
    
    // 2. 遍历到要删除的节点本身（不是前一个）
    dbnode_p p = head->next;   // p 指向第一个有效节点
    int i = 0;
    while (p->next != NULL && i < pos)
    {
        p = p->next;
        i++;
    }
    if (i != pos) return -1;   // pos 超出范围
    
    // 3. 修改指针，跳过 p
    p->prev->next = p->next;   // 前一个节点的 next 指向后一个节点
    
    if (p->next != NULL)       // 如果后一个节点存在
        p->next->prev = p->prev;  // 后一个节点的 prev 指向前一个节点
    
    // 4. 释放 p
    free(p);
    return 0;
}
```

**删除可以按情况拆解：**

**情况 A：删除第一个有效节点**
```
删除前： head -> [0] <--> [1] <--> [2] <--> [3] -> NULL

p = head->next = 节点1
p->prev = head，p->next = 节点2

步骤1： p->prev->next = p->next  ->  head->next = 节点2
步骤2： p->next != NULL，所以 p->next->prev = p->prev  ->  节点2->prev = head

删除后： head -> [0] <--> [2] <--> [3] -> NULL
```

**情况 B：删除中间节点**
```
删除前： head -> [0] <--> [1] <--> [2] <--> [3] -> NULL

p = 节点2（假设 pos=2）
p->prev = 节点1，p->next = 节点3

步骤1： 节点1->next = p->next = 节点3
步骤2： p->next != NULL，所以 节点3->prev = p->prev = 节点1

删除后： head -> [0] <--> [1] <--> [3] -> NULL
```

**情况 C：删除最后一个有效节点**
```
删除前： head -> [0] <--> [1] <--> [2] <--> [3] -> NULL

p = 节点3
p->prev = 节点2，p->next = NULL

步骤1： 节点2->next = p->next = NULL
步骤2： p->next == NULL，所以跳过（不执行）

删除后： head -> [0] <--> [1] <--> [2] -> NULL
```

**单向链表 vs 双向链表删除的对比：**

| 对比 | 单向链表 | 双向链表 |
|------|---------|---------|
| 遍历到谁 | 要删节点的前一个节点 | 要删的节点本身 |
| 如何找到前驱 | 遍历时记录 | 直接用 `p->prev` |
| 修改几个指针 | 1 个（前一个的 next） | 1~2 个（前一个的 next + 后一个的 prev） |

双向链表删除不需要知道前一个节点是谁——`p->prev` 直接告诉你了。这是双向链表相比单向链表最直观的优势。

### 4.6 正向遍历和反向遍历

```c
// 正向遍历（从头到尾）
void traverse_forward(dbnode_p head)
{
    dbnode_p p = head->next;    // 跳过头节点
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 反向遍历（从尾到头）—— 这是单向链表做不到的
void traverse_backward(dbnode_p head)
{
    // 1. 先找到最后一个节点
    dbnode_p p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    // 此时 p 指向最后一个有效节点（如果链表为空，p 指向 head）
    
    // 2. 从后往前遍历
    while (p != head)    // 回到头节点时停止（头节点不存数据）
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}
```

反向遍历的路径追踪：
```
head -> [0] <--> [1] <--> [2] <--> [3] -> NULL

正向： head->next = 1 -> 2 -> 3 -> NULL（结束）
反向： 先遍历到尾节点 3 -> 3->prev = 2 -> 2->prev = 1 -> 1->prev = head（停）

实现了："我想从尾部往前看"的需求
```

### 4.7 按值查找

```c
// 按值查找，返回节点指针（找不到返回 NULL）
dbnode_p find_by_value(dbnode_p head, datatype value)
{
    dbnode_p p = head->next;
    while (p != NULL)
    {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return NULL;
}
```

和单向链表一模一样，因为按值查找本质上就是遍历，不依赖于 prev 或 next 的区别。

### 4.8 销毁链表

```c
void destroy_list(dbnode_p head)
{
    dbnode_p p = head->next;    // 从第一个有效节点开始
    dbnode_p tmp;
    
    while (p != NULL)
    {
        tmp = p->next;          // 保存下一个节点
        free(p);                // 释放当前节点
        p = tmp;                // 指向下一个
    }
    
    // 最后释放头节点
    free(head);
}
```

销毁的顺序是**从头到尾逐个释放**。必须先保存 `p->next` 再释放 `p`，否则释放了 `p` 之后 `p->next` 就访问不到了。

---

## 五、边界情况汇总表

| 操作 | 空链表 | 只有一个有效节点 | 操作第一个节点 | 操作最后一个节点 |
|------|--------|----------------|--------------|----------------|
| 头插 | `head->next = new`，`new->prev = head` | 同左侧 | 标准流程 | 不影响 |
| 尾插 | `head->next = new`，`new->prev = head` | 同左侧 | 不影响 | `p->next = new; new->prev = p`（p 是原最后一个） |
| 指定位置插入 | pos=0 时可以，否则报错 | pos 范围 0~1 | 同头插 | 同尾插 |
| 指定位置删除 | 报错（链表为空） | 删完后 `head->next = NULL` | `p->prev (=head)->next = p->next`；`p->next->prev = head` | `p->prev->next = NULL`（不用动 prev） |
| 正向遍历 | 直接不打印 | 正常遍历 | 不影响 | 不影响 |
| 反向遍历 | 直接不打印 | 正常遍历 | 不影响 | 不影响 |
| 按值查找 | 返回 NULL | 正常返回 | 不影响 | 不影响 |

---

## 六、时间复杂度总结

| 操作 | 单向链表 | 双向链表 |
|------|---------|---------|
| 创建头节点 | O(1) | O(1) |
| 头插 | O(1) | O(1) |
| 尾插（已知尾指针） | O(1) | O(1) |
| 尾插（无尾指针） | O(n) | O(n) |
| 指定位置插入 | O(n) | O(n) |
| 删除（已知节点指针） | O(n)（需找前驱） | O(1) |
| 指定位置删除 | O(n) | O(n) |
| 正向遍历 | O(n) | O(n) |
| 反向遍历 | 不支持 | O(n) |
| 按值查找 | O(n) | O(n) |
| 销毁 | O(n) | O(n) |

**最显著的区别：**
- 如果已经拿到要删除节点的指针，双向链表的删除是 **O(1)**，单向链表是 **O(n)**
- 反向遍历只有双向链表才支持

---

## 七、双向链表 vs 单向链表总结

| 对比维度 | 单向链表 | 双向链表 |
|---------|---------|---------|
| 节点结构 | `data + next` | `prev + data + next` |
| 指针数量 | 1 个 | 2 个 |
| 每个节点内存（64位）| 数据 + 8 字节 | 数据 + 16 字节 |
| 遍历方向 | 只能从头到尾 | 双向均可 |
| 删除已知节点 | O(n)（需找前驱）| O(1)（prev 直接给出）|
| 插入修改指针数 | 2 个 | 3~4 个 |
| 代码复杂度 | 简单 | 稍微复杂一点 |
| 适用场景 | 简单的顺序存储 | 需要频繁双向遍历或频繁删除已知节点 |

---

## 八、完整代码（放在文件最下方）

```c
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct double_node
{
    datatype data;
    struct double_node *prev;
    struct double_node *next;
}dbnode_t, *dbnode_p;

// 1. 创建头节点
dbnode_p create_head()
{
    dbnode_p head = malloc(sizeof(dbnode_t));
    if (head == NULL) return NULL;
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

// 2. 尾插
dbnode_p insert_tail(dbnode_p head, datatype data)
{
    dbnode_p new_node = malloc(sizeof(dbnode_t));
    if (new_node == NULL) return NULL;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    dbnode_p p = head;
    while (p->next != NULL)
        p = p->next;
    
    p->next = new_node;
    new_node->prev = p;
    return new_node;
}

// 3. 头插
int insert_head(dbnode_p head, datatype data)
{
    dbnode_p new_node = malloc(sizeof(dbnode_t));
    if (new_node == NULL) return -1;
    new_node->data = data;
    new_node->prev = head;
    new_node->next = head->next;
    
    if (head->next != NULL)
        head->next->prev = new_node;
    
    head->next = new_node;
    return 0;
}

// 4. 指定位置插入
int insert_by_pos(dbnode_p head, int pos, datatype data)
{
    if (pos < 0) return -1;
    
    dbnode_p p = head;
    int i = 0;
    while (p->next != NULL && i < pos)
    {
        p = p->next;
        i++;
    }
    if (i != pos) return -1;
    
    dbnode_p new_node = malloc(sizeof(dbnode_t));
    if (new_node == NULL) return -1;
    new_node->data = data;
    
    new_node->next = p->next;
    new_node->prev = p;
    
    if (p->next != NULL)
        p->next->prev = new_node;
    
    p->next = new_node;
    return 0;
}

// 5. 指定位置删除
int delete_by_pos(dbnode_p head, int pos)
{
    if (head->next == NULL || pos < 0) return -1;
    
    dbnode_p p = head->next;
    int i = 0;
    while (p->next != NULL && i < pos)
    {
        p = p->next;
        i++;
    }
    if (i != pos) return -1;
    
    p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;
    
    free(p);
    return 0;
}

// 6. 正向遍历
void traverse_forward(dbnode_p head)
{
    dbnode_p p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 7. 反向遍历
void traverse_backward(dbnode_p head)
{
    dbnode_p p = head;
    while (p->next != NULL)
        p = p->next;
    
    while (p != head)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

// 8. 按值查找
dbnode_p find_by_value(dbnode_p head, datatype value)
{
    dbnode_p p = head->next;
    while (p != NULL)
    {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return NULL;
}

// 9. 销毁链表
void destroy_list(dbnode_p head)
{
    dbnode_p p = head->next;
    dbnode_p tmp;
    while (p != NULL)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(head);
}

// 10. 求长度
int list_length(dbnode_p head)
{
    dbnode_p p = head->next;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

// ========== 测试用例 ==========
int main()
{
    // 1. 创建链表
    dbnode_p head = create_head();
    
    // 2. 尾插 5 个节点：1 2 3 4 5
    for (int i = 1; i <= 5; i++)
        insert_tail(head, i);
    
    printf("尾插 5 个后正向遍历：");
    traverse_forward(head);     // 输出：1 2 3 4 5
    
    // 3. 头插 2 个节点：0 -1
    insert_head(head, 0);       // 头插 0
    insert_head(head, -1);      // 头插 -1
    
    printf("头插 2 个后正向遍历：");
    traverse_forward(head);     // 输出：-1 0 1 2 3 4 5
    
    // 4. 删除第 3 个节点（偏移2，值是1）
    delete_by_pos(head, 2);
    printf("删除 pos=2 后正向遍历：");
    traverse_forward(head);     // 输出：-1 0 2 3 4 5
    
    // 5. 删除第一个有效节点（偏移0，值是-1）
    delete_by_pos(head, 0);
    printf("删除第一个后正向遍历：");
    traverse_forward(head);     // 输出：0 2 3 4 5
    
    // 6. 删除最后一个有效节点（偏移4，值是5）
    delete_by_pos(head, list_length(head) - 1);
    printf("删除最后一个后正向遍历：");
    traverse_forward(head);     // 输出：0 2 3 4
    
    // 7. 反向遍历
    printf("反向遍历：");
    traverse_backward(head);    // 输出：4 3 2 0
    
    // 8. 按值查找
    dbnode_p found = find_by_value(head, 3);
    if (found != NULL)
        printf("按值查找 3：找到，data=%d\n", found->data);
    else
        printf("按值查找 3：未找到\n");
    
    // 9. 销毁
    destroy_list(head);
    printf("链表已销毁\n");
    
    return 0;
}
```

编译命令：
```bash
gcc -o test doublylinkedlist.c
./test
```

预期输出：
```
尾插 5 个后正向遍历：1 2 3 4 5
头插 2 个后正向遍历：-1 0 1 2 3 4 5
删除 pos=2 后正向遍历：-1 0 2 3 4 5
删除第一个后正向遍历：0 2 3 4 5
删除最后一个后正向遍历：0 2 3 4
反向遍历：4 3 2 0
按值查找 3：找到，data=3
链表已销毁