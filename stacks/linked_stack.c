#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

LinkedNode* head, * tail, * linked_stack_head, * linked_stack_tail;

void init_linked_stack(void) {
	head = (LinkedNode*)malloc(sizeof(LinkedNode));
	tail = (LinkedNode*)malloc(sizeof(LinkedNode));
	if (!head || !tail) {
		if(head) free(head);
		if(tail) free(tail);
		exit(1);
	}

	linked_stack_head = head;
	linked_stack_tail = tail;

	head->next = tail;
	tail->next = tail;
}

int push_linked_stack(int k) {
	LinkedNode* node = (LinkedNode*)malloc(sizeof(LinkedNode));
	if (!node) {
		printf("\n Out of memory.");
		return -1;
	}
	node->key = k;
	node->next = head->next;
	head->next = node;
	return k;
}

int pop_linked_stack(void) {
	if (head->next == tail) {
		printf("\n Stack Underflow");
		return -1;
	}
	LinkedNode* n = head->next;
	head->next = n->next;
	int k = n->key;
	free(n);
	return k;
}

void clear_linked_stack(void) {
	LinkedNode* n;
	while (head->next != tail) {
		n = head->next;
		head->next = n->next;
		free(n);
	}
}

void print_linked_stack(void) {
	LinkedNode* n = head;
	printf("\n Top -> Bottom.");
	while ((n = n->next) != tail) {
		printf("%-6d", n->key);
	}
}