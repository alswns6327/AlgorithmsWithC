#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

CircularLinkedNode* circular_linked_head;

void insert_nodes(int k) {
	CircularLinkedNode* node = (CircularLinkedNode*)malloc(sizeof(CircularLinkedNode));
	if (!node) exit(1);
	node->key = 1;
	circular_linked_head = node;
	for (int i = 2; i <= k; i++) {
		node->next = (CircularLinkedNode*)malloc(sizeof(CircularLinkedNode));
		if (!node->next) exit(1);
		node->next->key = i;
		node = node->next;
	}
	node->next = circular_linked_head;
}

void delete_after(CircularLinkedNode* node) {
	CircularLinkedNode* s = node->next;
	node->next = s->next;
	free(s);
}

void josephus(int n, int m) {
	insert_nodes(n);
	CircularLinkedNode* node = circular_linked_head;
	while (node != node->next) {
		for (int i = 0; i < m - 1; i++)
			node = node->next;
		printf("%4d", node->next->key);
		delete_after(node);
	}
	printf("%4d", node->key);
	free(node);
}