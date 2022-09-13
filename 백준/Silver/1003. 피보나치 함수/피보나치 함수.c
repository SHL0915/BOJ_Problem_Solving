#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Arr[43] = { 0 };

int dp(int n) {
	if (n == 0)
		return Arr[n];
	else if ((n == 1) || (n == 2))
		return Arr[n];
	else if (Arr[n] == 0) {
		Arr[n] = dp(n - 1) + dp(n - 2);
		return Arr[n];
	}
	else {
		return Arr[n];
	}
}



int main(void) {
	int T, N;
	int i;
	scanf("%d", &T);

	Arr[0] = 0;
	Arr[1] = 1;
	Arr[2] = 1;

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		if (N == 0)
			printf("1 0\n");
		else if (N % 2 == 0) {
			printf("%d %d\n", dp(N-1), dp(N));
		}
		else {
			printf("%d %d\n", dp(N - 1), dp(N));
		}
	}

	return 0;
}