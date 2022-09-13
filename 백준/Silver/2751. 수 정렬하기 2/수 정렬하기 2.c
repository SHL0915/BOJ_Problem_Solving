#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int* Arr, int* temp, int left, int right_end);

void Merge(int* Arr, int* temp, int left, int right, int right_end);

int main(void) {
	int N, *Arr, * temp, i; // 크기가 N인 배열 Arr
	scanf("%d", &N);	
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);	
	for (i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
	MergeSort(Arr, temp, 0, N - 1);	// 오름차순으로 정렬
	for (i = 0; i < N; i++)
		printf("%d\n", Arr[i]);
	return 0;
}

void MergeSort(int* Arr, int* temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	return;
}

void Merge(int* Arr, int* temp, int left, int right, int right_end) {
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