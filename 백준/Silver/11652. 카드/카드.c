#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(long long Arr[], long long temp[], int left, int right, int right_end) {
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
	int N, i, count, index, max = 0;
	long long num;
	long long* Arr;
	long long* temp;

	scanf("%d", &N);
	Arr = (long long*)malloc(sizeof(long long) * N);
	temp = (long long*)malloc(sizeof(long long) * N);

	for (i = 0; i < N; i++) {
		scanf("%lld", &Arr[i]);
	}

	MergeSort(Arr, temp, 0, N-1);

	num = Arr[0];
	count = 1;
	for (i = 1; i < N; i++) {
		if (Arr[i] != num) {
			if (count > max) {
				max = count;
				index = i - 1;
			}
			count = 1;
			num = Arr[i];
		}
		else {
			count++;
		}
	}
	if (count > max) {
		index = i-1;
	}

	printf("%lld", Arr[index]);

}
