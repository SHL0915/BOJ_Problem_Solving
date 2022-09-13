#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b, int c) {
	return ((a >= b ? a : b) >= c ? (a >= b ? a : b) : c);
}

int val[10001] = { 0 };

int main(void) {
	int n;
	int i;
	int temp;
	int* Arr;

	scanf("%d", &n);

	Arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &Arr[i]);
	
	val[1] += Arr[0];
	val[2] += Arr[0] + Arr[1];
	val[3] += compare(Arr[0] + Arr[1], Arr[0] + Arr[2], Arr[1] + Arr[2]);
	
	temp = Arr[1] + Arr[2];

	for (i = 4; i <= n; i++) {
		val[i] = compare(val[i - 2] + Arr[i - 1], val[i - 3] + Arr[i - 2] + Arr[i - 1], temp);
		temp = val[i - 3] + Arr[i - 2] + Arr[i - 1];
	}

	printf("%d", val[n]);

	return 0;
}