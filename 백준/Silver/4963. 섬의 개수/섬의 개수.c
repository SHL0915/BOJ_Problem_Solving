#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
}coor;

void DFS(int** map, coor pos, int** mark, int h, int w) {
	coor temp;

	mark[pos.y][pos.x] = 1;

	if ((pos.x - 1 >= 0) && (map[pos.y][pos.x - 1] == 1)) {
		temp.x = pos.x - 1;
		temp.y = pos.y;
		if (mark[temp.y][temp.x] == 0) {
			DFS(map, temp, mark, h, w);
		}
	}
	if ((pos.y - 1 >= 0) && (map[pos.y - 1][pos.x] == 1)) {
		temp.x = pos.x;
		temp.y = pos.y - 1;
		if (mark[temp.y][temp.x] == 0) {
			DFS(map, temp, mark, h, w);
		}
	}
	if ((pos.y + 1 < h) && (map[pos.y + 1][pos.x] == 1)) {
		temp.x = pos.x;
		temp.y = pos.y + 1;
		if (mark[temp.y][temp.x] == 0) {
			DFS(map, temp, mark, h, w);
		}
	}
	if ((pos.x + 1 < w) && (map[pos.y][pos.x + 1] == 1)) {
		temp.x = pos.x + 1;
		temp.y = pos.y;
		if (mark[temp.y][temp.x] == 0) {
			DFS(map, temp, mark, h, w);
		}
	}
	if ((pos.x - 1 >= 0) && (pos.y - 1 >= 0)) {
		temp.x = pos.x - 1;
		temp.y = pos.y - 1;
		if ((map[temp.y][temp.x] == 1) && (mark[temp.y][temp.x] == 0))
			DFS(map, temp, mark, h, w);
	}
	if ((pos.x + 1 < w) && (pos.y - 1 >= 0)) {
		temp.x = pos.x + 1;
		temp.y = pos.y - 1;
		if ((map[temp.y][temp.x] == 1) && (mark[temp.y][temp.x] == 0))
			DFS(map, temp, mark, h, w);
	}
	if ((pos.x + 1 < w) && (pos.y + 1 < h)) {
		temp.x = pos.x + 1;
		temp.y = pos.y + 1;
		if ((map[temp.y][temp.x] == 1) && (mark[temp.y][temp.x] == 0))
			DFS(map, temp, mark, h, w);
	}
	if ((pos.x - 1 >= 0) && (pos.y + 1 < h)) {
		temp.x = pos.x - 1;
		temp.y = pos.y + 1;
		if ((map[temp.y][temp.x] == 1) && (mark[temp.y][temp.x] == 0))
			DFS(map, temp, mark, h, w);
	}
}

int main(void) {
	int w, h, i, j, count;
	coor pos;
	int** map, ** mark;
	
	while (1) {
		scanf("%d %d", &w, &h);

		if ((w == 0) && (h == 0))
			break;

		count = 0;
		map = (int**)malloc(sizeof(int*) * h);
		mark = (int**)malloc(sizeof(int*) * h);

		for (i = 0; i < h; i++) {
			map[i] = (int*)malloc(sizeof(int) * w);
			mark[i] = (int*)malloc(sizeof(int) * w);
			for (j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
				mark[i][j] = 0;
			}
		}

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if ((map[i][j] == 1) && (mark[i][j] == 0)) {
					pos.x = j;
					pos.y = i;
					count++;
					DFS(map, pos, mark, h, w);
				}
			}
		}

		printf("%d\n", count);
	}
}