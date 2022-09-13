#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long findVal(long long** Arr, int x_left, int x_right, int y_up, int y_down) { // 정해진 구역의 직사각형의 합을 구하는 함수
	int i, j;
	long long sum = 0;
	for (i = y_up; i < y_down; i++) {
		for (j = x_left; j < x_right; j++)
			sum += Arr[i][j];
	}
	return sum;
}

int main(void) {
	int N, M, i ,j; // N * M 크기의 직사각형 배열 Arr
	long long** Arr;
	long long max = 0, temp, rec1, rec2, rec3; // 최댓값 max, 세 개의 직사각형의 합 rec1, rec2, rec3
	char line[51];
	scanf("%d %d", &N, &M);
	Arr = (long long**)malloc(sizeof(long long*) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (long long*)malloc(sizeof(long long) * M);
		scanf("%s", line);
		for (j = 0; j < M; j++) {
			Arr[i][j] = line[j] - '0';

		}
	}
	for (i = 1; i < N; i++) { // 세로줄 i 와 가로줄 j가 결정될 때마다 큰 직사각형을 3개의 작은 직사각형으로 분할하는 4가지 방법을 떠올릴 수 있다.
		for (j = 1; j < M; j++) { 
			rec1 = findVal(Arr, 0, j, 0, i);
			rec2 = findVal(Arr, j, M, 0, i);
			rec3 = findVal(Arr, 0, M, i, N);
			temp = rec1 * rec2 * rec3;
			if (max <= temp) // 첫 번째 유형
				max = temp;
			rec1 = findVal(Arr, 0, j, i, N);
			rec2 = findVal(Arr, j, M, i, N);
			rec3 = findVal(Arr, 0, M, 0, i);
			temp = rec1 * rec2 * rec3;
			if (max <= temp) // 두 번째 유형
				max = temp;
			rec1 = findVal(Arr, 0, j, 0, i);
			rec2 = findVal(Arr, 0, j, i, N);
			rec3 = findVal(Arr, j, M, 0, N);
			temp = rec1 * rec2 * rec3;
			if (max <= temp) // 세 번째 유형
				max = temp;
			rec1 = findVal(Arr, 0, j, 0, N);
			rec2 = findVal(Arr, j, M, 0, i);
			rec3 = findVal(Arr, j, M, i, N);
			temp = rec1 * rec2 * rec3;
			if (max <= temp) // 네 번째 유형
				max = temp;			
		}
	}
	for (i = 1; i < M - 1; i++) { // 혹은 세로줄 2개나 가로줄 2개를 선택하는 유형도 존재한다.
		for (j = i + 1; j < M; j++) {
			rec1 = findVal(Arr, 0, i, 0, N);
			rec2 = findVal(Arr, i, j, 0, N);
			rec3 = findVal(Arr, j, M, 0, N);
			temp = rec1 * rec2 * rec3;
			if (max <= temp) // 다섯 번째 유형
				max = temp;			
		}
	}
	for (i = 1; i < N - 1; i++) { 
		for (j = i + 1; j < N; j++) {
			rec1 = findVal(Arr, 0, M, 0, i);
			rec2 = findVal(Arr, 0, M, i, j);
			rec3 = findVal(Arr, 0, M, j, N);
			temp = rec1 * rec2 * rec3;
			if (max <= temp) // 여섯 번째 유형
				max = temp;
		}
	}
	printf("%lld", max);
	return 0;
}