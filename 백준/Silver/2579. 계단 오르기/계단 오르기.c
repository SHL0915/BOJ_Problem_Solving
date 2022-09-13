#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[301] = { 0 };

int compare(int a, int b) {
	return (a >= b ? a : b);
}

int dp(int* Arr, int N) {
	if (val[N] == 0) {
		val[N] = compare(dp(Arr, N - 2), dp(Arr, N - 3) + Arr[N - 2]) + Arr[N - 1];
		return val[N];
	}
	else
		return val[N];
}

int main(void) {
	int N;
	int i;
	int* Arr;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	val[1] = Arr[0];
	val[2] = Arr[0] + Arr[1];
	val[3] = compare(Arr[0], Arr[1]) + Arr[2];

	printf("%d",dp(Arr, N));
	return 0;
}