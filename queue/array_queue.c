#include "array_queue.h"

#define MAX 10
int array_queue[MAX], front, rear;

void init_array_queue(void) {
	front = rear = 0;
}

void clear_array_queue(void) {
	front = rear;
}

int put_array_queue(int k) {
	if ((rear + 1) % MAX == front) {
		printf("\n Overflow.");
		return -1;
	}
	array_queue[rear] = k;
	rear = ++rear % MAX;
	return k;
}

int get_array_queue(void) {
	if (front == rear) {
		printf("\n Underflow.");
		return -1;
	}

	int k = array_queue[front];
	front = ++front % MAX;
	return k;
}

void print_array_queue(void) {
	printf("\n Queue contents : Front -> Rear\n");
	for (int i = front; i != rear; i = ++i % MAX)
		printf("%-6d", array_queue[i]);
	
}