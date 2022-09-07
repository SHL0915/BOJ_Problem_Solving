#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int max = 1;

void findMax(char** Board, int N) {
	int i, j, k, count;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {			
			if (j < N - max + 1) {
				if (Board[i][j + max - 1] == Board[i][j]) { // 적어도 j+max-1의 index가 시작점과 같을 때만 검색
					count = 0;
					for (k = j; k < N; k++) {
						if (Board[i][j] == Board[i][k]) {
							count++;
						}
						else
							break;
					}
					if (max <= count)
						max = count;
				}
			}
			if (i < N - max + 1) { // 적어도 i+max-1의 index가 시작점과 같을 때만 검색
				if (Board[i][j] == Board[i + max - 1][j]) {
					count = 0;
					for (k = i; k < N; k++) {
						if (Board[i][j] == Board[k][j]) {
							count++;
						}
						else
							break;
					}
					if (max <= count)
						max = count;
				}
			}
		}
	}
}

int main(void) {
	int N, i, j; // 크기가 N*N인 배열 Board
	char** Board, temp;
	scanf("%d", &N);
	Board = (char**)malloc(sizeof(char*) * N);
	for (i = 0; i < N; i++) {
		Board[i] = (char*)malloc(sizeof(char) * (N + 1));
		scanf("%s", Board[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j < N - 1) { // (j,i)의 글자와 (j+1,i)의 글자를 바꾼 뒤, 최대값을 구한다
				temp = Board[i][j];
				Board[i][j] = Board[i][j + 1];
				Board[i][j + 1] = temp;
				findMax(Board, N); // 현재 보드에서 최대값 갱신 여부 판별
				Board[i][j+1] = Board[i][j];
				Board[i][j] = temp;
			}
			if (i < N - 1) { // (j,i)의 글자와 (j,i+1)의 글자를 바꾼 뒤, 최대값을 구한다
				temp = Board[i][j];
				Board[i][j] = Board[i + 1][j];
				Board[i + 1][j] = temp;
				findMax(Board, N); // 현재 보드에서 최대값 갱신 여부 판별				
				Board[i + 1][j] = Board[i][j];
				Board[i][j] = temp;
			}
		}
	}
	printf("%d", max);
	return 0;
}