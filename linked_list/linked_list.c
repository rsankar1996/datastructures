#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int init(list_t ** head, int data)
{
	*head = (list_t *)malloc(sizeof(list_t*));
	if (NULL == *head)
	{
		printf("ERR: Linked list init failed\r\n");
		return -1;
	}
	
	(*head)->data = data;
	(*head)->next = NULL;
	
	printf("DBG: Linked list created with only head allocation\r\n");
	
	return 0;
}

void show (list_t * node)
{
	while (NULL != node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\r\n");
}

int append(list_t ** head, int data)
{
	list_t * node = *head;
	list_t * new_node = NULL;
	
	new_node = (list_t *)malloc(sizeof(list_t*));
	if (NULL == new_node)
	{
		printf("ERR: Linked list init failed\r\n");
		return -1;
	}
	
	while (NULL != node->next)
	{
		node = node->next;
	}
	
	node->next = new_node;
	new_node->next = NULL;
	new_node->data = data;
	
	return 0;
}

int remove_tail(list_t ** head)
{
	list_t * node = *head;
	list_t * tmp = NULL;
	
	while (NULL != node->next)
	{
		tmp = node;
		node = node->next;
	}
	
	tmp->next = NULL;
	free(node);

	return 0;
}

int add_pos(list_t ** head, int pos, int data)
{
	list_t * node = *head;
	list_t * tmp = NULL;
	list_t * new = NULL;
	int i = 0;
	
	while (i != pos)
	{
		i++;
		tmp = node;
		node = node->next;
	}
	
	new = (list_t *)malloc(sizeof(list_t));
	if (NULL == new)
	{
		printf("ERR: memory allocation failed for new node\r\n");
		return -1;
	}
	
	new->data = data;
	new->next = node;
	tmp->next = new;
	
	return 0;
}

int remove_pos(list_t ** head, int pos)
{
	list_t * curr = *head;
	list_t * prev = NULL;
	int i = 0;
	
	while (i != pos)
	{
		i++;
		
		if (NULL == curr)
		{
			printf("ERR: index out of bound\r\n");
			return -1;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	prev->next = curr->next;
	free(curr);

	return 0;
}
