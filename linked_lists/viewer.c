#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewer.h"
#include "rlutil.h"

Line* head, * tail, *viewer_head, *viewer_tail;
int total, now;
char filename[13];

void init_line(void) {
	head = (Line*)malloc(sizeof(Line));
	tail = (Line*)malloc(sizeof(Line));
	if (!head || !tail) exit(1);
	viewer_head = head;
	viewer_tail = tail;
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void load_file(void) {
	FILE* fp;
	char buf[256];
	Line* t;
	fp = fopen(filename, "rt");
	if (!fp) exit(1);

	while (fgets(buf, sizeof(buf), fp) != NULL) {
		if (strlen(buf) > 80)
			buf[80] = 0;
		if ((t = (Line*)malloc(sizeof(Line))) == NULL) {
			fclose(fp);
			exit(1);
		}

		if ((t->buf = (char*)malloc(strlen(buf))) == NULL) {
			fclose(fp);
			free(t);
			exit(1);
		}

		strcpy(t->buf, buf);
		t->prev = tail->prev;
		t->next = tail;
		tail->prev->next = t;
		tail->prev = t;
		total++;
	}
	fclose(fp);
}

void show_header(void) {
	saveDefaultColor();
	setBackgroundColor(GREY);
	setColor(BLACK);
	locate(1, 1);
	printf("TVIEW: %-12s, Loc : %6d of %6d    By Kim minjun", filename, now, total);
	resetColor();
}

void show_page(Line* t) {
	int i = 0;
	cls();
	show_header();
	locate(1, 2);
	while (i++ < 23 && t != tail) {
		printf("%80s", t->buf);
		t = t->next;
	}
}

void move_line(int d, Line** t) {
	if (d < 0) 
		while (d++ && (*t)->prev != head) {
			(*t) = (*t)->prev;
			now--;
		}
	else
		while (d-- && (*t)->next != tail) {
			(*t) = (*t)->next;
			now++;
		}
}

void key_proc(void) {
	Line* t;
	int key, page = 0;
	now = 1;
	t = head->next;
	show_page(t);
	while ((key = getkey()) != KEY_ESCAPE) {
		switch (key) {
			case KEY_PGUP:	
				page = -23;
				break;
			case KEY_PGDOWN:
				page = 23;
				break;
		}
		move_line(page, &t);
		show_page(t);
	}
	cls();
}