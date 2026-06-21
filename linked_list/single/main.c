#include <stdio.h>
#include "slist.h"

int main()
{
	list_t * head = NULL;
	list_t * rev = NULL;
	
	if (0 == init(&head, 10))
	{
		printf("Linked list created\r\n");
	}
	
	show (head);
	
	append(&head, 20);
	append(&head, 30);
	append(&head, 40);
	append(&head, 50);
	
	show(head);
	
	remove_tail(&head);
	
	show(head);
	
	printf("TST: Adding data 35 at position 2\r\n");
	add_pos(&head, 2, 35);
	
	show(head);
	
	printf("TST: Removing node at position 3\r\n");
	remove_pos(&head, 3);
	show(head);
	
	rev = reverse (head);
	show(rev);

	return 0;
}
