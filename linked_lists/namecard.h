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