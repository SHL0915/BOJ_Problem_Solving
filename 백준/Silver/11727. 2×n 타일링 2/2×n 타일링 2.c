#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Arr[1001] = { 0 };

int dp(int n) {
	if (Arr[n] != 0)
		return Arr[n] % 10007;
	else {
		Arr[n] = dp(n - 1) % 10007 + (2 * (dp(n - 2)) % 10007) % 10007;
		return Arr[n] % 10007;
	}

}

int main(void) {
	int n;
	scanf("%d", &n);
	Arr[1] = 1;
	Arr[2] = 3;
	printf("%d", dp(n));
	return 0;
}

