#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, K, i;
	int* Arr;
	int temp;
	int sum = 0;
	scanf("%d %d", &N, &K);
	Arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	temp = K;
	for (i = N - 1; i >= 0; i--) {
		if (temp == 0)
			break;
		else if (temp < Arr[i])
			continue;
		else {
			sum += temp / Arr[i];
			temp = temp % Arr[i];
		}
	}

	printf("%d", sum);
	return 0;
}