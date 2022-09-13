#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Search(int Arr[], int bottom, int top, int N, int M) {
	int mid = (top+bottom)/2;
	int i, result;
	long long sum = 0;

	if (top > bottom) {
		for (i = 0; i < N; i++) {
			if (Arr[i] - mid > 0)
				sum += Arr[i] - mid;
		}
		if (sum >= M)
			result = Search(Arr, mid + 1, top, N, M);
		else
			result = Search(Arr, bottom, mid, N, M);
	}
	else
		return mid - 1;			
}


int main(void) {
	int N, M;
	int i;
	int* Arr;
	int result;
	int max = 0;

	scanf("%d %d", &N, &M);
	Arr = (int*)malloc(sizeof(int) * N);
	if (!Arr)
		return 1;

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
		if (Arr[i] >= max)
			max = Arr[i];
	}

	result = Search(Arr, 0, max + 1, N, M);

	printf("%d", result);

	return 0;
}