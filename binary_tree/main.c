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
	post_order_trv(root->rchild);
	printf("%d ", root->key);
}

/* 
Level order traversal
---------------------------------
*/

int height(btree_t* root) 
{
	if (root == NULL)
	{
		return 0;
	}

	int left_height = height(root->left);
	int right_height = height(root->right);

    	return max(left_height, right_height) + 1;
}

void print_given_level(btree_t* root, int level)
{
	if (root == NULL)
	{
		return;
	}

	if (level > 1)
	{
		print_given_level (root->left, (level - 1));
		print_given_level (root->right, (level - 1));
	}
	else if (level == 1)
	{
		printf ("%d ", root->data);
	}
}

void level_order_traversal(btree_t* root)
{
	int h = height(root);
	
	for (int i = 1; i <= h; i++)
	{
		print_given_level(root, i);
	}
}

/* 
Level order traversal using queue
----------------------------------------------
1. Push the root node into queue
2. Loop the queue until queue empty
3. Pop the queue
4. Push the left node into queue if available
5. Push the right node into queue if available
6. Repeat the step 2.
*/

int main()
{
	return 0;
}
