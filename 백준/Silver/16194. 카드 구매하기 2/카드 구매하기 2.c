#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[1001] = { 0 }; // N장의 카드를 구매하는 최소가격을 저장하는 배열 val

void DP(int N, int * Arr); // N장의 카드를 구매하는 최소가격을 구하는 함수 DP

int main(void) {
	int N, *Arr, i; // 구매하려는 카드의 개수 N, 카드 가격에 대한 정보를 담은 배열 Arr
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	val[0] = 0;
	val[1] = Arr[0];
	DP(N, Arr);
	printf("%d", val[N]);
	return 0;
}

void DP(int N, int * Arr) {
	int i, min = -1;
	if ((N == 1) || (N == 0))  // base case
		return;
	else {
		for (i = 0; i < N; i++) { // N-i 장을 한꺼번에 사는 경우
			if (val[i] == 0) 
				DP(i, Arr);			
			if (min == -1)
				min = val[i] + Arr[N - i - 1];
			else if (min >= val[i] + Arr[N - i - 1])
				min = val[i] + Arr[N - i - 1];
		}
		val[N] = min;
		return;
	}
}
