#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Arr[31] = { 0 };

int dp(int N) {
	int i;
	if (N % 2 == 1)
		return 0;
	else if (Arr[N] == 0) {
		for (i = 2; i <= N; i += 2) {
			if (i == 2)
				Arr[N] += 3 * dp(N - i);
			else
				Arr[N] += 2 * dp(N - i);
		}
		return Arr[N];
	}
	else
		return Arr[N];
}

int main(void) {
	int N;
	scanf("%d", &N);

	Arr[0] = 1;
	Arr[2] = 3;

	printf("%d", dp(N));
}