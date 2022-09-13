#include <stdio.h>
#include <stdlib.h>

int count = 0; // 부분수열의 개수 count

void BackTracking(int* Arr, int* Sequence, int N, int k, int start, int S);

int main(void) {
	int N, *Arr, S, *Sequence, i; // N개의 정수로 이루어진 수열 Arr, 부분수열 Sequence, 부분수열의 합 S
	scanf("%d %d", &N, &S);
	Arr = (int*)malloc(sizeof(int) * N);	
	Sequence = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) 
		scanf("%d", &Arr[i]);	
	for (i = 0; i < N; i++) {
		Sequence[0] = Arr[i];
		BackTracking(Arr, Sequence, N, 1, i+1, S); // BackTracking으로 모든 부분수열을 탐색	
	}		
	printf("%d", count);
	return 0;
}

void BackTracking(int* Arr, int* Sequence, int N, int k, int start, int S) {
	int i, sum = 0;
	for (i = 0; i < k; i++) 
		sum += Sequence[i];	
	if (sum == S)
		count++;
	if (k == N)
		return;
	else {
		for (i = start; i < N; i++) {
			Sequence[k] = Arr[i];
			BackTracking(Arr, Sequence, N, k + 1, i + 1, S);
		}
	}
}