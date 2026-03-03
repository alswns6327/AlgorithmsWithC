#pragma once

typedef struct _circular_linked_node {
	int key;
	struct _circular_linked_node* next;
} CircularLinkedNode;

extern CircularLinkedNode* circular_linked_head;

void insert_nodes(int k);
void delete_after(CircularLinkedNode* node);
void josephus(int n, int m);