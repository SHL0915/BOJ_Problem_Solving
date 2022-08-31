#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long count = 0; // swap의 횟수

void Merge(long long Arr[], long long temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] <= Arr[j]) {
			temp[pos] = Arr[i];
			i++;
			pos++;
		}
		else { // swap 발생 부분
			temp[pos] = Arr[j];
			j++;
			pos++;
			count += right - i ; // j가 추월한 left에 속해있는 index만큼 더해준다.
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
}

void MergeSort(long long Arr[], long long temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int main(void) {
	int N, i; 
	long long* Arr, * temp;// 원소의 개수가 N개인 배열 Arr, Sort를 위한 배열 temp
	scanf("%d", &N);
	Arr = (long long*)malloc(sizeof(long long) * N);
	temp = (long long*)malloc(sizeof(long long) * N);
	for (i = 0; i < N; i++)
		scanf("%lld", &Arr[i]);
	MergeSort(Arr, temp, 0, N - 1); // 병합 정렬 과정에서 count를 통해 swap 횟수 판별
	printf("%lld", count);
	return 0;
}