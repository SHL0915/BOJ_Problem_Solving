#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int** Arr;
	int N, M;
	int i, j;
	int x1, x2, y1, y2;

	scanf("%d %d", &N, &M);

	Arr = (int**)malloc(sizeof(int*) * N+1);
	for (i = 0; i <= N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N+1);
		for (j = 0; j <= N; j++) {
			Arr[i][j] = 0;
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &Arr[i][j]);
		}
	}


	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			Arr[i][j] += Arr[i - 1][j] + Arr[i][j-1] - Arr[i-1][j-1];
		}
	}

	

	for (i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", Arr[x2][y2] - Arr[x1 - 1][y2] - Arr[x2][y1 - 1] + Arr[x1 - 1][y1 - 1]);
	}

	return 0;
}