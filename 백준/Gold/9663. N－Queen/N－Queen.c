#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int count = 0;

int canPutQueen(int** Arr, int N, int x, int y) {
	int i;	
	for (i = 0; i < y; i++) {
		if (Arr[i][x] == 1)
			return 0;
	}
	for (i = 0; (x - i >= 0) && (y - i >= 0); i++) {
		if (Arr[y - i][x - i] == 1)
			return 0;
	}	
	for (i = 0; (x + i < N) && (y - i >= 0); i++) {
		if (Arr[y - i][x + i] == 1)
			return 0;
	}
	return 1;
}

void backTracking(int** Arr, int N, int M, int prev_x, int prev_y) {
	int i;
	if (M == 0) {			
		count++;		
	}
	else {
		for (i = 0; i < N; i++) {
			if (Arr[N - M][i] == 0) {
				if (canPutQueen(Arr, N, i, N - M)) {
					Arr[N - M][i] = 1;
					backTracking(Arr, N, M - 1, i, N - M);
					Arr[N - M][i] = 0;
				}				
			}
		}
	}
	
}

int main(void) {
	int N, i, j;
	int** Arr;
	scanf("%d", &N);

	Arr = (int**)malloc(sizeof(int *) * N);

	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++)
			Arr[i][j] = 0;
	}

	backTracking(Arr, N, N, 0, 0);

	printf("%d", count);
}