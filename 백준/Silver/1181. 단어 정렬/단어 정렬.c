#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(char** A, char** B, int left, int right, int right_end) {
	int i, j, temp_pos;
	i = left;
	temp_pos = left;
	j = right;

	while (i <= right - 1 && j <= right_end)
	{
		if (strlen(A[i])<strlen(A[j]))
		{
			strcpy(B[temp_pos], A[i]);
			i++;
			temp_pos++;
		}
		else if (strlen(A[i]) == strlen(A[j])){
			if (strcmp(A[i], A[j]) < 0) {
				strcpy(B[temp_pos], A[i]);
				i++;
				temp_pos++;
			}
			else {
				strcpy(B[temp_pos], A[j]);
				j++;
				temp_pos++;
			}
		}
		else {
			strcpy(B[temp_pos], A[j]);
			j++;
			temp_pos++;
		}
	}
	while (i <= right - 1) {
		strcpy(B[temp_pos], A[i]);
		i++;
		temp_pos++;
	}
	while (j <= right_end) {
		strcpy(B[temp_pos], A[j]);
		j++;
		temp_pos++;
	}
	for (i = left; i <= right_end; i++) {
		strcpy(A[i], B[i]);
	}

}

void MergeSort(char** A, char** B, int left, int right_end) {
	int mid;
	if (right_end > left) {
		mid = (right_end + left) / 2;
		MergeSort(A, B, left, mid);
		MergeSort(A, B, mid + 1, right_end);
		Merge(A, B, left, mid + 1, right_end);
	}
}


int main(void) {
	int N;
	int i;
	char** Arr;
	char** temp;
	int len;
	

	scanf("%d", &N);

	Arr = (char**)malloc(sizeof(char*) * N);
	temp = (char**)malloc(sizeof(char*) * N);
	

	for (i = 0; i < N; i++) {
		Arr[i] = (char*)malloc(sizeof(char) * 50);
		temp[i] = (char*)malloc(sizeof(char) * 50);
	}

	for (i = 0; i < N; i++) {
		scanf("%s", Arr[i]);
	}

	MergeSort(Arr, temp, 0, N - 1);

	for (i = 0; i < N-1; i++) {
		if(strcmp(Arr[i],Arr[i+1])!=0)
			printf("%s\n", Arr[i]);
	}
	printf("%s", Arr[N - 1]);

	return 0;
}