#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T, N, i, j, count; // 테스트 케이스의 개수 T, 정수 N, 파티션의 개수 count
	int primeNum[1000001] = { 0 }; // 소수 여부를 저장할 배열 primeNum
	primeNum[0] = 1;
	primeNum[1] = 1;
	for (i = 2; i < 1000001; i++) { // primeNum[i] = 0 이면, i는 소수
		if (primeNum[i] == 0) {
			j = i * 2;
			while (j <= 1000000) {
				primeNum[j] = 1;
				j += i;
			}
		}
	}
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		count = 0;
		scanf("%d", &N);
		for (j = 2; j <= N / 2; j ++) { // N에 대해 파티션 여부를 검색
			if (primeNum[j] == 0) {
				if (primeNum[N - j] == 0)
					count += 1;
			}
		}
		printf("%d\n", count);
	}
	return 0;	
}