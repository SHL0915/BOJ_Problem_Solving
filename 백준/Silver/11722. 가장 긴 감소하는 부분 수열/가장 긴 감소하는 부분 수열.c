#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[1001] = { 0 };

void dp(int Arr[], int k, int N) {
	int i, temp = 0;
	if (val[k] == 0) {
		for (i = k + 1; i < N; i++) {
			if (Arr[k] > Arr[i]) {
				if (temp <= val[i]) {
					temp = val[i];
				}
			}			
		}
		val[k] = temp + 1;
		return;
	}
}

int main(void) {
	int N, i, max =0;
	int* Arr;

	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	val[N - 1] = 1;

	for (i = N - 2; i >= 0; i--) {
		dp(Arr, i, N);
	}

	for (i = 0; i < N; i++) {
		if (max <= val[i])
			max = val[i];
	}


	printf("%d", max);
	return 0;
}