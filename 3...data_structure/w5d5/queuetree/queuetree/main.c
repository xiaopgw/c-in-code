#include "bitree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	bitree_t *r = createBitree();
	showBitree("前序:",preOrder,r);
	showBitree("中序:",inOrder,r);
	showBitree("后序:",postOrder,r);
	showBitree("层次:",unOrder,r);
	return 0;
}
