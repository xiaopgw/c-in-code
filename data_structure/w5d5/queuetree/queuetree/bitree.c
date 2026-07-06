#include "bitree.h"
#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>
//前序遍历
void preOrder(bitree_t *r)//r二叉树根节点的指针
{
	if(r == NULL)//递归函数的结束条件
		return;
	printf("%c ",r->data);//根
	preOrder(r->lchild);//左
	preOrder(r->rchild);//右
}
//中序遍历
void inOrder(bitree_t * r)
{
	if(r == NULL)//递归的结束条件
		return;
	inOrder(r->lchild);//左
	printf("%c ",r->data);//根
	inOrder(r->rchild);//右
}
//后序遍历
void postOrder(bitree_t *r)
{
	if(r == NULL)//递归函数的结束条件
		return;
	postOrder(r->lchild);//左
	postOrder(r->rchild);//右
	printf("%c ",r->data);//根
}
//遍历二叉树 
//s 代表的是打印提示, void (*p)(bitree_t *)函数指针  r遍历的树
void showBitree(char *s,void (*p)(bitree_t *),bitree_t *r)
{
	printf("%s",s);
	p(r);
	printf("\n");
}
//创建二叉树,用递归函数创建
bitree_t *createBitree()
{//root 
//	ABD###CE##F##
	bitree_t *r = NULL;//用来保存二叉树的根节点
	char ch;
	scanf("%c",&ch);
	if(ch == '#')//输入是'#'，代表没有左子或右子
		return NULL;
	r = (bitree_t *)malloc(sizeof(bitree_t));
	if(NULL == r)
	{
		perror("r malloc failed");
		return NULL;
	}
	r->data = ch;
	r->lchild = createBitree();
	r->rchild = createBitree();
	return r;
}

//层次遍历
void unOrder(bitree_t *r)
{
	//1.创建一个队列,队列的数据域变成指向树节点的指针
	linkqueue_t *p = createEmptyLinkQueue();
	if(r != NULL)
		inLinkQueue(p,r);
	//2.循环打印
	while(!isEmptyLinkQueue(p))
	{
		r = outLinkQueue(p);
		printf("%c ",r->data);
		if(r->lchild != NULL)//只要左子不为空，就入列，之后出列的时候打印
			inLinkQueue(p,r->lchild);
		if(r->rchild != NULL)//只要右子不为空，就入列，之后出列的时候打印
			inLinkQueue(p,r->rchild);
	}
}
