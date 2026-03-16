#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "namecard.h"

Card *head, *tail, *card_list_head, *card_list_tail;

void clear_input_buffer(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

void input_number(int* num, int min, int max) {
	while (1) {
		if (!scanf("%d", num)) {
			printf("\n숫자만 입력해주세요.\n");
			clear_input_buffer();
		}
		else if (*num < min || *num > max)
			printf("\n%d~%d 사이로 입력해주세요.\n", min, max);
		else
			break;
	}
	clear_input_buffer();
}

void input_str(char* str, int size, int min) {
	size_t len;
	while (1) {
		fgets(str, size, stdin);
		len = strlen(str);
		if (str[len - 1] != '\n') {
			min > 0 ?
				printf("\n영어는 %d~%d자 한글은 %d~%d자 이내로 입력해주세요.", min, size, min, size / 2):
				printf("\n영어는 %d자 한글은 %d자 이내로 입력해주세요.", size, size / 2);
			clear_input_buffer();
		}
		else if(len < min) {
			printf("\n영어는 %d~%d자 한글은 %d~%d자 이내로 입력해주세요.", min, size, min, size / 2);
		}
		else {
			str[len - 1] = '\0';
			break;
		}
	}
}

void init_card(void) {
	head = (Card*)malloc(sizeof(Card));
	tail = (Card*)malloc(sizeof(Card));
	if (!head || !tail) exit(1);
	card_list_head = head;
	card_list_tail = tail;
	head->next = tail;
	tail->next = tail;
}

void input_card(void) {
	Card* t = (Card*)malloc(sizeof(Card));
	if (!t) {
		printf("\n등록 실패\n");
		return;
	}

	printf("\nInput name : ");
	input_str(t->name, sizeof(t->name), 2);
	printf("\nInput corporation : ");
	input_str(t->corp, sizeof(t->corp), 2);
	printf("\nInput telephone number : ");
	input_str(t->tel, sizeof(t->tel), 2);

	t->next = head->next;
	head->next = t;
}

int delete_card(char* s) {
	Card* t = head;
	while (t->next != tail) {
		if (!strcmp(t->next->name, s)) break;
		t = t->next;
	}
	if (t->next == tail) return 0;

	Card* del = t->next;
	t->next = del->next;
	free(del);
	return 1;
}

Card* search_card(char* s) {
	Card* t = head;
	while ((t = t->next) != tail) if (!strcmp(t->name, s)) break;

	return t == tail ? NULL : t;
}

void save_cards(char* s) {
	FILE* fp = fopen(s, "wb");
	if (!fp) {
		printf("\nopen fail");
		return;
	}
	Card* t = head;
	while((t = t->next) != tail) fwrite(t, REC_SIZE, 1, fp);
	fclose(fp);
}

void load_cards(char* s) {
	FILE* fp = fopen(s, "rb");
	if (!fp) {
		printf("\nopen fail");
		return;
	}
	Card* t = head;
	while (t->next != tail) {
		Card* del = t->next;
		t->next = del->next;
		free(del);
	}

	while (1) {
		t = (Card*)malloc(sizeof(Card));
		if (!t) {
			printf("\n오류 발생");
			return;
		}
		if (!fread(t, REC_SIZE, 1, fp)) {
			free(t);
			break;
		}
		t->next = head->next;
		head->next = t;
	}
	fclose(fp);
}

void print_header(FILE* fp) {
	fprintf(fp, "\nName                 " "Corporation           " "Telephone number    ");
	fprintf(fp, "\n---------------------" "----------------------" "--------------------");
}

void print_card(Card* t, FILE* fp) {
	fprintf(fp, "\n%-20s  %-20s  %-20s", t->name, t->corp, t->tel);
}