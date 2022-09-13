#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(char** address, int key[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i <= right - 1) && (j <= right_end)) {
		if (strcmp(address[key[i]], address[key[j]]) <= 0) {
			temp[pos] = key[i];
			i++;
			pos++;
		}
		else {
			temp[pos] = key[j];
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		temp[pos] = key[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = key[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		key[i] = temp[i];
	}
}

void MergeSort(char ** address, int key[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(address, key, temp, left, mid);
		MergeSort(address, key, temp, mid + 1, right_end);
		Merge(address, key, temp, left, mid + 1, right_end);
	}
}

int FindPassword(char** address, int key[], int left, int right_end, char* Find) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		if (strcmp(address[key[mid]], Find) == 0)
			return key[mid];
		else if (strcmp(address[key[mid]], Find) > 0)
			return FindPassword(address, key, 0, mid - 1, Find);
		else
			return FindPassword(address, key, mid + 1, right_end, Find);
	}
	else
		return key[mid];
}

int main(void) {
	int N, M;
	int i, j;
	char** address;
	char** password;
	int* key, *temp;
	char Find[21];


	scanf("%d %d", &N, &M);
	address = (char**)malloc(sizeof(char*) * N);
	password = (char**)malloc(sizeof(char*) * N);
	key = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);
		
	for (i = 0; i < N; i++) {
		address[i] = (char*)malloc(sizeof(char) * 21);
		password[i] = (char*)malloc(sizeof(char) * 21);
		scanf("%s %s", address[i], password[i]);
		key[i] = i;
	}

	MergeSort(address, key, temp, 0, N - 1);

	for (i = 0; i < M; i++) {
		scanf("%s", Find);
		printf("%s\n", password[FindPassword(address, key, 0, N - 1, Find)]);
	}

	return 0;
}