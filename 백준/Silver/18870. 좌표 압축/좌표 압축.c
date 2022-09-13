#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int** A, int** temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	pos = left;
	j = right;
	while ((i <= right - 1) && (j <= right_end)) {
		if (A[i][0] <= A[j][0]) {
			temp[pos][0] = A[i][0];
			temp[pos][1] = A[i][1];
			i++;
			pos++;
		}
		else {
			temp[pos][0] = A[j][0];
			temp[pos][1] = A[j][1];
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		temp[pos][0] = A[i][0];
		temp[pos][1] = A[i][1];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos][0] = A[j][0];
		temp[pos][1] = A[j][1];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		A[i][0] = temp[i][0];
		A[i][1] = temp[i][1];
	}
}

void MergeSort(int** A, int** temp, int left, int right_end) {
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
	int i, j;
	int** Arr, **temp;

	scanf("%d", &N);

	Arr = (int**)malloc(sizeof(int*) * N);
	temp = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * 2);
		temp[i] = (int*)malloc(sizeof(int) * 2);
	}

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i][0]);
		Arr[i][1] = i;
	}

	MergeSort(Arr, temp, 0, N - 1);

	j = 0;

	for (i = 0; i < N - 1; i++) {		
		if ((Arr[i][0]) != (Arr[i + 1][0])) {
			Arr[i][0] = j;
			j++;
		}
		else
			Arr[i][0] = j;
	}
	Arr[N - 1][0] = j;

	for (i = 0; i < N; i++) {
		temp[Arr[i][1]][0] = Arr[i][0];
	}
	
	for (i = 0; i < N; i++) {
		printf("%d ", temp[i][0]);
	}
	return 0;

}