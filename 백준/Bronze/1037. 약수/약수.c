#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	pos = left;
	j = right;
	while ((i <= right - 1) && (j <= right_end)) {
		if (A[i] <= A[j]) {
			temp[pos] = A[i];
			i++;
			pos++;
		}
		else {
			temp[pos] = A[j];
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		temp[pos] = A[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = A[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		A[i] = temp[i];
	}
}

void MergeSort(int A[], int temp[], int left, int right_end) {
	int mid;

	if (right_end > left) {
		mid = (left + right_end) / 2;
		MergeSort(A, temp, left, mid);
		MergeSort(A, temp, mid + 1, right_end);
		Merge(A, temp, left, mid + 1, right_end);
	}
}


int main(void) {
	int N;
	int i;
	int* Arr, *temp;

	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	MergeSort(Arr, temp, 0, N - 1);

	if (N == 1)
		printf("%d", Arr[0] * Arr[0]);
	else
		printf("%d", Arr[0] * Arr[N - 1]);



	return 0;
}