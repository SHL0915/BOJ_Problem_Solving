#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, K; // N: 여학생, M: 남학생, K: 인턴쉽 참여 인원
	scanf("%d %d %d", &N, &M, &K);

	if (2 * M < N) { // 여학생이 남는 상황
		if (K <= N - 2 * M) { // 인턴쉽 참여 인원보다 많이 남은 상황
			printf("%d", M);
		}
		else { // 인턴쉽 참여 인원보다 적게 남은 상황
			K -= N - 2 * M; // 잉여 인원을 제외
			N = 2 * M;
			if (K % 3 == 0) {
				printf("%d", M - K / 3);
			}
			else {
				printf("%d", M - K / 3 - 1);
			}
		}
	}
	else { // 남학생이 남는 상황
		if (N % 2 == 0) { // 짝수 명의 여학생
			if (K <= M - N / 2) { // 인턴쉽 참여 인원보다 많이 남은 상황
				printf("%d", N / 2);
			}
			else { // 인턴쉽 참여 인원보다 적게 남은 상황
				K -= M - N / 2;
				M = N / 2;
				if (K % 3 == 0) {
					printf("%d", M - K / 3);
				}
				else {
					printf("%d", M - K / 3 - 1);
				}
			}
		}
		else { // 홀수 명의 여학생
			K -= 1;
			M -= 1;
			if (K <= M - N / 2) { // 인턴쉽 참여 인원보다 많이 남은 상황
				printf("%d", N / 2);
			}
			else { // 인턴쉽 참여 인원보다 적게 남은 상황
				K -= M - N / 2;
				M = N / 2;
				if (K % 3 == 0) {
					printf("%d", M - K / 3);
				}
				else {
					printf("%d", M - K / 3 - 1);
				}
			}
		}
	}
	return 0;
}

