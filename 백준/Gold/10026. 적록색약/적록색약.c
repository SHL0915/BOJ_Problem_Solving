#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void DFS(int** Arr, int** mark, int x, int y, int N) {
	if (mark[y][x] != 0)
		return;
	mark[y][x] = 1;
	if ((x - 1 >= 0) && (Arr[y][x - 1] == Arr[y][x]))
		DFS(Arr, mark, x - 1, y, N);
	if ((y - 1 >= 0) && (Arr[y-1][x] == Arr[y][x]))
		DFS(Arr, mark, x, y - 1, N);
	if ((x + 1 < N) && (Arr[y][x + 1] == Arr[y][x]))
		DFS(Arr, mark, x + 1, y, N);
	if ((y+1 < N) && (Arr[y + 1][x] == Arr[y][x]))
		DFS(Arr, mark, x, y + 1, N);
}

int main(void) {
	int N, i, j, count = 0;
	int** Normal, ** weakness, ** mark;	
	char line[101];

	scanf("%d", &N);
	Normal = (int**)malloc(sizeof(int*) * N);
	weakness = (int**)malloc(sizeof(int*) * N);
	mark = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) {
		Normal[i] = (int*)malloc(sizeof(int) * N);
		weakness[i] = (int*)malloc(sizeof(int) * N);
		mark[i] = (int*)malloc(sizeof(int) * N);
		scanf("%s", line);
		for (j = 0; j < N; j++) {
			mark[i][j] = 0;
			if (line[j] == 'R') {
				Normal[i][j] = 1;
				weakness[i][j] = 1;
			}
			else if (line[j] == 'G') {
				Normal[i][j] = 2;
				weakness[i][j] = 1;
			}
			else {
				Normal[i][j] = 3;
				weakness[i][j] = 3;
			}
		}
	}

	for (i = 0; i < N; i++) {		
		for (j = 0; j < N; j++) {
			if (mark[i][j] == 0) {
				count++;
				DFS(Normal, mark, j, i, N);
			}
		}		
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			mark[i][j] = 0;
		}
	}

	printf("%d ", count);
	count = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (mark[i][j] == 0) {
				count++;
				DFS(weakness, mark, j, i, N);
			}
		}
	}
	printf("%d", count);
	return 0;
}