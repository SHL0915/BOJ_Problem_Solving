#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, K;
	int i;
	int max, temp;
	int* Arr;

	scanf("%d %d", &N, &K);

	Arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	for (i = 1; i < N; i++) {
		Arr[i] += Arr[i - 1];
	}

	max = Arr[K - 1];

	for (i = 0; i < N - K; i++) {
		temp = Arr[K + i] - Arr[i];
		if (max <= temp)
			max = temp;
	}

	printf("%d", max);
}