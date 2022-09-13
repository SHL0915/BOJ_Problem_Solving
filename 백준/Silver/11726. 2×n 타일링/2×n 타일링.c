#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Arr[1001] = { 0 };

int dp(int n) {
	if (n == 1)
		return Arr[n];
	else if (n == 2)
		return Arr[n];
	else if (Arr[n] == 0) {
		Arr[n] = (dp(n - 2) + dp(n - 1))%10007;
		return Arr[n];
	}
	else
		return Arr[n];
}

int main(void) {
	int n;
	scanf("%d", &n);

	Arr[1] = 1;
	Arr[2] = 2;
	
	printf("%d", dp(n));
	return 0;
}