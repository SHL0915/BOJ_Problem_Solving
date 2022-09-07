#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val1[100001] = { 0 }; // memoization에 사용할 배열, 왼쪽에 배치하는 경우
int val2[100001] = { 0 }; // memoization에 사용할 배열, 오른쪽에 배치하는 경우
int val3[100001] = { 0 }; // memoization에 사용할 배열, 배치하지 않는 경우

int main(void) {
	int N, i; // 우리의 크기 N
	scanf("%d", &N);
	val1[1] = 1; 
	val2[1] = 1;
	val3[1] = 1;	
	for (i = 2; i <= N; i++) {
		val1[i] = (val2[i - 1] % 9901 + val3[i - 1] % 9901) % 9901; // (i칸 왼쪽 배치) = (i-1 칸 오른쪽 배치) + (i-1칸 배치 x)
		val2[i] = (val1[i - 1] % 9901 + val3[i - 1] % 9901) % 9901; // (i칸 오른쪽 배치) = (i-1 칸 왼쪽 배치) + (i-1칸 배치 x)
		val3[i] = ((val1[i - 1] % 9901 + val2[i - 1] % 9901) % 9901 + val3[i - 1] % 9901) % 9901; // (i칸 배치 x) = (i-1칸의 모든 경우)
	}
	printf("%d", ((val1[N] % 9901 + val2[N] % 9901) % 9901 + val3[N] % 9901) % 9901);
	return 0;
}
