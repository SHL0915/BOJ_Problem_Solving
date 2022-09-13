#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int cmp(int A, int B) {
	return (A > B ? A : B);
}

int val1[100001] = { 0 };
int val2[100001] = { 0 };
int val3[100001] = { 0 };
int val[100001] = { 0 };

void dp(int** Arr, int n) {
	if ((n == 0) || (n == 1))
		return;
	else if (val[n] == 0) {
		val1[n] = cmp(val2[n-1] + Arr[n][0], val3[n-1] + Arr[n][0]);
		val2[n] = cmp(val1[n-1] + Arr[n][1], val3[n-1] + Arr[n][1]);
		val3[n] = val[n-1];
		val[n] = cmp(cmp(val1[n], val2[n]), val3[n]);
	}
	else
		return;
}

int main(void) {
	int T, n, i, j;
	int** Arr;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		Arr = (int**)malloc(sizeof(int*) * n);

		for (j = 0; j < n; j++) {
			Arr[j] = (int*)malloc(sizeof(int) * 2);
			scanf("%d", &Arr[j][0]);
		}
		for (j = 0; j < n; j++) {
			scanf("%d", &Arr[j][1]);
		}

		if (n == 1) {
			val1[0] = Arr[0][0];
			val2[0] = Arr[0][1];
			val[0] = cmp(val1[0], val2[0]);
		}
		else {
			val1[0] = Arr[0][0];
			val2[0] = Arr[0][1];
			val[0] = cmp(val1[0], val2[0]);
			val1[1] = cmp(val2[0] + Arr[1][0], val3[0] + Arr[1][0]);
			val2[1] = cmp(val1[0] + Arr[1][1], val3[0] + Arr[1][1]);
			val3[1] = val[0];
			val[1] = cmp(cmp(val1[1], val2[1]), val3[1]);
			for (j = 2; j < n; j++) {
				dp(Arr, j);
			}
		}
		printf("%d\n", val[n - 1]);
		for (j = 0; j < n; j++) {
			val1[j] = 0;
			val2[j] = 0;
			val3[j] = 0;
			val[j] = 0;
		}
	}
	return 0;
}