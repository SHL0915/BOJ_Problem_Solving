#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int min = -1;

void BackTracking(int* team, int** Arr, int N, int k);

int calcStat(int* team, int** Arr, int N, int teamNum);

int main(void) {
	int N, ** Arr, i, j, *team; // 능력치를 저장할 배열 Arr, 팀 정보를 저장하는 배열 team
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	team = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		team[i] = 0;
		for (j = 0; j < N; j++) {
			scanf("%d", &Arr[i][j]);
		}
	}
	// 1번이 속한 팀을 teamA라고 정의한다
	BackTracking(team, Arr, N, 1); // BackTracking으로 가능한 팀의 조합을 모두 검색
	printf("%d", min);
	return 0;
}

void BackTracking(int* team, int** Arr, int N, int k) {
	int i, statA, statB, diff;
	if (k == N) { // 팀이 결정된 경우
		statA = calcStat(team, Arr, N, 0); // A팀의 teamNum은 0
		statB = calcStat(team, Arr, N, 1); // B팀의 teamNum = 1
		diff = statA > statB ? statA - statB : statB - statA;
		if (min == -1)
			min = diff;
		else if (min >= diff)
			min = diff;
		return;
	}
	else { // 팀이 결정되지 않은 경우
		for (i = 0; i < 2; i++) {
			team[k] = i;
			BackTracking(team, Arr, N, k + 1);
		}
	}
}

int calcStat(int* team, int** Arr, int N, int teamNum) { // 팀이 결정된 상태에서 팀의 능력치를 계산
	int sum = 0, i, j;
	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			if (team[i] == teamNum && team[j] == teamNum) {
				sum += Arr[i][j] + Arr[j][i];
			}
		}
	}
	return sum;
}