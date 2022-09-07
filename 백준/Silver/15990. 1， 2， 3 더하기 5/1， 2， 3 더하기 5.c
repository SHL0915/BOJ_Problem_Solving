#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long val1[100001]; // Memoization에 사용할 배열, 합을 나타내는 수의 마지막이 1인 경우
long long val2[100001]; // Memoization에 사용할 배열, 합을 나타내는 수의 마지막이 2인 경우
long long val3[100001]; // Memoization에 사용할 배열, 합을 나타내는 수의 마지막이 3인 경우
long long val[100001]; // Memoization에 사용할 배열 val

int main(void) {
	int T, n, i, j; // 테스트 케이스의 개수 T, 정수 n;
	scanf("%d", &T);
	for (j = 0; j < 100001; j++) {
		val1[j] = 0;
		val2[j] = 0;
		val3[j] = 0;
	}
	val1[1] = 1; // 1
	val1[2] = 0;
	val1[3] = 1; // 2+1
	val2[1] = 0;
	val2[2] = 1; // 2
	val2[3] = 1; // 1+2
	val3[1] = 0;
	val3[2] = 0;
	val3[3] = 1; // 3
	val[1] = val1[1] + val2[1] + val3[1];
	val[2] = val1[2] + val2[2] + val3[2];
	val[3] = val1[3] + val2[3] + val3[3];
	for (j = 4; j <= 100000; j++) {
		val1[j] = (val2[j - 1] % 1000000009 + val3[j - 1] % 1000000009) % 1000000009; // 마지막 수가 1인 경우, 그 전 숫자는 2이거나 3이어야 한다.
		val2[j] = (val1[j - 2] % 1000000009 + val3[j - 2] % 1000000009) % 1000000009; // 마지막 수가 2인 경우, 그 전 숫자는 1이거나 3이어야 한다.
		val3[j] = (val1[j - 3] % 1000000009 + val2[j - 3] % 1000000009) % 1000000009; // 마지막 수가 3인 경우, 그 전 숫자는 1이거나 2이어야 한다.
		val[j] = ((val1[j] % 1000000009 + val2[j] % 1000000009) % 1000000009 + val3[j] % 1000000009) % 1000000009;
	}
	for (i = 0; i < T; i++) {		
		scanf("%d", &n);		
		printf("%lld\n", val[n] % 1000000009);
	}
}