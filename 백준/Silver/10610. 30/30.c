#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(int* Arr, int* temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] > Arr[j]) { // 내림차순 정렬
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

void MergeSort(int* Arr, int* temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	return;
}

int main(void) {
	char input[100001]; // 문자열로 입력을 받는다.
	int* Arr, *tempArr, len, i, flag = 0, index, temp; // Arr: 숫자 배열, len: 배열의 길이, flag: 0의 유무 판별
	scanf("%s", input);
	len = strlen(input);
	Arr = (int*)malloc(sizeof(int) * len);
	tempArr = (int*)malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
		Arr[i] = input[i] - '0';
	for (i = 0; i < len; i++) {
		if (Arr[i] == 0) { // 30의 배수는 0이 포함되어야만 한다.
			flag = 1;
			index = i;
			break;
		}
	}
	if (flag == 0) {
		printf("-1");
		return 0;
	}
	temp = Arr[len - 1]; // 마지막 자리를 0으로 고정
	Arr[len - 1] = 0;
	Arr[index] = temp;
	temp = 0; // temp를 누적합으로 사용
	for (i = 0; i < len - 1; i++) {
		temp += Arr[i];
	}
	if (temp % 3 != 0) { // 3의 배수는 누적합이 3의 배수이어야만 한다.
		printf("-1");
		return 0;
	}
	MergeSort(Arr, tempArr, 0, len - 2); // 최대값을 구하기 위해 정렬
	for (i = 0; i < len; i++)
		printf("%d", Arr[i]);
	return 0;
}