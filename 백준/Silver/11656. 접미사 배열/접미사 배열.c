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
		if (strcmp(Arr[i], Arr[j]) <= 0) {
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
}

void MergeSort(char** Arr, char** temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int main(void) {
	char S[1001];
	int i, j, len;
	char** Arr, ** temp;


	scanf("%s", S);
	len = strlen(S);
	Arr = (char**)malloc(sizeof(char*) * len);
	temp = (char**)malloc(sizeof(char*) * len);

	for (i = 0; i < len; i++) {
		Arr[i] = (char*)malloc(sizeof(char) * 1001);
		temp[i] = (char*)malloc(sizeof(char) * 1001);
		Arr[i][0] = '\0';
	}

	j = 0;

	for (i = len-1; i >= 0; i--) {
		strcat(Arr[j], S + i);
		j++;
	}

	MergeSort(Arr, temp, 0, len - 1);

	for (i = 0; i < len; i++) {
		printf("%s\n", Arr[i]);
	}
	return 0;
}