#include <stdio.h>
#include <stdlib.h>
#include "simple_linked_list.h"

static SimPleLinkedNode* head, * tail;

SimPleLinkedNode* simple_linked_head,* simple_linked_tail;

void init_list(void) {
	head = (SimPleLinkedNode*)malloc(sizeof(SimPleLinkedNode));
	tail = (SimPleLinkedNode*)malloc(sizeof(SimPleLinkedNode));
	head->next = tail;
	tail->next = tail;
	simple_linked_head = head;
	simple_linked_tail = tail;
}

SimPleLinkedNode* insert_after(int k, SimPleLinkedNode* t) {
	SimPleLinkedNode* new_node = (SimPleLinkedNode*)malloc(sizeof(SimPleLinkedNode));
	if (!new_node) return NULL;
	new_node->key = k;
	new_node->next = t->next;
	t->next = new_node;
	return new_node;
}

int delete_next(SimPleLinkedNode* t) {
	SimPleLinkedNode* del = t->next;
	if (del == tail) return 0;

	t->next = del->next;
	free(del);
	return 1;
}

SimPleLinkedNode* find_node(int k) {
	SimPleLinkedNode* s = head;
	while ((s = s->next) != tail) 
		if (s->key == k) break;
	
	return s;
}

int delete_node(int k) {
	SimPleLinkedNode* s = head;
	while(s->next != tail && s->next->key != k)
		s = s->next;
	
	
	if (s->next == tail) return 0;

	SimPleLinkedNode* del = s->next;
	s->next = del->next;
	free(del);
	return 1;
}

SimPleLinkedNode* insert_node_before_k(int t, int k) {
	SimPleLinkedNode* s = head;
	while (s->next != tail && s->next->key != k) 
		s = s->next;
	
	

	if (s->next == tail) return s->next;

	SimPleLinkedNode* new_node = (SimPleLinkedNode*)malloc(sizeof(SimPleLinkedNode));
	if (!new_node) return NULL;

	new_node->key = t;
	new_node->next = s->next;
	s->next = new_node;

	return new_node;
}

SimPleLinkedNode* ordered_insert(int k) {
	SimPleLinkedNode* s = head;

	while (s->next != tail && s->next->key <= k)
		s = s->next;

	SimPleLinkedNode* new_node = (SimPleLinkedNode*)malloc(sizeof(SimPleLinkedNode));
	if (!new_node) return NULL;

	new_node->key = k;
	new_node->next = s->next;
	s->next = new_node;

	return new_node;
}

void print_list(SimPleLinkedNode* t) {
	printf("\n");
	while (t != tail) {
		printf("%-8d", t->key);
		t = t->next;
	}
}

void delete_all(void) {
	SimPleLinkedNode *del;
	while (head->next != tail) {
		del = head->next;
		head->next = del->next;
		free(del);
	}
}