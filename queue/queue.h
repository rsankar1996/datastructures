#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct
{
	int * mem;
	int front;
	int rear;
	int size;
	int capacity;
} queue_t ;

int init (queue_t * queue, int size);
int is_full(queue_t * queue);
int is_empty(queue_t * queue);
void show (queue_t * queue);
int enqueue (queue_t * queue, int data);
int dequeue (queue_t * queue, int * data);


#endif /* _QUEUE_H */
