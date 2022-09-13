#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int val[3] = { 0 };

int find_Min(int a, int b, int c) {
	return ((a <= b ? a : b) <= c ? (a <= b ? a : b) : c);
}

int compare(int a, int b) {
	return (a < b ? a : b);
}

int dp(int** Arr, int N) {
	int i;
	int temp0, temp1, temp2;
	val[0] = Arr[0][0];
	val[1] = Arr[0][1];
	val[2] = Arr[0][2];
	for (i = 1; i < N; i++) {
		temp0 = val[0];
		temp1 = val[1];
		temp2 = val[2];
		val[0] = Arr[i][0] + compare(temp1, temp2);
		val[1] = Arr[i][1] + compare(temp0, temp2);
		val[2] = Arr[i][2] + compare(temp0, temp1);
	}
	return find_Min(val[0], val[1], val[2]);
}

int main(void) {
	int N;
	int i;
	int** Arr;

	scanf("%d", &N);

	Arr = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		Arr[i] = malloc(sizeof(int) * 3);
	}

	for (i = N-1; i >= 0; i--) {
		scanf("%d %d %d", &Arr[i][0], &Arr[i][1], &Arr[i][2]);
	}
	


	printf("%d", dp(Arr, N));
}