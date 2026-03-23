#pragma once

typedef struct _linked_node {
	int key;
	struct _linked_node* next;
} LinkedNode;

extern LinkedNode* linked_stack_head, * linked_stack_tail;

void init_linked_stack(void);
int push_linked_stack(int k);
int pop_linked_stack(void);
void clear_linked_stack(void);
void print_linked_stack(void);