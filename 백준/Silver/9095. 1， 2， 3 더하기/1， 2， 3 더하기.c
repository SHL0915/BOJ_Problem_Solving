#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Arr[12] = { 0 };

int dp(int n) {
	if (n == 1)
		return Arr[n];
	else if (n == 2)
		return Arr[n];
	else if (n == 3)
		return Arr[n];
	else if (Arr[n] == 0) {
		Arr[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
		return Arr[n];
	}
	else
		return Arr[n];
}

int main(void) {
	int T, n;
	int i;
	Arr[1] = 1;
	Arr[2] = 2;
	Arr[3] = 4;
	
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%d\n", dp(n));
	}

	return 0;
}