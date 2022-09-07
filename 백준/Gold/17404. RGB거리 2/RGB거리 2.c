#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Red[1000] = { 0 }; // 마지막 집을 빨강으로 칠하는 최소 비용
int Green[1000] = { 0 }; // 마지막 집을 초록으로 칠하는 최소 비용
int Blue[1000] = { 0 }; // 마지막 집을 파랑으로 칠하는 최소 비용

void DPRed(int N, int color, int** Arr); // 집의 수 N과 마지막 집의 색을 전달
void DPGreen(int N, int color, int** Arr); // 집의 수 N과 마지막 집의 색을 전달
void DPBlue(int N, int color, int** Arr); // 집의 수 N과 마지막 집의 색을 전달

int main(void) {
	int N, ** Arr, i, min = -1; // 집의 수 N, 비용을 저장한 배열 Arr
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) { // Arr[i][0]: 빨강으로 칠하는 비용, Arr[i][1]: 초록으로 칠하는 비용, Arr[i][2]: 파랑으로 칠하는 비용
		Arr[i] = (int*)malloc(sizeof(int) * 3);
		scanf("%d %d %d", &Arr[i][0], &Arr[i][1], &Arr[i][2]);
	}
	Red[0] = Arr[0][0];
	Green[0] = Arr[0][1];
	Blue[0] = Arr[0][2];
	DPRed(N - 1, 0, Arr);
	min = Red[N - 1];
	for (i = 1; i < N; i++) {
		Red[i] = 0;
		Green[i] = 0;
		Blue[i] = 0;
	}
	DPGreen(N - 1, 1, Arr);
	if (Green[N - 1] <= min)
		min = Green[N - 1];
	for (i = 1; i < N; i++) {
		Red[i] = 0;
		Green[i] = 0;
		Blue[i] = 0;
	}
	DPBlue(N - 1, 2, Arr);
	if (min >= Blue[N - 1])
		min = Blue[N - 1];	
	printf("%d", min);
	return 0;
}

void DPRed(int N, int color, int** Arr) {
	if (N == 0)
		return;
	else if (N == 1) {
		if (color == 1) { // 원래 색이 초록일 때, 첫 번째 집은 파랑색으로 칠해져야 한다.
			Red[1] = Blue[0] + Arr[1][0];
		}
		else if (color == 2) { // 원래 색이 파랑일 때, 첫 번째 집은 초록색으로 칠해져야 한다.
			Red[1] = Green[0] + Arr[1][0];
		}
		else { // 원래 색이 빨강일 때, 파랑_초록 중 더 작은 값을 취한다.
			Red[1] = Blue[0] + Arr[1][0] < Green[0] + Arr[1][0] ? Blue[0] + Arr[1][0] : Green[0] + Arr[1][0];
		}
	}
	else if (Red[N] != 0)
		return;
	else {
		DPGreen(N - 1, color, Arr);
		DPBlue(N - 1, color, Arr);
		Red[N] = Green[N - 1] + Arr[N][0] < Blue[N - 1] + Arr[N][0] ? Green[N - 1] + Arr[N][0] : Blue[N - 1] + Arr[N][0];
		return;
	}
}

void DPGreen(int N, int color, int** Arr) {
	if (N == 0)
		return;
	else if (N == 1) {
		if (color == 0) { // 원래 색이 빨강일 때, 첫 번째 집은 파랑색으로 칠해져야 한다.
			Green[1] = Blue[0] + Arr[1][1];
		}
		else if (color == 2) { // 원래 색이 파랑일 때, 첫 번째 집은 빨강색으로 칠해져야 한다.
			Green[1] = Red[0] + Arr[1][1];
		}
		else { // 원래 색이 초록일 때, 빨강_파랑 중 더 작은 값을 취한다.
			Green[1] = Blue[0] + Arr[1][1] < Red[0] + Arr[1][1] ? Blue[0] + Arr[1][1] : Red[0] + Arr[1][1];
		}
	}
	else if (Green[N] != 0)
		return;
	else {
		DPRed(N - 1, color, Arr);
		DPBlue(N - 1, color, Arr);
		Green[N] = Red[N - 1] + Arr[N][1] < Blue[N - 1] + Arr[N][1] ? Red[N - 1] + Arr[N][1] : Blue[N - 1] + Arr[N][1];
		return;
	}
}

void DPBlue(int N, int color, int** Arr) {
	if (N == 0)
		return;
	else if (N == 1) {
		if (color == 0) { // 원래 색이 빨강일 때, 첫 번째 집은 초록색으로 칠해져야 한다.
			Blue[1] = Green[0] + Arr[1][2];
		}
		else if (color == 1) { // 원래 색이 초록일 때, 첫 번째 집은 빨강색으로 칠해져야 한다.
			Blue[1] = Red[0] + Arr[1][2];
		}
		else { // 원래 색이 초록일 때, 빨강_파랑 중 더 작은 값을 취한다.
			Blue[1] = Green[0] + Arr[1][2] < Red[0] + Arr[1][2] ? Green[0] + Arr[1][2] : Red[0] + Arr[1][2];
		}
	}
	else if (Blue[N] != 0)
		return;
	else {
		DPRed(N - 1, color, Arr);
		DPGreen(N - 1, color, Arr);
		Blue[N] = Red[N - 1] + Arr[N][2] < Green[N - 1] + Arr[N][2] ? Red[N - 1] + Arr[N][2] : Green[N - 1] + Arr[N][2];
		return;
	}
}