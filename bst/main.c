#include <stdlib.h>
#include <stdio.h>

typedef struct bst
{
	int data;
	struct bst * left;
	struct bst * right;
} bst_t;

void bst_traverse(bst_t * root)
{
	bst_t * node = root;
	
	if (NULL != node->left)
	{
		bst_traverse (node->left);
	}
	
	printf("%d ", node->data);
	
	if (NULL != node->right)
	{
		bst_traverse (node->right);
	}
}

bst_t * add_node (int data)
{
	bst_t * root = (bst_t *) malloc (sizeof (bst_t));
	
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	
	return root;
}

bst_t * insert_node (bst_t * root, int data)
{
	if (NULL == root)
	{
		return add_node (data);
	}
	
	if (data < (root->data))
	{
		root->left = insert_node (root->left, data);
	}
	else if (data > (root->data))
	{
		root->right = insert_node (root->right, data);
	}
	
	return root;
}

int main()
{
	bst_t * root = add_node(10);
	
	bst_traverse(root);
	
	root = insert_node (root, 20);
	
	bst_traverse(root);

	return 0;
}
