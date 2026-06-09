#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void fw_inspect (dlist_t * head)
{
	printf("List in FW: ");
	while (NULL != head)
	{
		printf("%d ", head->data);
		head = head->next;		
	}
	printf("\r\n");
}

void rv_inspect (dlist_t * head)
{
	printf("List in RV: ");
	while (NULL != head->next)
	{
		head = head->next;
	}

	while (NULL != head)
	{
		printf("%d ", head->data);
		head = head->prev;
	}
	printf("\r\n");
}

int init(dlist_t ** head, int data)
{
	if (NULL != *head)
	{
		printf("DBG: head already allocated\r\n");
		return 0;
	}
	
	*head = (dlist_t*) malloc (sizeof(dlist_t));
	if (NULL == *head)
	{
		printf("ERR: Memory allocation for node failed\r\n");
		return -1;
	}

	(*head)->data = data;
	(*head)->next = NULL;
	(*head)->prev = NULL;
	
	printf("DBG: Successfully allocated head node [%d] and created the list\r\n", data);
	
	return 0;
}

int append(dlist_t ** head, int data)
{
	dlist_t * node = *head;

	if (NULL == *head)
	{
		printf("ERR: head unallocated, perform init first\r\n");
		return -1;
	}

	while (NULL != node->next)
	{
		node = node->next;
	}
	
	dlist_t * new = (dlist_t *) malloc (sizeof(dlist_t));
	if (NULL == new)
	{
		printf("ERR: Memory allocation for node failed\r\n");
		return -1;
	}

	node->next = new;
	new->data = data;
	new->prev = node;
	new->next = NULL;
	
	printf("DBG: Successfully allocated new node [%d] and appended to the list\r\n", data);

	return 0;
}

int insert_at (dlist_t ** head, int index, int data)
{
	dlist_t * node = *head;
	dlist_t * prev = NULL;
	dlist_t * new = NULL;
	int i = index;
	
	if (NULL == node)
	{
		printf("ERR: head unallocated, perform init first\r\n");
		return -1;
	}
	
	while (0 != i)
	{
		i--;
		prev = node;
		node = node->next;
	}
	
	new = (dlist_t *) malloc (sizeof(dlist_t));
	if (NULL == new)
	{
		printf("ERR: memory allocation failed for node\r\n");
		return -1;
	}
	
	new->data = data;
	prev->next = new;
	new->prev = prev;
	new->next = node;
	node->prev = new;
	
	printf("DBG: Successfully allocated new node [%d] at index [%d] of list\r\n", data, index);
	return 0;
}

