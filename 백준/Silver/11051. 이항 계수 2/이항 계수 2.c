#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[1001] = { 0 };
int bin[1001][1001];

int dp(int N,int K) {
	if (K == 0) {
		bin[N][K] = 1;
		return bin[N][K];
	}
	else if (K == 1) {
		bin[N][K] = N;
		return bin[N][K];
	}
	else if (K == N) {
		bin[N][K] = 1;
		return bin[N][K];
	}
	else if (bin[N][K] == 0) {
		bin[N][K] = (dp(N - 1, K)%10007 + dp(N - 1, K - 1) % 10007) % 10007;
		return bin[N][K];
	}
	else
		return bin[N][K];
}

int main(void) {
	int i, j;
	int N, K;
	scanf("%d %d", &N, &K);

	for (i = 0; i < 1001; i++) {
		for (j = 0; j < 1001; j++)
			bin[i][j] = 0;
	}
	

	printf("%d", dp(N, K));
	return 0;
}