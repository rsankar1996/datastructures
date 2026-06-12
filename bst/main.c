#include <stdlib.h>
#include <stdio.h>

typedef struct btree
{
	int key;
	struct btree * lchild;
	struct btree * rchild;
} btree_t;

/*
Pre-order traversal 
---------------------------
1. Visit the root node
2. Traverse the left subtree of root node in preorder (L)
3. Traverse the right subtree of root node in preorder (R)
*/

void pre_order_trv (btree_t * root)
{
	if (NULL == root)
	{
		return;
	}
	
	printf("%d ", root->key);
	
	pre_order_trv(root->lchild);
	pre_order_trv(root->rchild);
}

/*
Inorder traversal
-----------------------
1. Traverse the left subtree of root node in in-order (L)
2. Visit the root
3. Traverse the right subtree of root node in in-order (R)
*/

void in_order_trv (btree_t * root)
{
	if (NULL == root)
	{
		return;
	}
	
	in_order_trv(root->lchild);
	printf("%d ", root->key);
	in_order_trv(root->rchild);
}

/*
Post order traversal
---------------------------
1. Traverse the left subtree of root node in post-order (L)
2. Traverse the right subtree of root node in in-order (R)
3. Visit the root node
*/
void post_order_trv (btree_t * root)
{
	if (NULL == root)
	{
		return;
	}
	
	post_order_trv(root->lchild);
	printf("%d ", root->key);
	post_order_trv(root->rchild);
}

int main()
{

	return 0;
}
