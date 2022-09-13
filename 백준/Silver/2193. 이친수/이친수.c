#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long Arr[91] = { 0 };

long long dp(long long n) {	
	if (Arr[n] != 0)
		return Arr[n];
	else {
		Arr[n] = dp(n - 1) + dp(n - 2);
		return Arr[n];
	}
}

int main(void) {
	long long n;
	scanf("%lld", &n);
	Arr[1] = 1;
	Arr[2] = 1;
	printf("%lld", dp(n));
	return 0;
}