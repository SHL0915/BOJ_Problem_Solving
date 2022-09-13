#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int dp(int** Arr, int n, int m) {
	int i;
	int temp = 0;
	if (n == 0) {
		return Arr[n][m];
	}
	if (n == 1) {
		Arr[n][m] = m;
		return Arr[n][m];
	}
	else if (Arr[n][m] == 0) {
		for (i = n - 1; i < m; i++) {
			temp += dp(Arr, n - 1, i);
		}
		Arr[n][m] = temp;
		return Arr[n][m];
	}
	else
		return Arr[n][m];

}

int main(void) {
	int T, N, M;
	int i, j;
	int** Arr;

	scanf("%d", &T);

	Arr = (int**)malloc(sizeof(int*) * 30);

	for (i = 0; i < 30; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * 30);
		for (j = 0; j < 30; j++) {
			if (i == j)
				Arr[i][j] = 1;
			else
				Arr[i][j] = 0;
		}
	}

	for (i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		printf("%d\n", dp(Arr, N, M));
	}
	return 0;
}