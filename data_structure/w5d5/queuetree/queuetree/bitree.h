#ifndef _BITREE_H_
#define _BITREE_H_
typedef char datatype_tree;
typedef struct tree_node_t
{
	datatype_tree data;//数据域 
	struct tree_node_t *lchild;//左子指针
	struct tree_node_t *rchild;//右子指针
}bitree_t;

//前序遍历
void preOrder(bitree_t *r);//r二叉树根节点的指针
//中序遍历
void inOrder(bitree_t * r);
//后序遍历
void postOrder(bitree_t *r);
//遍历二叉树 
//s 代表的是打印提示, void (*p)(bitree_t *)函数指针  r遍历的树
void showBitree(char *s,void (*p)(bitree_t *),bitree_t *r);
//创建二叉树,用递归函数创建
bitree_t *createBitree();
//层次遍历
void unOrder(bitree_t *r);

#endif
