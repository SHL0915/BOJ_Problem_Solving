#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

void Merge(char** str, char** temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i <= right - 1) && (j <= right_end)) {
		if (strcmp(str[i], str[j]) == 0) {
			if ((str[i][0] == '\0') || (str[j][0] == '\0')) {
				strcpy(temp[pos], str[j]);
				j++;
				pos++;
			}
			else {
				str[j][0] = '\0';
				count++;
				strcpy(temp[pos], str[j]);
				j++;
				pos++;
			}
		}
		else if (strcmp(str[i], str[j]) < 0) {
			strcpy(temp[pos], str[i]);
			i++;
			pos++;
		}
		else {
			strcpy(temp[pos], str[j]);
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		strcpy(temp[pos], str[i]);
		i++;
		pos++;
	}
	while (j <= right_end) {
		strcpy(temp[pos], str[j]);
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		strcpy(str[i], temp[i]);
	}
}

void MergeSort(char** str, char** temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(str, temp, left, mid);
		MergeSort(str, temp, mid + 1, right_end);
		Merge(str, temp, left, mid + 1, right_end);
	}
	else
		return;
}

int main(void) {
	char S[1001];
	char*** str, *** temp;
	int len;
	int i, j, N;

	scanf("%s", S);
	len = strlen(S);
	N = (len * (len + 1)) / 2;

	str = (char***)malloc(sizeof(char*) * len);
	temp = (char***)malloc(sizeof(char*) * len);

	for (i = 0; i < len; i++) {
		str[i] = (char**)malloc(sizeof(char*) * (len - i));
		temp[i] = (char**)malloc(sizeof(char*) * (len - i));
		for (j = 0; j <= len - i; j++) {
			str[i][j] = (char*)malloc(sizeof(char) * (i + 2));
			temp[i][j] = (char*)malloc(sizeof(char) * (i + 2));
		}
	}

	for (i = 1; i <= len; i++) {
		for (j = 0; j <= len - i; j++) {
			strncpy(str[i - 1][j], S + j, i);
			str[i - 1][j][i] = '\0';
		}
	}

	for (i = 0; i < len; i++) {
		MergeSort(str[i], temp[i], 0, len - i - 1);
	}

	printf("%d", N - count);

	return 0;
}