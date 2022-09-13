#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long Search(int Arr[], long long left, long long right, int N, int K) {
	long long mid;

	if (((right % 2) + (left % 2)) == 0)
		mid = (left / 2) + (right / 2);
	else if (((right % 2) + (left % 2)) == 1)
		mid = (left / 2) + (right / 2);
	else
		mid = (left / 2) + (right / 2) + 1;
	
	int i, result = 0;

	if (left < right) {
		for (i = 0; i < K; i++) {
			result += Arr[i] / mid;
		}
		if (result < N) {
			Search(Arr, left, mid, N, K);
		}
		else {
			Search(Arr, mid + 1, right, N, K);
		}
	}
	else {
		return mid-1;
	}	
	}

int main(void) {
	int K, N;
	int i;
	int* Arr;
	long long max = 0;
	long long result;


	scanf("%d %d", &K, &N);

	Arr = (int*)malloc(sizeof(int) * K);
	if (!Arr)
		return 1;

	for (i = 0; i < K; i++) {
		scanf("%d", &Arr[i]);
		if (max <= Arr[i])
			max = Arr[i];
	}

	result = Search(Arr, 1, max+1, N, K);
	printf("%d", result);	


	return 0;
}