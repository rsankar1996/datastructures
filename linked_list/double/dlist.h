#ifndef DLIST_H
#define DLIST_H

typedef struct dlist
{
	int data;
	struct dlist * next;
	struct dlist * prev;
} dlist_t;


void fw_inspect (dlist_t * head);
void rv_inspect (dlist_t * head);
int init(dlist_t ** head, int data);
int append(dlist_t ** head, int data);
int insert_at (dlist_t ** head, int index, int data);

#endif /* DLIST_H */
