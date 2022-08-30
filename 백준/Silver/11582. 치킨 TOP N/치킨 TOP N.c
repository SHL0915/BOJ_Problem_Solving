#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while(i<right && j<=right_end){
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


int main(void) {
	int N, k, i, * Arr, * temp; // N: 치킨집의 개수, k: 정렬을 진행중인 회원, Arr: 맛의 수치 배열
	int mid, j;
	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) 
		scanf("%d", &Arr[i]);
	scanf("%d", &k);
	i = 2;
	while (i <= N / k) { // 실행 횟수: log(N/k)
		for (j = 0; j < N; j += i)
			Merge(Arr, temp, j, j + i / 2, j + i - 1); // 구간을 두 배씩 늘려가며 정렬
		i *= 2;
	}
	for (i = 0; i < N; i++)
		printf("%d ", Arr[i]);
	return 0;
}