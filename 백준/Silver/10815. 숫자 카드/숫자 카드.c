#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i <= right - 1) && (j <= right_end)) {
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
	while (i <= right - 1) {
		temp[pos] = Arr[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = Arr[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		Arr[i] = temp[i];
	}
	return;	
}

void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	else
		return;
}

int Search(int Arr[], int left, int right_end, int data) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		if (Arr[mid] == data)
			return 1;
		else if (Arr[mid] > data)
			Search(Arr, left, mid, data);
		else
			Search(Arr, mid + 1, right_end, data);
	}
	else {
		if (Arr[mid] == data)
			return 1;
		else
			return 0;
	}
		
}

int main(void) {
	int N, M;
	int i;
	int* Arr, *temp;
	int data;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	MergeSort(Arr, temp, 0, N - 1);

	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &data);
		printf("%d ", Search(Arr, 0, N-1, data));
	}

	return 0;
}