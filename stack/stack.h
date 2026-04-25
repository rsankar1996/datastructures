#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef struct
{
	int * mem;
	int top;
	int size;
} stack_t;

int init(stack_t * stack, int size);
int is_empty(stack_t * stack);
int is_full(stack_t * stack);
int push(stack_t * stack, int data);
int pop(stack_t * stack, int * data);


#endif /* _STACK_H */
