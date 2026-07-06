#include"my.h"
binnode_p CreateBinary(datatype data, int n)
{
    binnode_p lin = malloc(sizeof(binnode_t));
    if (lin == NULL)
    {
        perror("X->");
        return NULL;
    }
    // static int i = 1;
    // printf("%d ", i++);
    lin->data = data;
    if (data * 2 <= n)
    {
        lin->lchild = CreateBinary(data * 2, n);
    }
    else
    {
        lin->lchild = NULL;
    }

    if (data * 2 + 1 <= n)
    {
        lin->rchild = CreateBinary(data * 2 + 1, n);
    }
    else
    {
        lin->rchild = NULL;
    }
    return lin;
}
// 前
binnode_p ShowBinary(binnode_p root, int n)
{
    printf("%d ", root->data);
    if (root->lchild != NULL)
    {
        ShowBinary(root->lchild, n);
    }

    if (root->rchild != NULL)
    {
        
        ShowBinary(root->rchild, n);
    }
    return 0;
}

// 中
binnode_p ShowBinary2(binnode_p root, int n)
{
    
    if (root->data * 2 <= n)
    {
        ShowBinary(root->lchild, n);
        
    }
    printf("%d ", root->data);
    if (root->data * 2 + 1 <= n)
    {
        
        ShowBinary(root->rchild, n);
    }
    return 0;
}
// 后
binnode_p ShowBinary2(binnode_p root, int n)
{
    
    if (root->data * 2 <= n)
    {
        ShowBinary(root->lchild, n);
        
    }
    
    if (root->data * 2 + 1 <= n)
    {
        
        ShowBinary(root->rchild, n);
    }
    printf("%d ", root->data);
    return 0;
}

// 输入建立
binnode_p PushBinary()
{
    int data = 0;
    scanf("%d", &data);
    if (data == -1)
    {
       return NULL; 
    }
    
    binnode_p child = malloc(sizeof(binnode_t));
    if (child == NULL)
    {
        perror("X->");
        return NULL;
    }
    child->data = data;
    printf("%d ", child->data);
    child->lchild = PushBinary();
    child->rchild = PushBinary();
    return child;
}
// // 遍历（应该用层次遍历）// 层次遍历
// binnode_p ShowBinary(binnode_p root)
// {
//     int data = root->data;
//     if (data == -1)
//     {
//         return NULL;
//     }
//     printf("%d ", root->data);
    
//     root = root->lchild;
//     root = root->rchild;
//     root->lchild = ShowBinary(root);
//     root->rchild = ShowBinary(root);
// }