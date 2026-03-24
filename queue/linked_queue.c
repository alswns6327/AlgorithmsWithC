#include "linked_queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _linked_queue_node {
	int key;
	struct _linked_queue_node* next;
	struct _linked_queue_node* prev;
} LinkedQueueNode;

LinkedQueueNode* head, * tail, * linkedQueueHead, * linkedQueueTail;
int queueState = 0;

void init_queue(void) {
	if (queueState) remove_linked_queue();

	head = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
	tail = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
	if (!head || !tail) 
		exit(1);
	
	linkedQueueHead = head;
	linkedQueueTail = tail;

	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	queueState = 1;
}


int put_linked_queue(int k) {
	if (!queueState) return;

	LinkedQueueNode* n = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
	if (!n) {
		printf("\n Out of Memory");
		return -1;
	}

	n->key = k;
	n->next = tail;
	n->prev = tail->prev;
	tail->prev->next = n;
	tail->prev = n;

	return k;
}

int get_linked_queue(int k) {
	if (!queueState) return;

	if (head->next == tail) {
		printf("\n Underflow.");
		return -1;
	}
	LinkedQueueNode* n = head->next;
	head->next = head->next->next;
	head->next->prev = head;
	int k = n->key;
	free(n);
	return k;
}

void clear_linked_queue(void) {
	if (!queueState) return;

	LinkedQueueNode* n;
	while (head->next != tail) {
		n = head->next;
		head->next = head->next->next;
		free(n);
	}
	tail->prev = head;
}

void remove_linked_queue(void) {
	if (!queueState) return;

	clear_linked_queue();
	free(head);
	free(tail);

	queueState = 0;
}