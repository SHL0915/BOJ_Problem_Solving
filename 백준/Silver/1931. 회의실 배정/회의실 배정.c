#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int** Arr, int** temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i < right) && (j <= right_end)) {
		if (Arr[i][1] <= Arr[j][1]) {
			if (Arr[i][1] == Arr[j][1]) {
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
			else {
				temp[pos][0] = Arr[i][0];
				temp[pos][1] = Arr[i][1];
				i++;
				pos++;
			}
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
	for (i = left; i <= right_end; i ++) {
		Arr[i][0] = temp[i][0];
		Arr[i][1] = temp[i][1];
	}
}

void MergeSort(int** Arr, int** temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int main(void) {
	int N, i, count = 1;
	int** Arr, ** temp;
	int* ptr;
	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	temp = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * 2);
		temp[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &Arr[i][0], &Arr[i][1]);
	}

	MergeSort(Arr, temp, 0, N - 1);

	ptr = Arr[0];
	for (i = 1; i < N; i++) {
		if (Arr[i][0] < ptr[1])
			continue;
		else {
			ptr = Arr[i];
			count++;
		}
	}
	printf("%d", count);
	return 0;
}