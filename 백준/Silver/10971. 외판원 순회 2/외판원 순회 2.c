#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int min = 10000000;
int sum;

void Traverse(int** Arr, int* mark, int N, int k, int start, int j) {
	int i;	
	if (k == N - 1) {		
		if (Arr[j][start] != 0) {
			sum += Arr[j][start];
			if (min >= sum)
				min = sum;
			sum -= Arr[j][start];
		}
		else
			return;
	}
	else {
		for (i = 0; i < N; i++) {
			if (mark[i] != 0)
				continue;
			else {
				if (Arr[j][i] != 0) {					
					mark[i] = 1;
					sum += Arr[j][i];
					Traverse(Arr, mark, N, k + 1, start, i);
					sum -= Arr[j][i];
					mark[i] = 0;
				}
			}
		}
	}
	return;
}

int main(void) {
	int N, ** Arr, * mark, i, j; // N개의 도시, 비용 행렬 Arr, 도시의 여행 여부를 저장하는 mark
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	mark = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		mark[i] = 0;
		for (j = 0; j < N; j++)
			scanf("%d", &Arr[i][j]);
	}
	for (i = 0; i < N; i++) { // 도시의 모든 순회 경로를 Backtracking 
		sum = 0;
		mark[i] = 1;
		for (j = 0; j < N; j++) {
			if (Arr[i][j] != 0) {
				mark[j] = 1;
				sum += Arr[i][j];
				Traverse(Arr, mark, N, 1, i, j);
				sum -= Arr[i][j];
				mark[j] = 0;
			}
		}
		mark[i] = 0;
	}
	printf("%d", min);
	return 0;
}