#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backTracking(int* Result, int N, int M, int k) {
	int i;
	if (k == 0) {
		for (i = 0; i < M; i++) {
			printf("%d ", Result[i]);
		}
		printf("\n");
	}
	else {
		for (i = 1; i <= N; i++) {
			Result[M - k] = i;
			backTracking(Result, N, M, k - 1);
			Result[M - k] = 0;
		}
	}
}

int main(void) {
	int N, M;
	
	int* Result;

	scanf("%d %d", &N, &M);
	Result = (int*)malloc(sizeof(int) * N);

	backTracking(Result, N, M, M);
	

	return 0;
}