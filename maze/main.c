#include <stdio.h>
#include <windows.h>

#define MAZE_SIZE 10
#define UP 1
#define RIGHT 2
#define DOWN 4
#define LEFT 8

int get_shape(int m[][MAZE_SIZE], int x, int y);
void draw_maze(int m[][MAZE_SIZE]);
void gotoxy(int x, int y);

int main() {
	UINT defaultCP = GetConsoleOutputCP();
	SetConsoleOutputCP(437);
	SetConsoleOutputCP(defaultCP);

	return 0;
}

int get_shape(int (*m)[MAZE_SIZE], int x, int y) {	
	static int shape[] = { 32, 179, 196, 192, 179, 179, 218, 195, 196, 217, 196, 193, 191, 180, 194, 197 };
	int s = 0;
	if (m[y][x]) {
		if (x > 0 && m[y][x - 1]) s |= LEFT;
		if (x < MAZE_SIZE - 1 && m[y][x + 1]) s |= RIGHT;
		if (y > 0 && m[y - 1][x]) s |= UP;
		if (y < MAZE_SIZE -1 && m[y + 1][x]) s |= DOWN;
	}

	return s;
}
void draw_maze(int m[][MAZE_SIZE]) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			//gotoxy(i + 1, j + 1);
			putchar(get_shape(m, i, j));
		}
	}
}

void gotoxy(int x, int y) {
	printf("\033[%d;%df", y, x);
}