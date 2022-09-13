#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


long long dp(long long** Arr, long long N, long long K) {
	if (K == 0)
		return Arr[N][K];
	else if (N == 0)
		return Arr[N][K];
	else if (Arr[N][K] == 0) {
		Arr[N][K] = dp(Arr, N - 1, K) % 1000000000 + dp(Arr, N, K - 1)%1000000000;
		Arr[N][K] = Arr[N][K] % 1000000000;
		return Arr[N][K];
	}
	else
		return Arr[N][K];
}



int main(void) {
	long long N, K, i, j;
	long long** Arr;


	scanf("%lld %lld", &N, &K);

	Arr = (long long**)malloc(sizeof(long long*) * (N + 1));
	for (i = 0; i <= N; i++) {
		Arr[i] = (long long*)malloc(sizeof(long long) * (K + 1));
	}


	for (i = 0; i <= N; i++) {
		for (j = 0; j <= K; j++)
			Arr[i][j] = 0;
	}

	for (i = 0; i <= K; i++) {
		Arr[0][i] = 1;
	}
	for (i = 0; i <= N; i++) {
		Arr[i][1] = 1;
	}
	for (i = 0; i <= N; i++) {
		Arr[i][0] = 0;
	}	

	printf("%lld", dp(Arr,N,K));
}