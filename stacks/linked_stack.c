#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

Node* head, * tail;

void init_linked_stack(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	if (!head || !tail) exit(1);

	head->next = tail;
	tail->next = tail;
}

int push_linked_stack(int k) {
	Node* node = (Node*)malloc(sizeof(Node));
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
	Node* n = head->next;
	head->next = n->next;
	int k = n->key;
	free(n);
	return k;
}

void clear_linked_stack(void) {
	Node* n;
	while (head->next != tail) {
		n = head->next;
		head->next = n->next;
		free(n);
	}
}

void print_linked_stack(void) {
	Node* n = head;
	printf("\n Top -> Bottom.");
	while ((n = n->next) != tail) {
		printf("%-6d", n->key);
	}
}