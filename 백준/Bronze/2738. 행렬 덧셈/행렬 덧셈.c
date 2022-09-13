#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int ** A, ** B, N, M, i, j; // 크기가 N * M 인 행렬 A, B
	scanf("%d %d", &N, &M);
	A = (int**)malloc(sizeof(int*) * N);
	B = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) { // 행렬 A를 입력 받음
		A[i] = (int*)malloc(sizeof(int) * M);
		B[i] = (int*)malloc(sizeof(int) * M);
		for (j = 0; j < M; j++)
			scanf("%d", &A[i][j]);
	}
	for (i = 0; i < N; i++) // 행렬 B를 입력 받음
		for (j = 0; j < M; j++)
			scanf("%d", &B[i][j]);
	for (i = 0; i < N; i++) { // 행렬 A와 B의 덧셈을 출력
		for (j = 0; j < M; j++)
			printf("%d ", A[i][j] + B[i][j]);
		printf("\n");
	}
	return 0;
}