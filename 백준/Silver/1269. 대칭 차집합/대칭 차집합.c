#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
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

	return;
}

void MergeSort(int A[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(A, temp, left, mid);
		MergeSort(A, temp, mid + 1, right_end);
		Merge(A, temp, left, mid + 1, right_end);
	}
	else
		return;
}

int Search(int A[], int left, int right_end,int data) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		if (A[mid] == data)
			return 1;
		else if (A[mid] < data)
			Search(A, mid + 1, right_end, data);
		else
			Search(A, left, mid, data);
	}
	else {
		if (A[mid] == data)
			return 1;
		else
			return 0;
	}
}

int main(void) {
	int N, M;
	int* A, *temp;
	int i, data;
	int total = 0;
	int count = 0;


	scanf("%d %d", &N, &M);

	A = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);

	total = N + M;

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	MergeSort(A, temp, 0, N - 1);

	for (i = 0; i < M; i++) {
		scanf("%d", &data);
		count += Search(A, 0, N - 1, data);
	}

	printf("%d", total - count - count);
	return 0;
}