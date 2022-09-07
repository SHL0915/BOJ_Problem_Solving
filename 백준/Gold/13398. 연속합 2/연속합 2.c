#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val1[100000] = { 0 }; // memoization에 사용할 배열, 수를 제거하지 않은 경우
int val2[100000] = { 0 }; // memoization에 사용할 배열, 수를 제거한 경우

int main(void) {
	int n, * Arr, i, max = -1001; // 크기가 n인 배열 Arr
	scanf("%d", &n);
	Arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &Arr[i]);
		if (Arr[i] >= max)
			max = Arr[i];
	}
	for (i = n - 1; i >= 0; i--) { // 배열의 마지막 양수를 검색
		if (Arr[i] <= 0)
			continue;
		else {
			val1[i] = Arr[i];
			val2[i] = Arr[i];
			break;
		}
	}
	if (i == -1) { // 배열에 양수가 하나도 없는 경우
		printf("%d", max);
		return 0;
	}
	n = i;
	for (i = n - 1; i >= 0; i--) {
		if (Arr[i] >= 0) { // 양수인 경우 연속합에 추가한다
			val1[i] = Arr[i] + val1[i + 1];
			val2[i] = Arr[i] + val2[i + 1];
		}
		else { // 음수인 경우, 수를 제거할지 여부를 결정한다
			if (Arr[i] + val1[i + 1] < 0) // 누적합을 새로 시작한다
				val1[i] = 0;
			else
				val1[i] = Arr[i] + val1[i + 1];
			val2[i] = val1[i + 1] > Arr[i] + val2[i + 1] ? val1[i + 1] : Arr[i] + val2[i + 1]; // 수를 제거하는 경우와 수를 이미 제거한 경우를 비교		
		}
	}
	for (i = 0; i <= n; i++) {
		if (max <= val2[i])
			max = val2[i];
	}
	printf("%d", max);
	return 0;
}