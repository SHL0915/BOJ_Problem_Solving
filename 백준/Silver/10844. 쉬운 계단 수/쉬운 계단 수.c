#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N;
	int i, j;
	long long Arr[10] = { 0 };
	long long temp[10];
	int val = 0;

	scanf("%d", &N);

	for (i = 1; i <= 9; i++) {
		Arr[i] = 1;
	}

	for (i = 2; i <= N; i++) {
		temp[0] = Arr[1] % 1000000000;
		for (j = 1; j <= 8; j++) {
			temp[j] = Arr[j - 1] % 1000000000 + Arr[j + 1] % 1000000000;
		}
		temp[9] = Arr[8];
		for (j = 0; j <= 9; j++)
			Arr[j] = temp[j] % 1000000000;
	}

	for (i = 0; i < 10; i++) {
		val += Arr[i] % 1000000000;
		val %= 1000000000;
	}


	printf("%d", val);
	return 0;
}