#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* Arr;
	int N, M, i, j;
	int k;
	scanf("%d %d", &N, &M);

	Arr = (int*)malloc(sizeof(int) * N);
	
	scanf("%d", &Arr[0]);

	for (k = 1; k < N; k++) {
		scanf("%d", &Arr[k]);
		Arr[k] += Arr[k - 1];
	}

	for (k = 0; k < M; k++) {
		scanf("%d %d", &i, &j);
		if (i == 1)
			printf("%d\n", Arr[j - 1]);
		else
			printf("%d\n", Arr[j - 1] - Arr[i - 2]);
	}

	return 0;
}