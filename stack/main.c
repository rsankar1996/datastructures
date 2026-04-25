#include <stdio.h>
#include "stack.h"

#define STACK_MAX		(5)

int main()
{
	stack_t stack1;
	int data;
	
	if (0 == init(&stack1, STACK_MAX))
	{
		printf("INF: stack init success\r\n");
	}
	
	push(&stack1, 1);
	push(&stack1, 2);
	push(&stack1, 3);
	push(&stack1, 4);
	push(&stack1, 5);
	push(&stack1, 6);
	pop(&stack1, &data);
	pop(&stack1, &data);
	pop(&stack1, &data);
	pop(&stack1, &data);
	pop(&stack1, &data);
	pop(&stack1, &data);
	pop(&stack1, &data);

	return 0;
}
