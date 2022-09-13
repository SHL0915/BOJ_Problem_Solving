#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Arr[50001] = { 0 };


int main(void) {
	int n, i, j, sqr;
	scanf("%d", &n);

	for (i = 1; i <= 50000; i++) {
		if (i * i > n)
			break;
		Arr[i * i] = 1;
	}

	for (i = 1; i < n; i++) {
		if (i * i > n)
			break;
	}

	sqr = i;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= sqr; j++) {
			if (i + j * j <= n) {
				if (Arr[i + j * j] == 0)
					Arr[i + j * j] = Arr[i] + 1;
				else {
					if (Arr[i + j * j] > Arr[i] + 1) {
						Arr[i + j * j] = Arr[i] + 1;
					}
				}
			}
			else
				break;
		}
	}
	
	printf("%d", Arr[n]);
}

