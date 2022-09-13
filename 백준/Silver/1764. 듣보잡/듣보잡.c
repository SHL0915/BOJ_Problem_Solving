#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(char** A, char** B, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i <= right - 1) && (j <= right_end)) {
		if (strcmp(A[i], A[j]) <= 0) {
			strcpy(B[pos], A[i]);
			i++;
			pos++;
		}
		else {
			strcpy(B[pos], A[j]);
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		strcpy(B[pos], A[i]);
		i++;
		pos++;
	}
	while (j <= right_end) {
		strcpy(B[pos], A[j]);
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		strcpy(A[i], B[i]);
	}
	return;
}


void MergeSort(char** A, char** B, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(A, B, left, mid);
		MergeSort(A, B, mid + 1, right_end);
		Merge(A, B, left, mid + 1, right_end);
	}
	else
		return;
}

int Search(char** A, int left, int right_end, char* str) {
	int mid = (left + right_end) / 2;
	int a;
	if (left < right_end) {
		if (strcmp(A[mid], str) == 0)
			return mid;
		else if (strcmp(A[mid], str) < 0)
			a = Search(A, mid + 1, right_end, str);
		else
			a = Search(A, left, mid, str);
	}

	else {
		if (strcmp(A[mid], str) == 0) {
			return mid;
		}
		else
			return -1;
	}

}

int main(void) {
	int N, M;
	int count = 0;
	int i;
	char** A, ** B;
	char str[21];
	int index;

	scanf("%d %d", &N, &M);

	A = (char**)malloc(sizeof(char*) * N);
	B = (char**)malloc(sizeof(char*) * N);

	for (i = 0; i < N; i++) {
		A[i] = (char*)malloc(sizeof(char) * 21);
		B[i] = (char*)malloc(sizeof(char) * 21);
		scanf("%s", A[i]);
	}

	MergeSort(A, B, 0, N - 1);

	free(B);
	B = (char**)malloc(sizeof(char*) * M);

	for (i = 0; i < M; i++) {
		B[i] = (char*)malloc(sizeof(char) * 21);
	}

	for (i = 0; i < M; i++) {
		scanf("%s", str);
		index = Search(A, 0, N - 1, str);
		if (index == -1) {
			continue;
		}
		else {
			B[count] = A[index];
			count++;
		}
	}
	free(A);

	A = (char**)malloc(sizeof(char*) * M);

	for (i = 0; i < M; i++) {
		A[i] = (char*)malloc(sizeof(char) * 21);
	}

	MergeSort(B, A, 0, count-1);

	printf("%d\n", count);	
	for (i = 0; i < count; i++) {
		printf("%s\n", B[i]);
	}
	return 0;
}