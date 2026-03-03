#pragma once
typedef struct _simple_linked_node {
	int key;
	struct _simple_linked_node* next;
} SimPleLinkedNode;

extern SimPleLinkedNode* simple_linked_head, *simple_linked_tail;


void init_list(void);
SimPleLinkedNode* insert_after(int k, SimPleLinkedNode* t);
int delete_next(SimPleLinkedNode* t);
SimPleLinkedNode* find_node(int k);
int delete_node(int k);
SimPleLinkedNode* insert_node_before_k(int t, int k);
SimPleLinkedNode* ordered_insert(int k);
void print_list(SimPleLinkedNode* t);
void delete_all(void);