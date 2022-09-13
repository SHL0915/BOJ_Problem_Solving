#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int A, B, m, i, j;
	int Arr[25];
	int num = 0, temp = 1;

	scanf("%d %d", &A, &B);
	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%d", &Arr[i]);
	}

	for (i = m - 1; i >= 0; i--) {
		num += temp * Arr[i];
		temp *= A;
	}

	temp = 1;
	for (i = 0;; i++) {
		if (temp > num) {
			temp /= B;
			break;
		}
		temp *= B;
	}

	for (j = 0; j < i; j++) {
		printf("%d ", num / temp);
		num %= temp;
		temp /= B;
	}

	return 0;
}