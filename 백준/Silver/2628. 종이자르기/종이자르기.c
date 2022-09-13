#include <stdio.h>
#include <stdlib.h>

void MergeSort(int* Arr, int* temp, int left, int right_end);

void Merge(int* Arr, int* temp, int left, int right, int right_end);

int main(void) {
	int N, M, * Vertical, * Horizontal, * temp; // 크기가 N * M인 종이, 세로선을 저장하는 배열 Vertical, 가로선을 저장하는 배열 Horizontal
	int i, a = 2, b = 2, n, k, hor_max = -1, ver_max = -1;
	scanf("%d %d", &N, &M);
	scanf("%d", &n);
	Vertical = (int*)malloc(sizeof(int) * (n + 2)); // 최대 n+2의 선 저장
	Horizontal = (int*)malloc(sizeof(int) * (n + 2));
	temp = (int*)malloc(sizeof(int) * (n + 2));
	Vertical[0] = 0;
	Vertical[1] = N;
	Horizontal[0] = 0;
	Horizontal[1] = M;
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			scanf("%d", &Horizontal[a]);
			a++;
		}
		else {
			scanf("%d", &Vertical[b]);
			b++;
		}
	}
	MergeSort(Horizontal, temp, 0, a - 1);
	MergeSort(Vertical, temp, 0, b - 1);
	for (i = 1; i < a; i++) { // 종이의 가로에서 가장 긴 부분을 찾음
		if (Horizontal[i] - Horizontal[i - 1] >= hor_max)
			hor_max = Horizontal[i] - Horizontal[i - 1];
	}
	for (i = 1; i < b; i++) { // 종이의 세로에서 가장 긴 부분을 찾음
		if (Vertical[i] - Vertical[i - 1] >= ver_max)
			ver_max = Vertical[i] - Vertical[i - 1];
	}
	printf("%d", hor_max * ver_max); // 둘을 곱한 값이 가장 큰 종이 조각의 넓이
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