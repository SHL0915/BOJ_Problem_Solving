#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int** A, ** B;
	int N, M, K, i, j, sum, k;
	scanf("%d %d", &N, &M);
	A = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) {
		A[i] = (int*)malloc(sizeof(int) * M);
		for (j = 0; j < M; j++)
			scanf("%d", &A[i][j]);
	}
	scanf("%d %d", &M, &K);	
	B = (int**)malloc(sizeof(int*) * M);
	for (i = 0; i < M; i++) {
		B[i] = (int*)malloc(sizeof(int) * K);
		for (j = 0; j < K; j++)
			scanf("%d", &B[i][j]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < K; j++) {
			sum = 0;
			for (k = 0; k < M; k++) {
				sum += A[i][k] * B[k][j];
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
	return 0;
}