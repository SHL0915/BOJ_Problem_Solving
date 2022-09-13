#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void zip(char** Arr, int N, int x, int y) {
	int i, j;
	int sum = 0;	
	if (N == 1) {
		printf("%c", Arr[y][x]);
		return;
	}
	else {
		for (i = y; i < y+N; i++) {
			for (j = x; j < x+N; j++) {
				sum += Arr[i][j] - '0';
			}
		}		
		if (sum == 0) {
			printf("0");
			return;
		}
		else if (sum == N * N) {
			printf("1");
			return;
		}
		else {
			printf("(");
			zip(Arr, N / 2, x, y);
			zip(Arr, N / 2, x + N/2, y);
			zip(Arr, N / 2, x, y + N/2);
			zip(Arr, N / 2, x + N/2, y + N/2);
			printf(")");
		}
	}
}

int main(void) {
	int N;
	int i, j;
	char** Arr;

	scanf("%d", &N);
	Arr = (char**)malloc(sizeof(char*) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (char*)malloc(sizeof(char) * (N + 1));
		scanf("%s", Arr[i]);
	}	
	zip(Arr, N, 0, 0);
	return 0;
}