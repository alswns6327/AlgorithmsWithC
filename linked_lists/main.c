#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple_linked_list.h"
#include "circular_linked_list.h"
#include "doubly_linked_list.h"
#include "namecard.h"
#include "viewer.h"

void testSimpleLinkedList(void);
void testCircularLinkedList(void);
void testDoublyLinkedList(void);
void testNamecardSystem(void);
void testViewerSystem(int argc, char** argv);

int main(int argc, char* argv[]) {
	testViewerSystem(argc, argv);
	//testNamecardSystem();
	//testDoublyLinkedList();
	//testCircularLinkedList();
	//testSimpleLinkedList();
	return 0;
}

void testViewerSystem(int argc, char** argv) {
	if (argc != 2) {
		printf("\nUsage: TVIEW <filename.txt>");
		exit(0);
	}
	strcpy(filename, argv[1]);
	init_line();
	load_file();
	key_proc();
}

void testNamecardSystem(void) {
	char* fname = "NAMECARD.DAT";
	char name[NAME_SIZE];
	int menu;
	Card* t;
	init_card();

	while (1) {
		printf("\n\nNamecard Manager System");
		printf("\n--------------------------");
		printf("\n1. Input");
		printf("\n2. Delete");
		printf("\n3. Search");
		printf("\n4. Load");
		printf("\n5. Save");
		printf("\n6. List");
		printf("\n7. Print");
		printf("\n8. End\n");
		input_number(&menu, 1, 8);
		if (menu == 8) break;

		switch (menu) {
			case 1:
				input_card();
				break;
			case 2:
				input_str(name, sizeof(name), 2);
				if (!delete_card(name))
					printf("\n   Can't find that name.");
				break;
			case 3:
				input_str(name, sizeof(name), 2);
				t = search_card(name);
				if (t == NULL) {
					printf("\n Can't find that name.");
					break;
				}
				print_header(stdout);
				print_card(t, stdout);
				break;
			case 4:
				load_cards(fname);
				break;
			case 5:
				save_cards(fname);
				break;
			case 6:
				t = card_list_head;
				print_header(stdout);
				while ((t = t->next) != card_list_tail)
					print_card(t, stdout);
				break;
			case 7:
				t = card_list_head;
				print_header(stdout);
				while ((t = t->next) != card_list_tail)
					print_card(t, stdout);
				break;
		}
	}
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

