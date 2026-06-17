#include <stdio.h>
#include "dlist.h"

int main()
{
	dlist_t * head = NULL;
	dlist_t * rev = NULL;

	(void)init (&head, 10);

	//fw_inspect(head);
	//rv_inspect(head);
	
	(void)append(&head, 20);
	//fw_inspect(head);
	(void)append(&head, 30);
	//fw_inspect(head);
	(void)append(&head, 40);
	//fw_inspect(head);
	(void)append(&head, 50);

	//fw_inspect(head);
	//rv_inspect(head);
	
	(void)insert_at(&head, 2, 25);
	
	fw_inspect(head);
	//rv_inspect(head);

	rev = reverse(&head);
	
	fw_inspect(rev);

	return 0;
}
