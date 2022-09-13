#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int dp[2000][2000];

void palindrome(int Arr[], int S, int E) {
	int i, flag = 0;
	if ((E - S + 1) % 2 == 0) {			
		for (i = 0; i < (E - S + 1) / 2; i++) {			
			if ((flag == 0) && (Arr[S + (E - S + 1) / 2 - i - 1] == Arr[S + (E - S + 1) / 2 + i])) {
				dp[S + (E - S + 1) / 2 - i - 1][S + (E - S + 1) / 2 + i] = 1;				
			}
			else {
				dp[S + (E - S + 1) / 2 - i - 1][S + (E - S + 1) / 2 + i] = 0;
				flag = 1;
			}
		}		
	}
	else {
		for (i = 0; i < (E - S) / 2; i++) {
			if ((flag== 0)&&(Arr[S + (E - S ) / 2 - i - 1] == Arr[S + (E - S) / 2 + i + 1]))
				dp[S + (E - S) / 2 - i - 1][S + (E - S) / 2 + i + 1] = 1;
			else {
				dp[S + (E - S) / 2 - i - 1][S + (E - S) / 2 + i + 1] = 0;
				flag = 1;
			}
		}
	}
}

int main(void) {
	int N, i, j, M, S, E;	
	int* Arr;
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
		for (j = 0; j < N; j++)
			dp[i][j] = -1;
		dp[i][i] = 1;
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);
		if (dp[S - 1][E - 1] == -1) {
			palindrome(Arr, S - 1, E - 1);
			printf("%d\n", dp[S - 1][E - 1]);
		}
		else
			printf("%d\n", dp[S - 1][E - 1]);
	}
	return 0;
}