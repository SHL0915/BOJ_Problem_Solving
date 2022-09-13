#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;

	while ((i <= right - 1) && (j <= right_end)) {
		if ((A[i] % 1000) <= (A[j] % 1000)) {
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

int main(void) {
	int N;
	int i, input;
	int* age, * temp;
	char** name;

	scanf("%d", &N);
	
	age = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	name = (char**)malloc(sizeof(char*) * N);



	for (i = 0; i < N; i++) {
		name[i] = (char*)malloc(sizeof(char) * 101);
	}

	for (i = 0; i < N; i++) {
		scanf("%d %s", &input, name[i]);
		age[i] = input + i * 1000;
	}

	MergeSort(age, temp, 0, N - 1);

	for (i = 0; i < N; i++) {
		printf("%d %s\n", age[i] % 1000, name[age[i] / 1000]);
	}

	return 0;
}