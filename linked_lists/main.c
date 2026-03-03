#include <stdio.h>
#include "simple_linked_list.h"
#include "circular_linked_list.h"
#include "doubly_linked_list.h"

void testSimpleLinkedList(void);
void testCircularLinkedList(void);
void testDoublyLinkedList(void);

int main(void) {
	testDoublyLinkedList();
	//testCircularLinkedList();
	//testSimpleLinkedList();
	return 0;
}

void testDoublyLinkedList (void) {
	DoublyLinkedNode* t;
	init_dlist();
	ordered_insert_dnode(10);
	ordered_insert_dnode(5);
	ordered_insert_dnode(8);
	ordered_insert_dnode(3);
	ordered_insert_dnode(1);
	ordered_insert_dnode(7);
	ordered_insert_dnode(8);

	printf("\nInitial");
	print_dlist(doubly_linked_head->next);
	t = find_dnode(4);
	printf("\n4 : %s", t == doubly_linked_tail ? "fail" : "success");
	t = find_dnode(5);
	printf("\n5 : %s", t == doubly_linked_tail ? "fail" : "success");

	insert_dnode_ptr(7, t);
	print_dlist(doubly_linked_head->next);

	t = find_dnode(3);
	delete_dnode_ptr(t);
	print_dlist(doubly_linked_head->next);

	
	insert_dnode(2, 10);
	print_dlist(doubly_linked_head->next);

	if (delete_dnode(2))
		printf("\n deleting 2 success");
	print_dlist(doubly_linked_head->next);

	delete_dnode(1);
	print_dlist(doubly_linked_head->next);

	insert_dnode_ptr(15, doubly_linked_head->next);
	print_dlist(doubly_linked_head->next);

	delete_dlist();
	print_dlist(doubly_linked_head->next);
}

void testCircularLinkedList(void) {
	int n, m;
	while (1) {
		printf("Input n, m : ");
		scanf("%d%d", &n, &m);
		if (n > 0 || m > 0) break;
	}

	josephus(n, m);
}

void testSimpleLinkedList(void) {
	SimPleLinkedNode* t;
	init_list();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	printf("\nInitial Linked list : ");
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
}

