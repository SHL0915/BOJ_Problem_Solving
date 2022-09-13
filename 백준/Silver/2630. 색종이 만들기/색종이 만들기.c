#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int blue = 0;
int white = 0;

void cut(int** Arr, int N, int x, int y) {
	int i, j, sum = 0;
	if (N == 1) {
		if (Arr[y][x] == 0) {
			white++;
			return;
		}
		else if (Arr[y][x] == 1) {
			blue++;
			return;
		}
	}
	else {		
		for (i = y; i < y + N; i++) {
			for (j = x; j < x + N; j++) {
				sum += Arr[i][j];
			}
		}		
		if (sum == N * N) {
			blue++;
			return;
		}
		else if (sum == 0) {
			white++;
			return;
		}
		else {
			cut(Arr, N / 2, x, y);
			cut(Arr, N / 2, x + N / 2, y);
			cut(Arr, N / 2, x, y + N / 2);
			cut(Arr, N / 2, x + N / 2, y + N / 2);
		}
	}
}

int main(void) {
	int** Arr;
	int N, i, j;
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++) {
			scanf("%d", &Arr[i][j]);
		}
	}
	cut(Arr, N, 0, 0);
	printf("%d\n%d", white, blue);
	return 0;
}