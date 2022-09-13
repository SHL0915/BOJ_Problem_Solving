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

int Search(int Arr[], int left, int right_end, int N, int C) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		if (Test(Arr, 0, N, C - 1, mid) == 1) {
			Search(Arr, mid + 1, right_end, N, C);
		}
		else {
			Search(Arr, left, mid, N, C);
		}
	}
	else {
		return mid;
	}
}

int Test(int Arr[], int start, int N, int C, int distance) {
	int i;
	int flag = 0;

	for (i = start; i < N; i++) {
		if ((Arr[i] - Arr[start]) >= distance) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		if (C != 1)
			return Test(Arr, i, N, C - 1, distance);
		else if (C == 1) {
			return 1;
		}
	}
	else
		return 0;
}

int main(void) {
	int N, C;
	int i;
	int* Arr;
	int* temp;
	int distance;
	int max, result;


	scanf("%d %d", &N, &C);

	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	MergeSort(Arr, temp, 0, N - 1);  

	distance = Arr[N - 1] - Arr[0];
	max = distance / (C - 1) + 1;

	result = Search(Arr, 1, max, N, C);

	printf("%d", result-1);

}