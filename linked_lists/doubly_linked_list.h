#pragma once

typedef struct _doubly_linked_node {
	int key;
	struct _doubly_linked_node* prev;
	struct _doubly_linked_node* next;
} DoublyLinkedNode;

extern DoublyLinkedNode* doubly_linked_head, *doubly_linked_tail;

void init_dlist(void);
DoublyLinkedNode* insert_dnode_ptr(int k, DoublyLinkedNode* node);
int delete_dnode_ptr(DoublyLinkedNode* node);
DoublyLinkedNode* find_dnode(int k);
int delete_dnode(int k);
DoublyLinkedNode* insert_dnode(int k, int t);
DoublyLinkedNode* ordered_insert_dnode(int k);
void print_dlist(DoublyLinkedNode* node);
void delete_dlist();