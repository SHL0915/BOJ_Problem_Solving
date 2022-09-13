#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Arr[1000001] = { 0 };

void isPrimeNum(void) {
	int i, j;

	for (i = 2; i < 1000000; i++) {
		if (Arr[i] == 0) {
			for (j = 2;; j++) {
				if (i * j > 1000000)
					break;
				else
					Arr[i * j] = 1;
			}
		}
	}
}

int main(void) {
	int i, j, n;
	
	isPrimeNum();

	for (i = 0;; i++) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (j = 3; j <= n-3; j += 2) {
			if ((Arr[j] == 0) && (Arr[n - j] == 0)) {
				printf("%d = %d + %d\n", n, j, n - j);
				break;
			}
		}
	}
}