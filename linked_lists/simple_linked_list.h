#pragma once
typedef struct _node {
	int key;
	struct _node* next;
} Node;

extern Node* simple_linked_head, *simple_linked_tail;


void init_list(void);
Node* insert_after(int k, Node* t);
int delete_next(Node* t);
Node* find_node(int k);
int delete_node(int k);
Node* insert_node_before_k(int t, int k);
Node* ordered_insert(int k);
void print_list(Node* t);
void delete_all(void);