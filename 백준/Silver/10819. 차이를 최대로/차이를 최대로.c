#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int max = 0; // 최댓값 max

int calc(int A, int B) { // 두 수의 차를 구하는 함수
	return A > B ? A - B : B - A;
}

void BackTracking(int Arr[], int temp[], int mark[], int N, int k) {
	int sum = 0, i;
	if (k == 0) { // backtracking이 종료됨
		for (i = 0; i < N - 1; i++) {
			sum += calc(temp[i], temp[i + 1]);
		}
		if (sum >= max)
			max = sum;
	}
	else { 
		for (i = 0; i < N; i++) {
			if (mark[i] != 0)
				continue;
			temp[N - k] = Arr[i];
			mark[i] = 1;
			BackTracking(Arr, temp, mark, N, k - 1);
			mark[i] = 0;			
		}
	}
	return;
}

int main(void) {
	int N, i, *Arr, *temp, *mark; // 크기가 N인 배열 Arr, 여러 조합을 삽입할 배열 temp
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	mark = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
		mark[i] = 0;
	}
	for (i = 0; i < N; i++) { // Backtracking으로 모든 경우의 수 검색
		temp[0] = Arr[i];
		mark[i] = 1;
		BackTracking(Arr, temp, mark, N, N - 1);
		mark[i] = 0;		
	}
	printf("%d", max);
	return 0;
}