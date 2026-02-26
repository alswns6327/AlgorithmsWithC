#include "simple_linked_list.h"
#include <stdio.h>

int main(void) {

	Node* t;
	init_list();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	printf("\n Initial Linked list : ");
	print_list(simple_linked_head->next);
	printf("\nFinding 4 is %ssuccessful", find_node(4) == simple_linked_tail ? "un" : "");

	t = find_node(5);
	printf("\nFinding 5 is %ssuccessful", t == simple_linked_tail ? "un" : "");

	printf("\nInserting 9 after 5");
	insert_after(9, t);
	print_list(simple_linked_head->next);

	t = find_node(10);
	printf("\nDeleting next last node");
	delete_next(t);
	print_list(simple_linked_head->next);

	t = find_node(3);
	printf("\nDeleting next 3");
	delete_next(t);
	print_list(simple_linked_head->next);

	printf("\nInsert node 2 before 3");
	insert_node_before_k(2, 3);
	print_list(simple_linked_head->next);

	printf("\nDeleting node 2");
	if (!delete_node(2))
		printf("\n deleting 2 is unsuccessful");
	print_list(simple_linked_head->next);

	printf("\nDeleting node 1");
	delete_node(1);
	print_list(simple_linked_head->next);

	printf("\nDeleting all node");
	delete_all();
	print_list(simple_linked_head->next);


	return 0;
}