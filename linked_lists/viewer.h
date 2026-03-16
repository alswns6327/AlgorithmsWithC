#pragma once

typedef struct _line {
	char* buf;
	struct _line* prev;
	struct _line* next;
} Line;

extern Line* viewer_head, * viewer_tail;
extern char filename[13];

void key_proc(void);
void load_file(void);
void init_line(void);