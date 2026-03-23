#include "calcutil.h"
#include <stdio.h>
#include <stdlib.h>

Node* head, * tail, * calc_head, * calc_tail;
int stack_state;

void init_calc_stack(void) {
	stack_state = 1;
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	if (!head || !tail) {
		if (head) free(head);
		if (tail) free(tail);
		exit(1);
	}

	head->next = tail;
	tail->next = tail;
	calc_head = head;
	calc_tail = tail;
}

void remove_stack(void) {
	if (!stack_state)
		return;
	
	Node* s = head;
	Node* t = s->next;
	while (t != tail) {
		s = t->next;
		free(t);
		t = s->next;
	}
	free(head);
	free(tail);
	stack_state = 0;
}

int pop_calc_stack(void) {
	if (head->next == tail) {
		return -1;
	}
	Node* t = head->next;
	head->next = t->next;
	char v = t->code;
	free(t);
	return v;
}

int push_calc_stack(int v) {
	Node* t = (Node*)malloc(sizeof(Node));
	if (!t) {
		return -1;
	}
	t->next = head->next;
	head->next = t;
	t->code = v;
	return v;
}

void postfix1(char* dst, char* src) {
	remove_stack();
	init_calc_stack();
	while (*src) {
		if (*src == ')') {
			*dst++ = pop_calc_stack();
			*dst++ = ' ';
			src++;
		}
		else if (*src == '+' || *src == '*' || *src == '-' || *src == '/')
			push_calc_stack(*src++);
		else if (*src >= '0' && *src <= '9') {
			do {
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';
		}
		else src++;
	}
	dst--;
	*dst = 0;
}

int get_stack_top(void) {
	return head->next == tail ? -1 : head->next->code;
}

int is_operator(int k) {
	return (k == '+' || k == '*' || k == '-' || k == '/');
}

int precdence(int op) {
	if (op == '(') return 0;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	
	return 3;
}

int is_stack_empty() {
	return head->next == tail ? 1 : 0;
}

void postfix2(char* dst, char* src) {
	remove_stack();
	init_calc_stack();
	while (*src) {
		if (*src == '(') {
			push_calc_stack(*src);
			src++;
		}
		else if (*src == ')') {
			while (get_stack_top() != '(') {
				*dst++ = pop_calc_stack();
				*dst++ = ' ';
			}
			pop_calc_stack();
			src++;
		}
		else if (is_operator(*src)) {
			while (!is_stack_empty() && precdence(get_stack_top()) >= precdence(*src)) {
				*dst++ = pop_calc_stack();
				*dst++ = ' ';
			}
			push_calc_stack(*src);
			src++;
		}
		else if (*src >= '0' && *src <= '9') {
			do {
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';
		}
		else
			src++;
	}

	while (!is_stack_empty()) {
		*dst++ = pop_calc_stack();
		*dst++ = ' ';
	}
	dst--;
	*dst = '\0';
}

int calc(char* p) {
	int i;
	remove_stack();
	init_calc_stack();
	while (*p) {
		if (*p >= '0' && *p <= '9') {
			i = 0;
			do {
				i = i * 10 + *p - '0';
				p++;
			} while (*p >= '0' && *p <= '9');

			push_calc_stack(i);
		}
		else if (*p == '+') {
			push_calc_stack(pop_calc_stack() + pop_calc_stack());
			p++;
		}
		else if (*p == '*') {
			push_calc_stack(pop_calc_stack() * pop_calc_stack());
			p++;
		}
		else if (*p == '-') {
			int  i = pop_calc_stack();
			push_calc_stack(pop_calc_stack() - i);
			p++;
		}
		else if (*p == '/') {
			int  i = pop_calc_stack();
			push_calc_stack(pop_calc_stack() / i);
			p++;
		}
		else p++;
	}
	return pop_calc_stack();
}

int is_legal(char* s) {
	int f = 0;
	while (*s) {
		while (*s == ' ')
			s++;
		if (is_operator(*s)) f--;
		else {
			f++;
			while (*s != ' ')
				s++;
		}
		if (f < 1) break;
		s++;
	}
	return (f == 1);
}