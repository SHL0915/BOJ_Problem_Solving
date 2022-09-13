#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int dp[500][500]; // [첫장][마지막장]

void Merge(int left, int right_end, int Arr[]) {
	int i;
	int min, temp;
	int flag = 0;
	for (i = left; i < right_end; i++) {
		if (dp[left][i] == -1) {
			Merge(left, i, Arr);
		}
		if (dp[i + 1][right_end] == -1) {
			Merge(i + 1, right_end, Arr);
		}

		if (left == 0)
			temp = dp[left][i] + dp[i + 1][right_end] + Arr[right_end];
		else
			temp = dp[left][i] + dp[i + 1][right_end] + Arr[i] - Arr[left - 1] + Arr[right_end] - Arr[i];

		if (flag == 0) {
			min = temp;
			flag = 1;
		}
		else {
			if (min >= temp)
				min = temp;
		}
	}

	dp[left][right_end] = min;

	return;
}


int main(void) {
	int T, K, i, j,k;
	int* Arr;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &K);
		Arr = (int*)malloc(sizeof(int) * K);
		for (j = 0; j < K; j++) {
			scanf("%d", &Arr[j]);
		}

		for (j = 1; j < K; j++) {
			Arr[j] += Arr[j - 1];
		}

		for (j = 0; j < K; j++) {
			for (k = 0; k < K; k++)
				dp[j][k] = -1;
		}

		for (j = 0; j < K; j++) {
			dp[j][j] = 0;
		}		

		Merge(0, K - 1, Arr);

		printf("%d\n", dp[0][K - 1]);
		free(Arr);
	}
	
}