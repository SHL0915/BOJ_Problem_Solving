#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void star(int x, int y, int N) {
	if (N == 3) { // base case
		if (y == 0) {
			if (x == 2) printf("*");
			else printf(" ");
		}
		else if (y == 1) {
			if (x == 1 || x == 3) printf("*");
			else printf(" ");
		}
		else printf("*");
			
		return;
	}
	else {
		if (y < N / 2) { // 위 층을 다룸
			if(x < N / 2 || x > N + N / 2 - 2)
				printf(" ");
			else
				star(x - N / 2, y, N / 2);
		}
		else { // 아래 층을 다룸
			if (x < N - 1)
				star(x, y - N / 2, N / 2);
			else if (x > N - 1)
				star(x - N, y - N / 2, N / 2);
			else
				printf(" ");
		}
	}
}

int main(void) {
	int N, i, j; // 높이가 N 인 삼각형
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < 2 * N - 1; j++) { // 너비가 2 * N -1 인 삼각형
			star(j, i, N); // 각각 (i, j) 좌표에 대해서 별찍기 판별
		}
		printf("\n");
	}
	return 0;
}