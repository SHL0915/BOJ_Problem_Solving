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
	else
		return;	
}


int main(void) {
	int T, n, i, j, k;
	char Wearing[21];
	int* num;
	int kind, pos;
	char** Arr, ** temp;
	char a;
	int result;
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		result = 1;
		kind = 1;
		scanf("%d", &n);
		Arr = (char**)malloc(sizeof(char*) * n);
		temp = (char**)malloc(sizeof(char*) * n);
		for (j = 0; j < n; j++) {
			Arr[j] = (char*)malloc(sizeof(char) * 21);
			temp[j] = (char*)malloc(sizeof(char) * 21);
		}
		for (j = 0; j < n; j++) {
			k = 0;
			while ((a = getchar()) != ' ');
			while ((a = getchar()) != '\n') {
				Wearing[k] = a;
				k++;
			}
			Wearing[k] = '\0';			
			strcpy(Arr[j], Wearing);
			
		}
		MergeSort(Arr, temp, 0, n - 1);

		for (j = 1; j < n; j++) {
			if (strcmp(Arr[j], Arr[j - 1]) != 0)
				kind += 1;
		}


		num = (int*)malloc(sizeof(int) * kind);
		k = 0;
		pos = 0;

		for (j = 1; j < n; j++) {
			if (strcmp(Arr[j], Arr[j - 1]) != 0) {
				num[k] = j - pos;
				pos = j;
				k++;
			}
		}

		num[kind -1] = n-pos;

		for (j = 0; j < kind; j++) {
			result = result * (num[j] + 1);
		}
		result--;
		printf("%d\n", result);
	}
	return 0;	
}
