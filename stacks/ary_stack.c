#include <stdio.h>

#define MAX 10
int aryStack[MAX];
int top; // 빈 스택은 -1

void init_ary_stack(void) {
	top = -1;
}

int push_in_ary_stack(int t) {
	if (top >= MAX - 1) {
		printf("\n Stack overflow.");
		return -1;
	}

	aryStack[++top] = t;
	return t;
}

int pop_in_ary_stack(void) {
	if (top <= -1) {
		printf("\n Stack underflow.");
		return -1;
	}

	return aryStack[top--];
}

void print_ary_stack(void) {
	printf("\n Top->Bottom\n");
	for (int i = top; i >= 0; i--)
		printf("%-6d", aryStack[i]);
}