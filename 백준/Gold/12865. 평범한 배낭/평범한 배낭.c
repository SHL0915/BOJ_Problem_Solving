#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, K, i, j, temp;
	int** Arr;
	int val[100001] = {0};

	scanf("%d %d", &N, &K);
	Arr = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &Arr[i][0], &Arr[i][1]);
	}

	for (i = 0; i < N; i++) {
		for (j = K; j >= 0; j--) {
			temp = val[j];
			if (Arr[i][0] <= j) {
				if (Arr[i][1] + val[j - Arr[i][0]] >= temp)
					val[j] = Arr[i][1] + val[j - Arr[i][0]];
			}
		}
	}

	printf("%d", val[K]);

}