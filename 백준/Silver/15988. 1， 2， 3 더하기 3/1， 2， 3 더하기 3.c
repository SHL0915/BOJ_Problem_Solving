#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long val[1000001] = { 0 }; // memoization에 사용할 배열 val

void DP(int n);

int main(void) {
	int T, n, i; // 테스트 케이스 T, 정수 n
	scanf("%d", &T);
	val[1] = 1; // 1
	val[2] = 2; // 1+1, 2
	val[3] = 4; // 1+1+1, 1+2, 2+1, 3
	DP(1000000);
	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%lld\n", val[n] % 1000000009);
	}
}

void DP(int n) {
	if (n == 0)
		return;
	else if (val[n] != 0)
		return;
	else { // 마지막 수가 1, 2, 3인 경우를 더해준다
		DP(n - 1);
		DP(n - 2);
		DP(n - 3);
		val[n] = ((val[n - 1] % 1000000009 + val[n - 2] % 1000000009) % 1000000009 + val[n - 3] % 1000000009) % 1000000009;
		return;
	}
}