#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int init (queue_t * queue, int size)
{
	queue->mem = (int *)malloc(size * (sizeof(int)));
	if (NULL == queue->mem)
	{
		printf("ERR: Memory allocation failed\r\n");
		return -1;
	}
	
	queue->size = 0;
	queue->front = 0;
	queue->rear = 0;
	queue->capacity = size;
	
	return 0;
}

int is_full(queue_t * queue)
{
	if (queue->size == (queue->capacity))
	{
		return 0;
	}
	
	return -1;
}

int is_empty(queue_t * queue)
{
	if (0 == queue->size)
	{
		return 0;
	}
	
	return -1;
}

void show (queue_t * queue)
{
	int i = 0;
	
	for (i = 0; i < queue->size; i++)
	{
		printf("%d ", queue->mem[(queue->front + i) % queue->capacity]);
	}
	printf("\r\n");
}

int enqueue (queue_t * queue, int data)
{
	if (0 == is_full(queue))
	{
		printf("ERR: Queue is full, enqueue failed\r\n");
		return -1;
	}
	
	queue->rear = (queue->front + queue->size) % queue->capacity;
	queue->mem[queue->rear] = data;
	queue->size++;
	
	printf("ERR: Enqueue success with %d\r\n", data);

	return 0;
}

int dequeue (queue_t * queue, int * data)
{
	if (0 == is_empty(queue))
	{
		printf("ERR: Queue is empty, dequeue failed\r\n");
		return -1;
	}
	
	*data = queue->mem[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	
	printf("ERR: Dequeue success with %d\r\n", *data);

	return 0;
}
