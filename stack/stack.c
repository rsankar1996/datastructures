#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int init(stack_t * stack, int size)
{	
	if (NULL != stack->mem)
	{
		printf("ERR: stack memory already allocated\r\n");
		return -1;
	}
	
	stack->mem = (int *)malloc(size * sizeof(int));
	if (NULL == stack->mem)
	{
		printf("ERR: Stack memory allocation failed\r\n");
		return -1;
	}
	
	stack->top = -1;
	stack->size = size;
	
	return 0;
}

int is_empty(stack_t * stack)
{
	if (-1 == stack->top)
	{
		return 0;
	}

	return -1;
}

int is_full(stack_t * stack)
{
	if ((stack->size - 1) == stack->top)
	{
		return 0;
	}
	
	return -1;
}

int push(stack_t * stack, int data)
{
	if (0 == is_full(stack))
	{
		printf("ERR: Stack is full\r\n");
		printf("DBG: Stack push failed for %d\r\n", data);
		return -1;
	}
	
	stack->top++;
	stack->mem[stack->top] = data;
	
	printf("DBG: Stack push success for %d\r\n", data);
	
	return 0;
}

int pop(stack_t * stack, int * data)
{
	if (NULL == data)
	{
		printf("ERR: memory not allocated for data\r\n");
		return -1;
	}

	if (0 == is_empty(stack))
	{
		printf("ERR: Stack is empty\r\n");
		printf("DBG: Stack pop failed at %d\r\n", stack->top);
		return -1;
	}
	
	*data = stack->mem[stack->top];
	stack->top--;
	
	printf("DBG: Stack pop success, top at %d\r\n", stack->top);
	
	return 0;
}
