#pragma once

typedef struct _node {
	int code;
	struct _node* next;
} Node;

extern Node* calc_head, * calc_tail;

void init_calc_stack(void);
void remove_stack(void);
int pop_calc_stack(void);
int push_calc_stack(int v);
void postfix1(char* dst, char* src);
int get_stack_top(void);
int is_operator(int k);
int precdence(int op);
int is_stack_empty();
void postfix2(char* dst, char* src);
int calc(char* p);
int is_legal(char* s);