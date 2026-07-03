# 链表
增删改查

## 增
-尾插
-头插
-指定位置插（偏移位置）
-转置链表
## 删
(尾删)
(头删)
-指定位置删
-指定元素删（所有相同元素）
-全删
## 改
(指定元素改（所有相同元素）)
-指定位置改
## 查
-遍历
-指定元素查位置（偏移位置）
-指定位置（偏移位置）查元素
## 其他
-计算长度
-判断是否为空

```c
// 创建头节点
sp LinkedListHead()
{
    // 开辟头节点(malloc会返回NULL所以不用预初始化)
    sp p = malloc(sizeof(sl));
    // 判断开辟是否成功
    if (p == NULL)
    {
        perror("X->");
        return NULL;
    }
    // 初始化头节点
    p->poit = NULL;
    return p;
}
// 在指定位置插入函数
sp InsertLinkList(sp head, int post, datatype data)
{
    // 判断post是否存在
    if (post < 0 || post > LengthLinkList(head))
    {
        printf("X");
        return NULL;
    }
    // 创建一个节点
    sp p = malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return NULL;
    }
    // 初始化节点
    p->data = data;
    p->poit = NULL;
    // 把节点放入链表的指定位置中
    // 循环到指定位置之前
    for (int i = 0; i < post; i++)
    {
        head = head->poit;
    }
    // 把增加的节点指向指定位置后面的节点，把指定位置前链接到增加的节点
    p->poit = head->poit;
    head->poit = p;
    // 返回指定位置的地址
    return p;
}
// 遍历链表
void ShowLinkList(sp p)
{
    //有头链表遍历
    while (p->poit != NULL)
    {
        p = p->poit;
        printf("%d ", p->data);
    }
    putchar(10);
    printf("++++++++++++++++++++++++++++++++\n");
}
// 计算链表长度(这里不包括头节点)
int LengthLinkList(sp p)
{
    int i = 0;
    //有头链表遍历，遍历一遍加一
    while (p->poit != NULL)
    {
        p = p->poit;
        i++;
    }
    return i;
}
// 清空链表
void CleanLinkList(sp head)
{
    //跳过头链表清空链表
    //判断链表现在是否指着null
    //当删除一个节点时需要有个亚节点，存当前节点，把他删除
    //在删除前需要把前一个节点连接到要删除的节点后面的节点
    while (head->poit != NULL)
    {
        sp p = head->poit;
        head->poit = p->poit;
        free(p);
    }
}
// 头插尾插（这么爽的吗）
int InsertLinkListHead_Tail(sp head, datatype data)
{
    //插入第一步得有插入的东西，创建插入的节点
    sp p = malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return -1;
    }
    p->data = data;
    //把插入的节点链接到偏移0的节点
    p->poit = head->poit;
    //把头节点链接到插入的节点
    head->poit = p;
    //尾插
    p = malloc(sizeof(sl));
    if (p == NULL)
    {
        perror("X->");
        return -1;
    }
    p->data = data;
    p->poit = NULL;
    //循环遍历到尾节点
    while (head->poit != NULL)
    {
        //有头遍历
        head = head->poit;
    }
    head->poit = p;
    return 0;
}
//删除指定偏移量的位置
int DeleteLinkListPost(sp head, int post)
{
    //判断post是否存在
    if (post < 0 || post >= LengthLinkList(head))
    {
        printf("X");
        return -1;
    }
    //遍历到指定的偏移量的位置的前面的节点
    for (int i = 0; i < post; i++)
    {
        head = head->poit;
    }
    //需要有个亚节点存删除的节点
    sp p = head->poit;
    //把当前的位置链接到删除位置的下一个的节点
    head->poit = p->poit;
    //删除目标节点
    free(p);
    return 0;
}
// 删除指定所有元素
int DeleteLinkList(sp head, datatype data)
{
    //同样删除元素需要有个亚节点存储要删的节点
    //我们选择控制修改当前节点的方法，需要创建一个亚节点跳过头节点
    sp h = head;
    sp p = head->poit;
    //遍历查找是否有相同的元素
    while (p != NULL)
    {
        //找到则删掉，并把前一个节点连接到删掉节点的后一个节点
        if(p->data == data)
        {
            h->poit = p->poit;
            free(p);
            p = h->poit;
        }
        //没找到则往后移动
        else
        {
            h = h->poit;
            p = p->poit;
        }
    }
    return 0;
}
// 修改指定偏移量位置的元素
sp ChangeLinklistData(sp head, int post, datatype data)
{
    
    //找到指定的位置的当前位置
    for (int i = 0; i <= post; i++)
    {
        head = head->poit;
    }
    //修改值
    head->data = data;
    return head;
}
// 查找指定元素的位置
int SearchLinkListData(sp head, datatype data)
{
    //循环遍历查找位置，有头遍历，需要有个变量记录
    int i = 0;
    while (head->poit != NULL)
    {
        head = head->poit;
        
        if (head->data == data)
        {
            return i;
        }
        //自增放最后可以直接打印偏移量
        i++;
    }
    return -1;
}
// 指定位置查元素
datatype SearchLinkListPost(sp head, int post)
{
    if (post < 0 || post >= LengthLinkList(head))
    {
        printf("X\n");
        return -1;
    }
    // 循环找到指定的位置，然后输出
    for (int i = 0; i <= post; i++)
    {
        head = head->poit;
    }
    return head->data;
}
// 转置链表
void ReverseLinkList(sp head)
{
    // 这个函数的作用是把整个函数反转
    // 断掉之前我需要一个亚节点2存第一个2节点
    sp t2 = head->poit;
    // 我需要先定义一个亚节点1存头节点
    // 然后需要把头结点断掉
    sp h1 = head;
    head->poit = NULL;
    while (t2 != NULL)
    {
    // 在此之前我需要定义一个亚节点3存当亚节点2断掉的时候保留链表
        sp q3 = t2->poit;
        // 然后就需要循环把亚节点2指向亚节点1的指针域，也就是NULL
        t2->poit = h1->poit;
        // 然后把亚节点1指向亚节点2
        h1->poit = t2;
        // 最后需要把亚节点2指回链表
        t2 = q3;
    }
}
```

问题：
关于有头无头遍历条件脑子里很模糊
删除指定元素不理解为什么到了最后一个元素不会段错误