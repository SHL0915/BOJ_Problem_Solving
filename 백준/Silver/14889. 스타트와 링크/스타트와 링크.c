#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min = -1;

int calPower(int** Arr, int Team[], int N) {
	int i, j;
	int power = 0;
	for (i = 0; i < N; i++) {
		for (j = i+1; j < N; j++) {
			power = power + Arr[Team[i]][Team[j]] + Arr[Team[j]][Team[i]];
		}
	}
	return power;
}

void backTracking(int** Arr, int BT[], int TeamA[], int TeamB[], int N, int k, int start) {
	int i, j, l, powerA, powerB, result;
	if (k == 0) {
		j = 0;
		l = 0;

		for (i = 0; i < N; i++) {
			if (BT[i] == 0) {
				TeamB[j] = i;
				j++;
			}
			else {
				TeamA[l] = i;
				l++;
			}
		}
		
		powerA = calPower(Arr, TeamA, N / 2);
		powerB = calPower(Arr, TeamB, N / 2);

		result = powerA > powerB ? (powerA - powerB) : (powerB - powerA);
		if (min == -1) {
			min = result;
		}
		else if (min >= result)
			min = result;
		return;
	}
	else {
		if (start + k > N)
			return;
		for (i = start; i < N; i++) {
			if (BT[i] == 0) {
				BT[i] = 1;
				backTracking(Arr, BT, TeamA, TeamB, N, k - 1, i + 1);
				BT[i] = 0;
			}
		}
	}
}

int main(void) {
	int N, i, j;
	int** Arr;
	int* TeamA, * TeamB, * BT;

	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	TeamA = (int*)malloc(sizeof(int) * N / 2);
	TeamB = (int*)malloc(sizeof(int) * N / 2);
	BT = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
		BT[i] = 0;

	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++) {
			scanf("%d", &Arr[i][j]);
		}
	}

	backTracking(Arr, BT, TeamA, TeamB, N, N/2, 0);

	printf("%d", min);
}
