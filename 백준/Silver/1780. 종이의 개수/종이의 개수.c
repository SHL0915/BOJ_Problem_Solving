#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int zero = 0;
int one = 0;
int minusone = 0;

void cut(int** Arr, int N, int x, int y) {	
	int sum = 0;
	int flag = 0;
	int i, j;
	if (N == 1) {
		if (Arr[y][x] == -1) {
			minusone++;
			return;
		}
		else if (Arr[y][x] == 0) {
			zero++;
			return;
		}
		else {
			one++;
			return;
		}
	}
	else {
		for (i = y; i < y + N; i++) {
			for (j = x; j < x + N; j++) {
				sum += Arr[i][j];
				if (Arr[i][j] != 0)
					flag = 1;
			}
		}
		if ((flag == 0) && (sum == 0)) {
			zero++;
			return;
		}
		else if (sum == N * N) {
			one++;
			return;
		}
		else if (sum == -(N * N)) {
			minusone++;
			return;
		}
		else {
			cut(Arr, N / 3, x, y);
			cut(Arr, N / 3, x + N/3, y);
			cut(Arr, N / 3, x + 2 * (N/3), y);
			cut(Arr, N / 3, x, y + N / 3);
			cut(Arr, N / 3, x + N / 3, y + N / 3);
			cut(Arr, N / 3, x + 2 * (N / 3), y + N / 3);
			cut(Arr, N / 3, x, y + 2 * (N / 3));
			cut(Arr, N / 3, x + N / 3, y + 2 * (N / 3));
			cut(Arr, N / 3, x + 2 * (N / 3), y + 2 * (N / 3));
		}
	}
}

int main(void) {
	int N;
	int** Arr;
	int i, j;
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++) {
			scanf("%d", &Arr[i][j]);
		}
	}
	cut(Arr, N, 0, 0);
	printf("%d\n%d\n%d", minusone, zero, one);
	return 0;
}