#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, max = 0;
	int i, j, sum;
	int** map;
	scanf("%d %d", &N, &M);
	map = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int) * M);
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (j - 3 >= 0) {
				sum = map[i][j] + map[i][j - 1] + map[i][j - 2] + map[i][j - 3];
				if (sum >= max)
					max = sum;
			}
			if (j + 3 < M) {
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
				if (sum >= max)
					max = sum;
			}
			if (i - 3 >= 0) {
				sum = map[i][j] + map[i - 1][j ] + map[i - 2][j] + map[i - 3][j];
				if (sum >= max)
					max = sum;
			}
			if (i + 3 < N) {
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j - 1 >= 0) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i - 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 1 < M) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i][j + 1] + map[i - 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			if ((j - 1 >= 0) && (i + 1 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i][j - 1] + map[i + 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 1 < M) && (i + 1 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j - 2 >= 0) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i][j - 1] + map[i][j - 2] + map[i - 1][j - 2];
				if (sum >= max)
					max = sum;
			}
			if ((j - 2 >= 0) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i][j - 1] + map[i][j - 2] + map[i - 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j - 2 >= 0) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i][j - 1] + map[i - 1][j - 2] + map[i - 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j - 2 >= 0) && (i + 1 < N)) {
				sum = map[i][j] + map[i][j - 1] + map[i][j - 2] + map[i + 1][j - 2];
				if (sum >= max)
					max = sum;
			}
			if ((j - 2 >= 0) && (i + 1 < N)) {
				sum = map[i][j] + map[i][j - 1] + map[i][j - 2] + map[i + 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j - 2 >= 0) && (i + 1 < N)) {
				sum = map[i][j] + map[i][j - 1] + map[i + 1][j - 2] + map[i + 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j + 2 < M) && (i + 1 < N)) {
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
				if (sum >= max)
					max = sum;
			}
			if ((j + 2 < M) && (i + 1 < N)) {
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 2 < M) && (i + 1 < N)) {
				sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 2] + map[i + 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j + 2 < M) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
				if (sum >= max)
					max = sum;
			}
			if ((j + 2 < M) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 2 < M) && (i - 1 >= 0)) {
				sum = map[i][j] + map[i][j + 1] + map[i -1][j + 2] + map[i - 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j + 1 < M) && (i - 2 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i - 2][j] + map[i - 2][j + 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 1 < M) && (i - 2 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i - 2][j] + map[i - 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 1 < M) && (i - 2 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i - 2][j + 1] + map[i - 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j - 1 >= 0) && (i - 2 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i - 2][j] + map[i - 2][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j - 1 >= 0) && (i - 2 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i - 2][j] + map[i - 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j - 1 >= 0) && (i - 2 >= 0)) {
				sum = map[i][j] + map[i - 1][j] + map[i - 2][j - 1] + map[i - 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j - 1 >= 0) && (i + 2 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j - 1 >= 0) && (i + 2 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			if ((j - 1 >= 0) && (i + 2 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j - 1] + map[i + 1][j - 1];
				if (sum >= max)
					max = sum;
			}
			//
			if ((j + 1 < M) && (i + 2 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 1 < M) && (i + 2 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
				if (sum >= max)
					max = sum;
			}
			if ((j + 1 < M) && (i + 2 < N)) {
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j + 1] + map[i + 1][j + 1];
				if (sum >= max)
					max = sum;
			}
		}
	}

	

	printf("%d", max);
	return 0;
}