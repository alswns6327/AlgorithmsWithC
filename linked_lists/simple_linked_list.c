#include <stdio.h>
#include <stdlib.h>
#include "simple_linked_list.h"

Node* head, * tail;

Node* simple_linked_head,* simple_linked_tail;

void init_list(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	tail->next = tail;
	simple_linked_head = head;
	simple_linked_tail = tail;
}

Node* insert_after(int k, Node* t) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) return NULL;
	new_node->key = k;
	new_node->next = t->next;
	t->next = new_node;
	return new_node;
}

int delete_next(Node* t) {
	Node* del = t->next;
	if (del == tail) return 0;

	t->next = del->next;
	free(del);
	return 1;
}

Node* find_node(int k) {
	Node* s = head;
	while ((s = s->next) != tail) 
		if (s->key == k) break;
	
	return s;
}

int delete_node(int k) {
	Node* s = head;
	while(s->next != tail && s->next->key != k)
		s = s->next;
	
	
	if (s->next == tail) return 0;

	Node* del = s->next;
	s->next = del->next;
	free(del);
	return 1;
}

Node* insert_node_before_k(int t, int k) {
	Node* s = head;
	while (s->next != tail && s->next->key != k) 
		s = s->next;
	
	

	if (s->next == tail) return s->next;

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) return NULL;

	new_node->key = t;
	new_node->next = s->next;
	s->next = new_node;

	return new_node;
}

Node* ordered_insert(int k) {
	Node* s = head;

	while (s->next != tail && s->next->key <= k)
		s = s->next;

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) return NULL;

	new_node->key = k;
	new_node->next = s->next;
	s->next = new_node;

	return new_node;
}

void print_list(Node* t) {
	printf("\n");
	while (t != tail) {
		printf("%-8d", t->key);
		t = t->next;
	}
}

void delete_all(void) {
	Node *del;
	while (head->next != tail) {
		del = head->next;
		head->next = del->next;
		free(del);
	}
}