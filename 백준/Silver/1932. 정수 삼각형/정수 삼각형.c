#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(int a, int b) {
	return (a > b ? a : b);
}

int main(void) {
	int n;
	int i, j;
	int temp[500];
	int Arr[500];
	int max = 0;

	scanf("%d", &n);
	scanf("%d", &Arr[0]);
	for (i = 2; i <= n; i++) {
		for (j = 0; j < i-1; j++) {
			temp[j] = Arr[j];
			scanf("%d", &Arr[j]);
		}
		scanf("%d", &Arr[j]);
		Arr[0] += temp[0];
		for (j = 1; j < i-1; j++) {
			Arr[j] += compare(temp[j - 1], temp[j]);
		}
		Arr[i - 1] += temp[i - 2];
	}
	for (i = 0; i < n; i++) {
		if (max <= Arr[i])
			max = Arr[i];
	}

	printf("%d", max);
	return 0;
}