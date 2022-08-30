#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void star(int x, int y, int N) {
	if (N == 0) { // base case
		printf("*");
		return;
	}
	else {
		if (x / N == 1 && y / N == 1) // 가장 큰 정사각형의 가운데인 경우, 공백 출력
			printf(" ");
		else
			star(x % N, y % N, N / 3); // 가운데가 아닌 경우, 작은 정사각형에 대해 판별
	}
}

int main(void) {
	int N, i, j; // 한 변의 길이가 N인 정사각형
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			star(j, i, N/3); // 각각 (i,j) 좌표마다 별찍기 판별
		}
		printf("\n");
	}
	return 0;
}
