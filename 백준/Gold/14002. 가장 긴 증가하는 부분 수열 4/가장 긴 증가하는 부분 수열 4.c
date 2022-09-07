#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[1000][2]; // memoization에 사용할 배열 val, 최대값과 바로 다음 index를 저장

int main(void) {
	int N, * Arr, i, j, max, index; // 크기가 N인 수열 Arr
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
	for (i = 0; i < N; i++) {
		val[i][0] = 0; //  최대값 초기화
		val[i][1] = 1; // index 값 초기화
	}
	val[N - 1][0] = 1;
	val[N - 1][1] = N - 1;
	for (i = N - 1; i >= 0; i--) { // i번째 인덱스부터 시작하여 가장 긴 증가하는 부분 수열을 구한다
		max = -1;
		for (j = i; j < N; j++) { // i번째 인덱스부터 시작하여 Arr[i]보다 큰 Arr 값을 갖는 val의 최대값 + 1
			if (Arr[i] < Arr[j]) {
				if (max <= val[j][0]) {
					max = val[j][0]; // 최대값을 저장
					index = j; // 최대값의 index를 저장
				}
			}
		}
		if (max == -1) { // Arr[i]가 가장 큰 수인 경우
			val[i][0] = 1;
			val[i][1] = i; // 자기 자신을 저장
		}
		else {
			val[i][0] = max + 1;
			val[i][1] = index;
		}
	}
	max = 0;
	for (i = 0; i < N; i++) {
		if (max <= val[i][0]) {
			max = val[i][0];
			index = i;
		}
	}
	printf("%d\n", max);
	printf("%d ", Arr[index]);
	while (1) {
		if (index == val[index][1])
			break;
		printf("%d ", Arr[val[index][1]]);		
		index = val[index][1];		
	}	
	return 0;
}