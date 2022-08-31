#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
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
}

void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int main(void) {
	int N, i, input, pos_count, neg_count, zero_count, one_count; // input을 받아 각 조건의 배열에 삽입한다.
	int* posArr, * negArr, * temp; // posArr: 양수, negArr: 음수, temp: 정렬을 위한 임시 배열
	int sum = 0;
	scanf("%d", &N);
	posArr = (int*)malloc(sizeof(int) * N);
	negArr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	pos_count = 0;
	neg_count = 0;
	zero_count = 0;
	one_count = 0;
	for (i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input == 1) {
			one_count++;
		}
		else if (input > 0) {
			posArr[pos_count] = input;
			pos_count++;
		}
		else if (input < 0) {
			negArr[neg_count] = input;
			neg_count++;
		}
		else {
			zero_count++;
		}
	}
	sum += one_count; // 1은 그냥 더해준다.
	MergeSort(posArr, temp, 0, pos_count - 1);
	if (pos_count % 2 == 0) {
		for (i = pos_count - 1; i >= 0; i -= 2) {
			sum += posArr[i] * posArr[i - 1]; // 큰 수 두 수끼리 곱해준다.
		}
	}
	else {
		for (i = pos_count - 1; i >= 1; i -= 2) {
			sum += posArr[i] * posArr[i - 1]; // 큰 수 두 수끼리 곱해준다.
		}
		sum += posArr[0];
	}
	MergeSort(negArr, temp, 0, neg_count - 1);
	if (neg_count % 2 == 0) {
		for (i = 0; i < neg_count; i += 2) {
			sum += negArr[i] * negArr[i + 1]; // 작은 수 두 수끼리 곱해준다.
		}
	}
	else {
		for (i = 0; i < neg_count - 1; i += 2) {
			sum += negArr[i] * negArr[i + 1]; // 작은 수 두 수끼리 곱해준다.
		}
		if (zero_count > 0); // 0이 존재하는 경우, 음수 하나와 곱하여 0으로 만든다.
		else {
			sum += negArr[neg_count - 1];
		}
	}
	printf("%d", sum);
	return 0;
}

