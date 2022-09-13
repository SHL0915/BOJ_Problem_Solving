#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Arr[10] = { 0 };
int temp[10] = { 0 };

void dp(int N) {
	int i, j;
	if (N == 1) {
		for (i = 0; i < 10; i++) {
			Arr[i] = 1;
			temp[i] = 1;
		}
		return;
	}
	else {
		for (i = 9; i >= 0; i--) {
			for (j = i + 1; j < 10; j++) {
				Arr[i] += (temp[j] % 10007);
				Arr[i] = Arr[i] % 10007;
			}
		}
		for (i = 0; i < 10; i++) {
			temp[i] = Arr[i] % 10007;
		}
		return;
	}
	
}

int main(void) {
	int N, i, result = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		dp(i);
	}

	for (i = 0; i < 10; i++) {
		result += (Arr[i]%10007);
		result = result % 10007;
	}

	printf("%d", result);
	return 0;
}