#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

DoublyLinkedNode* doubly_linked_head, *doubly_linked_tail;

void init_dlist(void) {
	doubly_linked_head = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
	doubly_linked_tail = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
	if (!doubly_linked_head || !doubly_linked_head) exit(1);

	doubly_linked_head->prev = doubly_linked_head;
	doubly_linked_head->next = doubly_linked_tail;
	doubly_linked_tail->prev = doubly_linked_head;
	doubly_linked_tail->next = doubly_linked_tail;
}

DoublyLinkedNode* insert_dnode_ptr(int k, DoublyLinkedNode* node) {
	DoublyLinkedNode* t = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
	if (!t) return NULL;

	t->key = k;
	node->prev->next = t;
	t->prev = node->prev;
	t->next = node;
	node->prev = t;
	return t;
}

int delete_dnode_ptr(DoublyLinkedNode* node) {
	if (node == doubly_linked_head || node == doubly_linked_tail)
		return 0;

	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);

	return 1;
}

DoublyLinkedNode* find_dnode(int k) {
	DoublyLinkedNode* s = doubly_linked_head;
	while ((s = s->next) != doubly_linked_tail)
		if (s->key == k) break;

	return s;
}

int delete_dnode(int k) {
	DoublyLinkedNode* s = find_dnode(k);
	if (s == doubly_linked_tail) return 0;
	s->prev->next = s->next;
	s->next->prev = s->prev;
	free(s);

	return 1;
}

DoublyLinkedNode* insert_dnode(int k, int t) {
	DoublyLinkedNode* s = find_dnode(t);
	if (s == doubly_linked_tail) return NULL;

	DoublyLinkedNode* i = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
	if (!i) return NULL;

	i->key = k;
	s->prev->next = i;
	i->prev = s->prev;
	i->next = s;
	s->prev = i;

	return i;
}

DoublyLinkedNode* ordered_insert_dnode(int k) {
	DoublyLinkedNode* s;
	s = doubly_linked_head;
	while ((s = s->next) != doubly_linked_tail && s->key <= k);

	return insert_dnode_ptr(k, s);
}

void print_dlist(DoublyLinkedNode* node) {
	printf("\n");
	while (node != doubly_linked_tail) {
		printf("%-4d", node->key);
		node = node->next;
	}
}

void delete_dlist() {
	while (delete_dnode_ptr(doubly_linked_head->next));
}