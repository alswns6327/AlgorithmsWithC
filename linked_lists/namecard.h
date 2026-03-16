#pragma once

#define NAME_SIZE 21
#define CORP_SIZE 31
#define TEL_SIZE 16
#define REC_SIZE (NAME_SIZE + CORP_SIZE + TEL_SIZE)

typedef struct _card {
	char name[NAME_SIZE];
	char corp[CORP_SIZE];
	char tel[TEL_SIZE];
	struct _card* next;
} Card;

extern Card* card_list_head, * card_list_tail;

void clear_input_buffer(void);
void input_number(int* num, int min, int max);
void input_str(char* str, int size, int min);
void init_card(void);
void input_card(void);
int delete_card(char* s);
Card* search_card(char* s);
void save_cards(char* s);
void load_cards(char* s);
void print_header(FILE* fp);
void print_card(Card* t, FILE* fp);