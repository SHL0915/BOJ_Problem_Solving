#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int overlap[50000][8]; // 중복 검사 배열

int num = 0; // 중복 검사 배열의 원소의 수

void MergeSort(int Arr[], int temp[], int left, int right_end);

void Merge(int Arr[], int temp[], int left, int right, int right_end);

void BackTracking(int Arr[], int Sequence[], int mark[], int N, int k, int M);

int main(void) {
	int N, M, * Sequence, * Arr, * temp, * mark, i; // 크기가 N인 배열 Arr, 길이가 M인 수열 Sequence
	scanf("%d %d", &N, &M);
	Sequence = (int*)malloc(sizeof(int) * M);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	mark = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
		mark[i] = 0;
	}
	MergeSort(Arr, temp, 0, N - 1); // 배열을 오름차순으로 정렬
	BackTracking(Arr, Sequence, mark, N, 0, M); // BackTracking으로 가능한 모든 수열 출력
	return 0;
}

void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	return;
}

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] <= Arr[j]) {
			temp[pos] = Arr[i];
			i++;
			pos++;
		}
		else {
			temp[pos] = Arr[j];
			j++;
			pos++;
		}
	}
	while (i < right) {
		temp[pos] = Arr[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = Arr[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++)
		Arr[i] = temp[i];
	return;
}

void BackTracking(int Arr[], int Sequence[], int mark[], int N, int k, int M) {
	int i, j, flag = 0;
	if (k == M) { // 모든 수열이 채워진 상태, 수열 출력
		for (i = 0; i < num; i++) { // 중복 수열을 출력하지 않기 위해서, 중복 여부 검사
			for (j = 0; j < M; j++) { 
				if (Sequence[j] != overlap[i][j])
					break;
			}
			if (j == M) { // 중복된 수열
				flag = 1;
				break;
			}
		}
		if (flag == 0) { // 중복이 아니라면, 검사 배열에 수열을 추가하고 수열 출력
			for (i = 0; i < M; i++) {
				overlap[num][i] = Sequence[i];
				printf("%d ", Sequence[i]);
			}
			num++;			
			printf("\n");
		}		
		return;
	}
	else { // 수열에 수 하나를 채우고 BackTracking 수행
		for (i = 0; i < N; i++) { // Arr 속의 원소를 한 번 씩만 사용하여 수열을 구성하기 위해 mark에 사용 여부를 기록
			if (mark[i] == 0) {
				Sequence[k] = Arr[i];
				mark[i] = 1;
				BackTracking(Arr, Sequence, mark, N, k + 1, M);
				mark[i] = 0;
			}
		}
	}
}