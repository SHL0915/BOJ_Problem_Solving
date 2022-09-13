#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void backTracking(int Arr[], int temp[], int N, int M, int k) {
	int i, j;
	if (k == 0) {
		for (i = 0; i < M; i++) {
			printf("%d ", temp[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (i = 0; i < N; i++) {
			if (Arr[i] == 0) {
				temp[M - k] = i + 1;
				Arr[i] = 1;
				backTracking(Arr, temp, N, M, k - 1);
				Arr[i] = 0;
			}
		}
	}
}

int main(void) {
	int* Arr, * temp;
	int i;
	int N, M;
	scanf("%d %d", &N, &M);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * M);
	for (i = 0; i < N; i++) {
		Arr[i] = 0;
	}

	backTracking(Arr, temp, N, M, M);


	return 0;
}