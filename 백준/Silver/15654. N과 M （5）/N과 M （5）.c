#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int Arr[], int temp[], int left, int right_end);

void Merge(int Arr[], int temp[], int left, int right, int right_end);

void BackTracking(int Arr[], int Sequence[], int mark[], int k, int N, int M);

int main(void) {
	int N, M, * Sequence, * Arr, i, * temp, * mark; // 길이가 M인 수열 Sequence, 크기가 N인 배열 Arr
	scanf("%d %d", &N, &M);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	mark = (int*)malloc(sizeof(int) * N);
	Sequence = (int*)malloc(sizeof(int) * M);
	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
		mark[i] = 0;
	}
	MergeSort(Arr, temp, 0, N - 1); // 배열을 오름차순으로 정렬
	BackTracking(Arr, Sequence, mark, 0, N, M); // BackTracking으로 수열을 출력
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

void BackTracking(int Arr[], int Sequence[], int mark[], int k, int N, int M) {
	int i;
	if (k == M) { // M개의 수를 모두 뽑은 상태, 수열을 출력
		for (i = 0; i < M; i++) {
			printf("%d ", Sequence[i]);			
		}
		printf("\n");
		return;
	}
	else { // 수열에 수를 하나 입력
		for (i = 0; i < N; i++) {
			if (mark[i] == 0) { // 중복 여부 판별
				Sequence[k] = Arr[i];
				mark[i] = 1; // 중복 방지를 위해 mark[i]를 1로 바꾼다
				BackTracking(Arr, Sequence, mark, k + 1, N, M);
				mark[i] = 0;
			}			
		}
	}
}