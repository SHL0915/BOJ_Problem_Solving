#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int** Arr, int** temp, int left, int right_end);
void Merge(int** Arr, int** temp, int left, int right, int right_end);

int main(void) {
	int N, ** Arr, ** temp, i; // 선을 그은 횟수 N, 선에 대한 정보를 저장하는 배열 Arr
	int sum = 0, start, end; // 선의 총 길이 sum, 연속된 선의 시작점 start, 끝점 end
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	temp = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * 2);
		temp[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &Arr[i][0], &Arr[i][1]); // 시작점과 끝점을 입력
	}
	MergeSort(Arr, temp, 0, N - 1); // 시작점에 대해 오름차순으로 정렬
	start = Arr[0][0]; // 시작점 설정
	end = Arr[0][1]; // 끝점 설정
	for (i = 1; i < N; i++) {		
		if (Arr[i][0] > end) { // 선이 이어지지 않는 경우
			sum += end - start;
			start = Arr[i][0];
			end = Arr[i][1];
		}
		else  // 선이 이어진 경우
			end = end > Arr[i][1] ? end : Arr[i][1];
	}	
	sum += end - start;
	printf("%d", sum);
}

void MergeSort(int** Arr, int** temp, int left, int right_end) {
	if (left < right_end) {
		int mid = (left + right_end) / 2;
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	return;
}

void Merge(int** Arr, int** temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i][0] <= Arr[j][0]) {
			temp[pos][0] = Arr[i][0];
			temp[pos][1] = Arr[i][1];
			i++;
			pos++;
		}
		else {
			temp[pos][0] = Arr[j][0];
			temp[pos][1] = Arr[j][1];
			j++;
			pos++;
		}
	}
	while (i < right) {
		temp[pos][0] = Arr[i][0];
		temp[pos][1] = Arr[i][1];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos][0] = Arr[j][0];
		temp[pos][1] = Arr[j][1];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		Arr[i][0] = temp[i][0];
		Arr[i][1] = temp[i][1];
	}
	return;
}