#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int overlap[50000][8]; // 중복 검사 배열

int num = 0; // 중복 검사 배열의 원소의 수

void MergeSort(int Arr[], int temp[], int left, int right_end);

void Merge(int Arr[], int temp[], int left, int right, int right_end);

void BackTracking(int Arr[], int Sequence[], int N, int k, int M);

int main(void) {
	int N, M, * Sequence, * Arr, * temp, i; // 크기가 N인 배열 Arr, 길이가 M인 수열 Sequence
	scanf("%d %d", &N, &M);
	Sequence = (int*)malloc(sizeof(int) * M);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);	
	for (i = 0; i < N; i++) 
		scanf("%d", &Arr[i]);			
	MergeSort(Arr, temp, 0, N - 1); // 배열을 오름차순으로 정렬
	BackTracking(Arr, Sequence, N, 0, M); // BackTracking으로 가능한 모든 수열 출력
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

void BackTracking(int Arr[], int Sequence[], int N, int k, int M) {
	int i;
	if (k == M) { // 모든 수열이 채워진 상태, 수열 출력
		for (i = 0; i < M; i++) {
			printf("%d ", Sequence[i]);
		}
		printf("\n");
		return;
	}
	else { // 수열에 수 하나를 채우고 BackTracking 수행
		Sequence[k] = Arr[0];
		BackTracking(Arr, Sequence, N, k + 1, M);
		for (i = 1; i < N; i++) {
			if (Arr[i] != Arr[i - 1]) { // 중복되는 수열 방지
				Sequence[k] = Arr[i];
				BackTracking(Arr, Sequence, N, k + 1, M);
			}
		}
	}
}