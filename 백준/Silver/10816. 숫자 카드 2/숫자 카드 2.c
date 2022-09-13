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
	for (i = left; i <= right_end;i++) {
		A[i] = temp[i];
	}
	return;
}

void MergeSort(int A[], int temp[], int left, int right_end) {
	int mid;

	if (left < right_end) {
		mid = (left + right_end) / 2;
		MergeSort(A, temp, left, mid);
		MergeSort(A, temp, mid + 1, right_end);
		Merge(A, temp, left, mid + 1, right_end);
	}

	return;
}

int SearchLower(int A[], int left, int right_end, int data) {
	int mid;
	mid = (left + right_end) / 2;

	if (left < right_end) {
		if (A[mid] < data) {
			SearchLower(A, mid+1, right_end, data);
		}
		else {
			SearchLower(A, left, mid, data);
		}
	}
	else
		return mid;	
}

int SearchUpper(int A[], int left, int right_end, int data) {
	int mid;
	mid = (left + right_end) / 2;

	if (left < right_end) {
		if (A[mid] <= data) {
			SearchUpper(A, mid + 1, right_end, data);
		}
		else {
			SearchUpper(A, left, mid, data);
		}
	}
	else
		return mid;
}


int main(void) {
	int N, M;
	int* Arr, *temp;
	int i;
	int num, result;
	int a, b;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	MergeSort(Arr, temp, 0, N - 1);

	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &num);
		a = SearchLower(Arr, 0, N - 1, num);
		b = SearchUpper(Arr, 0, N - 1, num);
		result = b - a;
		if (num == Arr[N - 1])
			result += 1;
		printf("%d ", result);
	}
	return 0;
}