#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void BackTracking(int Arr[], int mark[], int N, int k);

int main(void) {
	int N, * Arr, * mark, i; // 1부터 N까지 수로 이루어진 순열 Arr, 중복 여부를 기록하는 배열 mark
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	mark = (int*)malloc(sizeof(int) * (N+1));
	for (i = 1; i <= N; i++)
		mark[i] = 0;
	BackTracking(Arr, mark, N, 0); // backtracking을 사용하여 모든 순열을 사전순으로 출력
	return 0;
}

void BackTracking(int Arr[], int mark[], int N, int k) {
	int i;
	if (N == k) { // 모든 순열이 채워짐
		for (i = 0; i < N; i++) {
			printf("%d ", Arr[i]);
		}
		printf("\n");
		return;
	}
	else { // 순열에 수 하나를 추가
		for (i = 1; i <= N; i++) {
			if (mark[i] == 0) { // 중복된 숫자 사용 여부를 확인
				Arr[k] = i;
				mark[i] = 1;
				BackTracking(Arr, mark, N, k + 1);
				mark[i] = 0;
			}
		}
	}
}