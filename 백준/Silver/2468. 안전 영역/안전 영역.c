#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void DFS(int** mark, int** Arr, int x, int y, int N) {
	if (mark[y][x] != 0)
		return;
	mark[y][x] = 1;
	if ((x - 1 >= 0) && (Arr[y][x - 1] == 1)) {
		if (mark[y][x - 1] == 0)
			DFS(mark, Arr, x - 1, y, N);
	}
	if ((y - 1 >= 0) && (Arr[y - 1][x] == 1)) {
		if (mark[y - 1][x] == 0)
			DFS(mark, Arr, x, y - 1, N);
	}
	if ((x + 1 < N) && (Arr[y][x + 1] == 1)) {
		if (mark[y][x + 1] == 0)
			DFS(mark, Arr, x + 1, y, N);
	}
	if ((y + 1 < N) && (Arr[y + 1][x] == 1)) {
		if (mark[y + 1][x] == 0)
			DFS(mark, Arr, x, y + 1, N);
	}
}

int main(void) {
	int N, max = 0;
	int count;
	int i, j, k;
	int** map, ** temp;
	int** mark;
	scanf("%d", &N);
	map = (int**)malloc(sizeof(int*) * N);
	temp = (int**)malloc(sizeof(int*) * N);
	mark = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int) * N);
		temp[i] = (int*)malloc(sizeof(int) * N);
		mark[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (k = 0; k <= 100; k++) {

		count = 0;

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				mark[i][j] = 0;
				if (map[i][j] <= k)
					temp[i][j] = 0;
				else
					temp[i][j] = 1;
			}
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				mark[i][j] = 0;
				if (map[i][j] <= k)
					temp[i][j] = 0;
				else
					temp[i][j] = 1;
			}
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if ((mark[i][j] == 0)&&(temp[i][j] == 1)) {
					DFS(mark, temp, j, i, N);
					count++;
				}
			}
		}

		if (max <= count) {			
			max = count;
		}
	}

	printf("%d", max);


}