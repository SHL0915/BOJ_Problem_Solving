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

	if (left < right_end) {
		mid = (left + right_end) / 2;
		MergeSort(A, temp, left, mid);
		MergeSort(A, temp, mid + 1, right_end);
		Merge(A, temp, left, mid + 1, right_end);
	}
}

int Search(int A[], int left, int right_end, int data) {
	int mid = (left + right_end) / 2;

	if (left < right_end) {
		if (data == A[mid])
			return 1;
		else if (data > A[mid])
			Search(A, mid + 1, right_end, data);
		else
			Search(A, left, mid, data);
	}


	else {
		if (A[left] == data)
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
	
	if (!Arr || !temp) {
		return 1;
	}

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	MergeSort(Arr, temp, 0, N - 1);

	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &data);
		printf("%d\n", Search(Arr, 0, N - 1, data));
	}
	

	return 0;
}