#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] < Arr[j]) {
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

void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	return;
}

int findSecondNum(int** Arr, int x, int y, int N) { // 왼쪽 위 좌표 (x,y)를 입력
	int result;
	int* Sort, * temp;
	if (N == 0)
		return;
	Sort = (int*)malloc(sizeof(int) * 4);
	temp = (int*)malloc(sizeof(int) * 4);	
	Sort[0] = Arr[y][x];
	Sort[1] = Arr[y][x + N];
	Sort[2] = Arr[y + N][x];
	Sort[3] = Arr[y + N][x + N];
	MergeSort(Sort, temp, 0, 3);
	result = Sort[2];
	free(Sort);
	free(temp);	
	return result;
}

void Pulling(int** Arr, int x, int y, int N) {
	if (N == 1)
		return;
	else { // 네 구역으로 분할한 뒤, 두 번째로 큰 수를 가장 왼쪽 위 좌표로 복사
		Pulling(Arr, x, y, N / 2);		
		Pulling(Arr, x + N / 2, y, N / 2);
		Pulling(Arr, x, y + N / 2, N / 2);		
		Pulling(Arr, x + N / 2, y + N / 2, N / 2);
		Arr[y][x] = findSecondNum(Arr, x, y, N / 2);		
	}
}

int main(void) {
	int N, i, j, ** Arr; // 행렬Arr의 크기 N * N	
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++)
			scanf("%d", &Arr[i][j]);
	}

	Pulling(Arr, 0, 0, N);	

	printf("%d", Arr[0][0]);
}