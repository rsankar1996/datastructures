#include <stdio.h>
#include "queue.h"

int main()
{
	queue_t queue1;
	int data;
	
	if (0 == init(&queue1, 5))
	{
		printf("INF: Queue creation success\r\n");
	}

	enqueue(&queue1, 1);
	enqueue(&queue1, 2);
	enqueue(&queue1, 3);
	enqueue(&queue1, 4);
	enqueue(&queue1, 5);
	enqueue(&queue1, 6);
	enqueue(&queue1, 7);
	
	show(&queue1);
	
	dequeue(&queue1, &data);
	dequeue(&queue1, &data);
	
	show(&queue1);
	
	enqueue(&queue1, 6);
	enqueue(&queue1, 7);
	
	show(&queue1);
	
	return 0;
}
