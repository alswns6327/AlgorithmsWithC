#include <stdio.h>
#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
	#define Sleep(ms) usleep((ms) * 1000)
#endif

#define MAZE_SIZE 19
#define UP 1
#define RIGHT 2
#define DOWN 4
#define LEFT 8

char* get_shape(int x, int y);
void draw_maze(void);
void gotoxy(int x, int y);
void forward(int* x, int* y, int dir);
int still_in_maze(int x, int y);
int wall_ahead(int x, int y, int dir);
void turn_right(int* dir);
void turn_left(int* dir);
void right_hand(int x, int y, int dir);
void record(int x, int y);
int del_path(int i, int j);
void shortest_route(void);

int maze[MAZE_SIZE][MAZE_SIZE] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1},
	{1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1},
	{1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1},
	{1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1},
	{1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int sx = MAZE_SIZE - 1, sy = MAZE_SIZE - 2;
int* rec;

int main() {
	rec = (int*)malloc(sizeof(int) * MAZE_SIZE * MAZE_SIZE);
	draw_maze();
	right_hand(sx, sy, LEFT);
	gotoxy(1, 2);
	fputs(" ", stdout);
	shortest_route();
	gotoxy(20, 20);
	return 0;
}

char* get_shape(int x, int y) {	
	return maze[y][x] ? "&" : " ";
}
void draw_maze() {
	for (int j = 0; j < MAZE_SIZE; j++) {
		for (int i = 0; i < MAZE_SIZE; i++) {
			gotoxy(i + 1, j + 1);
			fputs(get_shape(i, j), stdout);
		}
	}
}

void gotoxy(int x, int y) {
	printf("\033[%d;%df", y, x);
}

void forward(int* x, int* y, int dir) {
	gotoxy(*x + 1, *y + 1);
	fputs(" ", stdout);
	*x += dir == LEFT ? -1 : dir == RIGHT ? 1 : 0;
	*y += dir == UP ? -1 : dir == DOWN ? 1 : 0;

	record(*x, *y);
	gotoxy(*x + 1, *y + 1);
	puts("*");
}

int still_in_maze(int x, int y) {
	if (x > 0 && x < MAZE_SIZE - 1 && y > 0 && y < MAZE_SIZE - 1) return 1;
	else return 0;
}

int wall_ahead(int x, int y, int dir) {
	x += dir == LEFT ? -1 : dir == RIGHT ? 1 : 0;
	y += dir == UP ? -1 : dir == DOWN ? 1 : 0;

	return maze[y][x];
}

void turn_right(int* dir) {
	*dir <<= 1;
	*dir = *dir > LEFT ? UP : *dir;
}

void turn_left(int* dir) {
	*dir >>= 1;
	*dir = *dir ? *dir : LEFT;
}

void right_hand(int x, int y, int dir) {
	gotoxy(x + 1, y + 1);
	fputs("*", stdout);
	record(x, y);

	forward(&x, &y, dir);
	while (still_in_maze(x, y)) {
		Sleep(100);
		turn_right(&dir);
		while (wall_ahead(x, y, dir))
			turn_left(&dir);
		forward(&x, &y, dir);
	}
	record(-1, -1);
}

void record(int x, int y) {
	static int index = 0;
	rec[index++] = x;
	rec[index++] = y;
}

int del_path(int i, int j) {
	int k = i;
	while (rec[j] >= 0)
		rec[i++] = rec[j++];
	rec[i] = -1;

	return k;
}

void shortest_route(void) {
	int i = 0, j, x, y, x1, y1;
	while (rec[i] >= 0) {
		x = rec[i], y = rec[i + 1];
		j = i + 2;
		while (rec[j] >= 0) {
			x1 = rec[j], y1 = rec[j + 1];
			if (x == x1 && y == y1) j = del_path(i, j);

			j += 2;
		}
		i += 2;
	}

	i = 0;
	while (rec[i] >= 0) {
		x = rec[i++];
		y = rec[i++];
		gotoxy(x + 1, y + 1);
		fputs("*", stdout);
		Sleep(100);
		gotoxy(x + 1, y + 1);
		fputs(" ", stdout);
	}
}