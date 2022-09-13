#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(char** Arr, char** temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i <= right - 1) && (j <= right_end)) {
		if (strcmp(Arr[i], Arr[j]) < 0) {
			strcpy(temp[pos], Arr[i]);
			i++;
			pos++;
		}
		else if (strcmp(Arr[i], Arr[j]) == 0) {
			strcpy(temp[pos], Arr[i]);
			i++;
			pos++;
		}
		else {
			strcpy(temp[pos], Arr[j]);
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		strcpy(temp[pos], Arr[i]);
		i++;
		pos++;
	}
	while (j <= right_end) {
		strcpy(temp[pos], Arr[j]);
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		strcpy(Arr[i], temp[i]);
	}
	return;
}

void MergeSort(char** Arr, char** temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	else
		return;
}

int Search(char** Arr, int left, int right_end, char* str) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		if (strcmp(str, Arr[mid]) == 0) {
			return 1;
		}
		else if (strcmp(str, Arr[mid]) > 0)
			Search(Arr, mid+1, right_end, str);
		else if (strcmp(str, Arr[mid]) < 0)
			Search(Arr, left, mid, str);
	}
	else {
		if (strcmp(Arr[mid], str) == 0) {
			return 1;
		}
		else
			return 0;
	}
}

int main(void) {
	int N, M;
	int i;
	char** Arr, ** temp;
	char str[501];
	int count = 0;

	scanf("%d %d", &N, &M);

	Arr = (char**)malloc(sizeof(char*) * N);
	temp = (char**)malloc(sizeof(char*) * N);

	for (i = 0; i < N; i++) {
		Arr[i] = (char*)malloc(sizeof(char) * 501);
		temp[i] = (char*)malloc(sizeof(char) * 501);
	}

	for (i = 0; i < N; i++) {
		scanf("%s", Arr[i]);
	}

	MergeSort(Arr, temp, 0, N-1);

	for (i = 0; i < M; i++) {
		scanf("%s", str);
		count += Search(temp, 0, N - 1, str);
	}

	printf("%d", count);
	return 0;
}