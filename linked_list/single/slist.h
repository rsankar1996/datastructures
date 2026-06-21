#ifndef SLIST_H
#define SLIST_H

typedef struct list
{
	int data;
	struct list * next;
} list_t;

int init(list_t ** head, int data);
void show (list_t * node);
int append(list_t ** head, int data);
int remove_tail(list_t ** head);
int add_pos(list_t ** head, int pos, int data);
int remove_pos(list_t ** head, int pos);
list_t * reverse (list_t * head);

#endif /* SLIST_H */
