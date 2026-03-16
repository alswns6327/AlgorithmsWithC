#pragma once

typedef struct _node {
	int key;
	struct _node* next;
} Node;

extern Node* head, * tail;

void init_linked_stack(void);
int push_linked_stack(int k);
int pop_linked_stack(void);
void clear_linked_stack(void);
void print_linked_stack(void);