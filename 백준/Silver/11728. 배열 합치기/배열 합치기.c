#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] < Arr[j]) {
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

void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int main(void) {
	int N, M, i;
	int* A, * B, * C, *temp;
	scanf("%d %d", &N, &M);
	A = (int*)malloc(sizeof(int) * N);
	B = (int*)malloc(sizeof(int) * M);
	C = (int*)malloc(sizeof(int) * (N + M));
	temp = (int*)malloc(sizeof(int) * (N + M));
	for (i = 0; i < N; i++) 
		scanf("%d", &A[i]);	
	for (i = 0; i < M; i++)
		scanf("%d", &B[i]);
	for (i = 0; i < N; i++) 
		C[i] = A[i];
	for (i = N; i < N + M; i++)
		C[i] = B[i - N];	
	Merge(C, temp, 0, N, N+M- 1);
	for (i = 0; i < N + M; i++)
		printf("%d ", C[i]);
	return 0;
}