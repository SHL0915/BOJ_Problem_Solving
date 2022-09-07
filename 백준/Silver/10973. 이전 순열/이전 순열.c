#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int Arr[], int temp[], int left, int right_end);

void Merge(int Arr[], int temp[], int left, int right, int right_end);

int main(void) {
	int N, * Arr, *temp, i, swap_point, index, swap, max = 0; // 1부터 N까지의 수로 이루어진 순열 Arr
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
	for (i = 0; i < N; i++) { // 가장 처음에 오는 순열인지 판별
		if (Arr[i] != i + 1)
			break;
	}
	if (i == N) { // 가장 처음에 오는 순열인 경우
		printf("-1");
		return 0;
	}
	else {
		for (i = N - 2; i >= 0; i--) { // 마지막에서부터 Arr[i] > Arr[i+1]인 swap_point를 검색
			if (Arr[i] > Arr[i + 1]) {
				swap_point = i;
				break;
			}
		}		
		for (i = swap_point + 1; i < N; i++) { // swap_point 이후 swap_point보다 작은 최대 값을 작아 swap을 진행
			if (Arr[i] < Arr[swap_point] && max == 0) {
				max = Arr[i];
				index = i;
			}
			else if (Arr[i] < Arr[swap_point] && Arr[i] >= max) {
				max = Arr[i];
				index = i;
			}
		}
		swap = Arr[swap_point];
		Arr[swap_point] = Arr[index];
		Arr[index] = swap;
		MergeSort(Arr, temp, swap_point + 1, N - 1); // swap_point 이후를 내림차순으로 정렬
		for (i = 0; i < N; i++)
			printf("%d ", Arr[i]);
		return 0;
	}
}

void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	return;
}

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] >= Arr[j]) {
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