#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Arr[1000001] = { 0 };

int dp(int n) {
	if (Arr[n] == 0) {
		Arr[n] = (dp(n - 1) + dp(n - 2))%15746;
	}
	
	return Arr[n];
}

int main(void) {
	Arr[1] = 1;
	Arr[2] = 2;
	int N;
	scanf("%d", &N);
	printf("%d", dp(N));
}