# 二叉树

## 一、从线性结构到树形结构

你之前学过的所有内容都属于**线性结构**：

```
顺序表、链表、栈、队列  -->  一对一关系
   [A] -- [B] -- [C] -- [D]
```

每个元素只有一个直接前驱和一个直接后继，像一条线串起来的珠子。

而**树形结构**是一对多的关系：

```
        [A]          <-- 根节点（没有前驱）
       /   \
     [B]   [C]       <-- 分支节点（既有前驱也有后继）
     / \     \
   [D] [E]   [F]     <-- 叶子节点（没有后继）
```

**为什么需要树？**
- 现实中有大量层次关系的数据：文件系统、公司组织架构、网页DOM、表达式语法树
- 二叉树的搜索效率远高于线性结构（O(log n) vs O(n)）
- 很多算法（排序、压缩、编码）的底层都依赖树

---

## 二、树的术语

```
            [A]                       深度0
           /   \
         [B]   [C]                   深度1
        /  \     \
      [D]  [E]   [F]                 深度2
```

| 术语 | 解释 | 图中对应 |
|------|------|---------|
| **根节点** | 树中最顶层的节点，没有父节点 | A |
| **父节点** | 某个节点的直接上级 | B 是 D、E 的父节点 |
| **子节点** | 某个节点的直接下级 | D、E 是 B 的子节点 |
| **叶子节点** | 没有子节点的节点 | D、E、F |
| **兄弟节点** | 有同一个父节点的节点 | B 和 C 是兄弟 |
| **深度** | 从根节点到该节点的层数（根为0） | D 的深度是 2 |
| **高度** | 从该节点到最远叶子节点的层数 | A 的高度是 2 |
| **子树** | 树中任何一个节点及其后代 | B-D-E 构成一棵子树 |

**一个容易混淆的概念——度和阶：**
- **节点的度**：该节点拥有的子节点个数
  - 叶子节点的度 = 0
  - 二叉树中，每个节点的度最大为 2
- **树的度**：树中所有节点的度的最大值

---

## 三、二叉树的定义

**二叉树（Binary Tree）**：每个节点最多有 2 个子节点的树。

```
         [A]                     [A]                     [A]
        /   \                    /                       / \
      [B]   [C]                [B]                     [B] [C]
     / \                         \
   [D] [E]                       [C]
 完全二叉树                 左斜树                  满二叉树
```

### 3.1 二叉树的五种基本形态

```
 1. 空二叉树           2. 只有根节点        3. 只有左子树
    NULL                 [A]                  [A]
                                               /
                                             [B]

 4. 只有右子树          5. 左右子树都有
    [A]                   [A]
     \                   / \
     [B]               [B] [C]
```

### 3.2 满二叉树和完全二叉树

**满二叉树：** 每一层都满的二叉树
```
           [1]
         /     \
       [2]     [3]
      /  \    /  \
    [4] [5]  [6] [7]
```
- 如果有 k 层，节点总数 = 2^(k+1) - 1（根为第0层）
- 每个节点要么是叶子，要么有两个子节点

**完全二叉树：** 除了最后一层，上面每一层都是满的，最后一层的节点都靠左排列
```
           [1]
         /     \
       [2]     [3]
      /  \    /
    [4] [5] [6]
```
- 最后一层允许缺右边，不允许缺左边
- 满二叉树一定是完全二叉树，反之不一定

完全二叉树有一个**非常非常重要的性质**（后面数组存储时会用到）：
```
如果根节点编号为 0，那么：
  左孩子编号 = 父节点编号 * 2 + 1
  右孩子编号 = 父节点编号 * 2 + 2
  父节点编号 = (子节点编号 - 1) / 2
```

---

## 四、二叉树的节点结构体定义

```c
typedef int datatype;

typedef struct binary_node
{
    datatype data;              // 数据域
    struct binary_node *lchild; // 左孩子指针
    struct binary_node *rchild; // 右孩子指针
}bin_node_t, *bin_node_p;
```

注意：和链表节点对比

```
链表节点：     data | next          -- 一个指针（指向后继）
二叉树节点：   data | lchild | rchild  -- 两个指针（指向左子和右子）
```

从链表的"一个节点一个后继"到二叉树的"一个节点两个后继"，这就是从线性到树形的本质跨越。

---

## 五、二叉树的创建

### 5.1 手动创建（用于学习和调试）

```c
// 创建单个节点
bin_node_p create_node(datatype data)
{
    bin_node_p p = malloc(sizeof(bin_node_t));
    if (p == NULL) return NULL;
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

// 手动构建一棵树
int main()
{
    //          [1]
    //         /   \
    //       [2]   [3]
    //      /  \
    //    [4]  [5]
    
    bin_node_p root = create_node(1);
    bin_node_p n2   = create_node(2);
    bin_node_p n3   = create_node(3);
    bin_node_p n4   = create_node(4);
    bin_node_p n5   = create_node(5);
    
    root->lchild = n2;
    root->rchild = n3;
    n2->lchild = n4;
    n2->rchild = n5;
    
    return 0;
}
```

### 5.2 递归创建（通过输入序列）

```c
// 前序创建：输入序列如 1 2 4 -1 -1 5 -1 -1 3 -1 -1
// -1 表示该位置没有节点（空）
bin_node_p create_tree()
{
    datatype data;
    scanf("%d", &data);
    
    if (data == -1)
        return NULL;             // 空节点
    
    bin_node_p p = malloc(sizeof(bin_node_t));
    p->data = data;
    p->lchild = create_tree();   // 递归创建左子树
    p->rchild = create_tree();   // 递归创建右子树
    return p;
}
```

输入序列 `1 2 4 -1 -1 5 -1 -1 3 -1 -1` 构建的树：

```
         [1]
        /   \
      [2]   [3]
     /  \
   [4]  [5]

输入顺序解释（前序）：
  1 -> 创建根节点
  2 -> 创建左孩子
  4 -> 创建左孩子的左孩子
  -1 -> 4的左孩子为空，返回
  -1 -> 4的右孩子为空，返回
  5 -> 2的右孩子
  -1 -> 5的左孩子为空
  -1 -> 5的右孩子为空
  3 -> 1的右孩子
  -1 -> 3的左孩子为空
  -1 -> 3的右孩子为空
```

这里的**-1 表示空节点**，是递归创建的终止条件。

---

## 六、二叉树的遍历（核心考点）

遍历就是按照一定规则访问树中的每个节点，且每个节点只访问一次。

有四种遍历方式，前三种用递归实现非常直观：

### 6.1 前序遍历（Preorder）

**规则：先访问根节点，再遍历左子树，最后遍历右子树**
```
访问顺序：根 -> 左 -> 右
```

```
         [1]
        /   \
      [2]   [3]
     /  \
   [4]  [5]

前序遍历结果：1 2 4 5 3
```

```c
void preorder(bin_node_p root)
{
    if (root == NULL) return;
    
    printf("%d ", root->data);  // 先访问根
    preorder(root->lchild);     // 再遍历左子树
    preorder(root->rchild);     // 最后遍历右子树
}
```

**递归展开过程（非常重要，理解了才知道递归是怎么跑的）：**

```
preorder(1)
  |-- 打印 1
  |-- preorder(2)
  |     |-- 打印 2
  |     |-- preorder(4)
  |     |     |-- 打印 4
  |     |     |-- preorder(NULL) -> return
  |     |     |-- preorder(NULL) -> return
  |     |-- preorder(5)
  |           |-- 打印 5
  |           |-- preorder(NULL) -> return
  |           |-- preorder(NULL) -> return
  |-- preorder(3)
        |-- 打印 3
        |-- preorder(NULL) -> return
        |-- preorder(NULL) -> return

最终输出：1 2 4 5 3
```

### 6.2 中序遍历（Inorder）

**规则：先遍历左子树，再访问根节点，最后遍历右子树**
```
访问顺序：左 -> 根 -> 右
```

```
         [1]
        /   \
      [2]   [3]
     /  \
   [4]  [5]

中序遍历结果：4 2 5 1 3
```

```c
void inorder(bin_node_p root)
{
    if (root == NULL) return;
    
    inorder(root->lchild);      // 先遍历左子树
    printf("%d ", root->data);  // 再访问根
    inorder(root->rchild);      // 最后遍历右子树
}
```

中序遍历的一个重要应用：
- 对**二叉搜索树**做中序遍历，结果是**有序序列**

### 6.3 后序遍历（Postorder）

**规则：先遍历左子树，再遍历右子树，最后访问根节点**
```
访问顺序：左 -> 右 -> 根
```

```
         [1]
        /   \
      [2]   [3]
     /  \
   [4]  [5]

后序遍历结果：4 5 2 3 1
```

```c
void postorder(bin_node_p root)
{
    if (root == NULL) return;
    
    postorder(root->lchild);     // 先遍历左子树
    postorder(root->rchild);     // 再遍历右子树
    printf("%d ", root->data);   // 最后访问根
}
```

后序遍历的一个重要应用：
- **删除整棵树**——必须先删子节点，再删父节点，否则会内存泄漏

```c
void destroy_tree(bin_node_p root)
{
    if (root == NULL) return;
    
    destroy_tree(root->lchild);  // 先删左子树
    destroy_tree(root->rchild);  // 再删右子树
    free(root);                  // 最后删自己
}
```

### 6.4 层序遍历（Level Order）

**规则：从上到下、从左到右逐层遍历**

```
         [1]
        /   \
      [2]   [3]
     /  \     \
   [4]  [5]   [6]

层序遍历结果：1 2 3 4 5 6
```

层序遍历不能直接用递归实现，需要借助**队列**：

```c
#include "queue.h"  // 假设你已经实现了队列

void levelorder(bin_node_p root)
{
    if (root == NULL) return;
    
    queue_p q = create_queue();
    enqueue(q, root);             // 根节点入队
    
    while (!empty_queue(q))
    {
        bin_node_p p = dequeue(q); // 出队
        printf("%d ", p->data);    // 访问该节点
        
        if (p->lchild != NULL)
            enqueue(q, p->lchild); // 左孩子入队
        if (p->rchild != NULL)
            enqueue(q, p->rchild); // 右孩子入队
    }
    
    destroy_queue(q);
}
```

层序遍历的过程：

```
步骤1：根节点 1 入队
  队列：[1]

步骤2：1 出队并访问，左孩子 2 入队，右孩子 3 入队
  队列：[2, 3]
  输出：1

步骤3：2 出队并访问，左孩子 4 入队，右孩子 5 入队
  队列：[3, 4, 5]
  输出：1 2

步骤4：3 出队并访问，没有左孩子（NULL），右孩子 6 入队
  队列：[4, 5, 6]
  输出：1 2 3

步骤5：4 出队并访问，没有孩子
  队列：[5, 6]
  输出：1 2 3 4

步骤6：5 出队并访问
  队列：[6]
  输出：1 2 3 4 5

步骤7：6 出队并访问
  队列：[空]
  输出：1 2 3 4 5 6
```

### 6.5 四种遍历对比

```
         [1]
        /   \
      [2]   [3]
     /  \
   [4]  [5]
```

| 遍历方式 | 顺序 | 结果 | 口诀 |
|---------|------|------|------|
| 前序 | 根->左->右 | 1 2 4 5 3 | 根左右 |
| 中序 | 左->根->右 | 4 2 5 1 3 | 左根右 |
| 后序 | 左->右->根 | 4 5 2 3 1 | 左右根 |
| 层序 | 逐层从左到右 | 1 2 3 4 5 | 用队列 |

---

## 七、求树的深度和节点个数

### 7.1 求深度（高度）

```c
int max_depth(bin_node_p root)
{
    if (root == NULL)
        return 0;
    
    int left_depth  = max_depth(root->lchild);
    int right_depth = max_depth(root->rchild);
    
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}
```

递归展开理解：
```
         [1]
        /   \
      [2]   [3]
     /  \
   [4]  [5]

max_depth(1)
  |-- left_depth = max_depth(2)
  |     |-- left_depth = max_depth(4)
  |     |     |-- left_depth = max_depth(NULL) = 0
  |     |     |-- right_depth = max_depth(NULL) = 0
  |     |     |-- return max(0,0)+1 = 1
  |     |-- right_depth = max_depth(5)
  |     |     |-- left_depth = max_depth(NULL) = 0
  |     |     |-- right_depth = max_depth(NULL) = 0
  |     |     |-- return max(0,0)+1 = 1
  |     |-- return max(1,1)+1 = 2
  |-- right_depth = max_depth(3)
  |     |-- left_depth = max_depth(NULL) = 0
  |     |-- right_depth = max_depth(NULL) = 0
  |     |-- return max(0,0)+1 = 1
  |-- return max(2,1)+1 = 3

最终深度 = 3
```

### 7.2 求节点个数

```c
int count_nodes(bin_node_p root)
{
    if (root == NULL)
        return 0;
    
    return count_nodes(root->lchild) + count_nodes(root->rchild) + 1;
}
```

### 7.3 求叶子节点个数

```c
int count_leaves(bin_node_p root)
{
    if (root == NULL)
        return 0;
    
    // 左右孩子都为空，说明是叶子节点
    if (root->lchild == NULL && root->rchild == NULL)
        return 1;
    
    return count_leaves(root->lchild) + count_leaves(root->rchild);
}
```

---

## 八、二叉搜索树（BST）

二叉搜索树（Binary Search Tree）是一种特殊的二叉树，它满足以下性质：

```
对于树中的任意节点：
  - 左子树中所有节点的值 < 根节点的值
  - 右子树中所有节点的值 > 根节点的值
  - 左子树和右子树也分别满足这个性质
```

```
         [5]
        /   \
      [3]   [8]
     /  \   / \
   [2] [4] [6] [9]
```

### 8.1 BST 的查找

```c
bin_node_p bst_search(bin_node_p root, datatype key)
{
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return bst_search(root->lchild, key);  // 去左子树找
    else
        return bst_search(root->rchild, key);  // 去右子树找
}
```

每次查找都排除了一半的子树，时间复杂度 O(log n)。

### 8.2 BST 的插入

```c
bin_node_p bst_insert(bin_node_p root, datatype data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(bin_node_t));
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    
    if (data < root->data)
        root->lchild = bst_insert(root->lchild, data);
    else if (data > root->data)
        root->rchild = bst_insert(root->rchild, data);
    // 如果相等，不插入（BST 中不允许重复）
    
    return root;
}
```

### 8.3 BST 的中序遍历

对 BST 做中序遍历，结果是**升序序列**：

```
         [5]
        /   \
      [3]   [8]
     /  \   / \
   [2] [4] [6] [9]

中序遍历结果：2 3 4 5 6 8 9
```

这正是 BST 最核心的特性——它天生就有排序能力。

---

## 九、二叉树的性质汇总（记熟）

1. **第 i 层最多有 2^i 个节点**（根为第 0 层）
   - 第 0 层：2^0 = 1 个（根）
   - 第 1 层：2^1 = 2 个
   - 第 2 层：2^2 = 4 个

2. **深度为 k 的二叉树最多有 2^(k+1) - 1 个节点**（根为第 0 层）
   - 深度 3 最多：2^4 - 1 = 15 个

3. **叶子节点数 = 度为 2 的节点数 + 1**
   - 记法：n0 = n2 + 1
   - 推导：总节点数 n = n0 + n1 + n2，总边数 = n - 1 = n1 + 2*n2
   - 所以：n0 + n1 + n2 - 1 = n1 + 2*n2 -> n0 = n2 + 1

4. **完全二叉树的性质：**
   - 如果根节点编号为 0：
     - 左孩子编号 = 父节点编号 * 2 + 1
     - 右孩子编号 = 父节点编号 * 2 + 2
     - 父节点编号 = (子节点编号 - 1) / 2
   - 可以用数组存储，不需要指针

---

## 十、树的存储方式

### 10.1 链式存储（常用）

```c
typedef struct binary_node
{
    datatype data;
    struct binary_node *lchild;
    struct binary_node *rchild;
}bin_node_t, *bin_node_p;
```

每个节点包含数据 + 两个指针，灵活，适用所有二叉树。

### 10.2 顺序存储（数组 + 完全二叉树）

对于完全二叉树，可以利用编号性质用一维数组存储：

```c
// 完全二叉树用数组存
//         [1]
//        /   \
//      [2]   [3]
//     /  \   /
//   [4] [5] [6]

int tree[] = {1, 2, 3, 4, 5, 6};
//            0  1  2  3  4  5

// 访问：
// 根节点：tree[0]
// tree[2] 的左孩子：tree[2*2+1] = tree[5] = 6
// tree[3] 的右孩子：tree[3*2+2] = tree[8] -> 越界，说明没有右孩子
```

**优点：** 省内存，不需要指针，访问快
**缺点：** 只适用于完全二叉树，普通二叉树会浪费大量空间

---

## 十一、二叉树的核心递归思想总结

你之前学的栈和队列主要用循环，而二叉树的操作**大量依赖递归**。理解递归的关键：

```
1. 终止条件：root == NULL（空树）
2. 递归步骤：对左子树做同样操作 + 对右子树做同样操作
3. 返回值：在"归"的途中整合结果
```

举三个例子对比看看结构上的统一性：

```c
// 遍历
void xxxorder(bin_node_p root)
{
    if (root == NULL) return;
    // 前序：printf(root->data);
    xxxorder(root->lchild);
    // 中序：printf(root->data);
    xxxorder(root->rchild);
    // 后序：printf(root->data);
}

// 求深度
int max_depth(bin_node_p root)
{
    if (root == NULL) return 0;
    int l = max_depth(root->lchild);
    int r = max_depth(root->rchild);
    return (l > r ? l : r) + 1;
}

// 求节点数
int count_nodes(bin_node_p root)
{
    if (root == NULL) return 0;
    return count_nodes(root->lchild) + count_nodes(root->rchild) + 1;
}
```

所有递归函数的结构都是：
```
if (root == NULL) return 基值;
递归求左子树的结果;
递归求右子树的结果;
整合左右结果 + 当前节点 -> 返回;
```

---

## 十二、总结

```
二叉树 = 每个节点最多两个子节点的树

节点结构：data | lchild | rchild
          数据域  左指针  右指针

遍历方式（核心考点）：
  前序：根->左->右    stack结构（先访问根）
  中序：左->根->右    对BST结果是升序
  后序：左->右->根    先删子后删父
  层序：从上到下       队列实现

重要性质：
  第i层最多 2^i 个节点
  深度k最多 2^(k+1)-1 个节点
  叶子数 = 度为2的节点数 + 1
  完全二叉树可用数组存储

递归万能公式：
  if (NULL) return;
  处理左子树 + 处理右子树;
  在合适的位置访问根节点;
```

**你接下来应该做的事：**
1. 先读笔记，理解树的术语和遍历方式
2. 手动画一棵树，用 4 种遍历方式分别写出结果
3. 写代码实现：节点创建 -> 手动建树 -> 四种遍历 -> 求深度 -> 求节点数
4. 再写递归创建（输入序列建树）
5. 最后挑战 BST（二叉搜索树）的查找和插入