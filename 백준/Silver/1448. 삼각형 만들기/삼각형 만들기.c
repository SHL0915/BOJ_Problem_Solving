#include <stdio.h>
#include <stdlib.h>

void MergeSort(int* Arr, int* temp, int left, int right_end);

void Merge(int* Arr, int* temp, int left, int right, int right_end);

int main(void) {
	int N, * Arr, * temp, i; // 크기가 N인 배열 Arr
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
	MergeSort(Arr, temp, 0, N - 1); // 오름차순으로 정렬
	for (i = N - 1; i >= 2; i--) { // 가장 긴 변을 선택하고 삼각형의 조건에 부합하는지 확인
		if (Arr[i] < Arr[i - 1] + Arr[i - 2]) { 
			printf("%d", Arr[i] + Arr[i - 1] + Arr[i - 2]);
			break;
		}		
	}
	if (i == 1) // 삼각형을 만들 수 없는 경우
		printf("-1");
	return 0;
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

void Merge(int* Arr, int* temp, int left, int right, int right_end) {
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
	return;
}