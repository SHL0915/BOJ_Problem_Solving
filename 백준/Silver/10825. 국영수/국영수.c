#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MergeSort(int* key, int* temp, int left, int right_end, int* Korean, int* English, int* Math, char** Name);

void Merge(int* key, int* temp, int left, int right, int right_end, int* Korean, int* English, int* Math, char** Name);

int main(void) {
	int N, *key, * temp, *Korean, *English, *Math, i; // 키값을 저장하여 정렬을 진행
	char** Name;
	scanf("%d", &N);	
	key = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);	
	Korean = (int*)malloc(sizeof(int) * N);
	English = (int*)malloc(sizeof(int) * N);
	Math = (int*)malloc(sizeof(int) * N);
	Name = (char**)malloc(sizeof(char *) * N);
	for (i = 0; i < N; i++) {
		Name[i] = (char*)malloc(sizeof(char) * 11);
		scanf("%s", Name[i]);
		scanf("%d %d %d", &Korean[i], &English[i], &Math[i]);
		key[i] = i;
	}
	MergeSort(key, temp, 0, N - 1, Korean, English, Math, Name);	// 키값을 이용해 조건에 맞게 정렬	
	for (i = 0; i < N; i++) { 
		printf("%s\n", Name[key[i]]);
	}
	return 0;
}

void MergeSort(int* key, int* temp, int left, int right_end, int * Korean, int * English, int * Math, char ** Name) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(key, temp, left, mid, Korean, English, Math, Name);
		MergeSort(key, temp, mid + 1, right_end, Korean, English, Math, Name);
		Merge(key, temp, left, mid + 1, right_end, Korean, English, Math, Name);
	}
	return;
}

void Merge(int* key, int* temp, int left, int right, int right_end, int* Korean, int* English, int* Math, char** Name) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Korean[key[i]] == Korean[key[j]]) { // 국어 점수가 같은 경우
			if (English[key[i]] == English[key[j]]) { // 국어 점수와 영어 점수가 같은 경우
				if (Math[key[i]] == Math[key[j]]) { // 국어 점수와 영어 점수와 수학 점수가 같은 경우
					if (strcmp(Name[key[i]], Name[key[j]]) <= 0) { // 사전 순으로 정렬
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
				else if (Math[key[i]] > Math[key[j]]) { // 수학 점수가 감소하는 순서로 정렬
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
			else if (English[key[i]] < English[key[j]]) { // 영어 점수가 증가하는 순서로 정렬
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
		else if (Korean[key[i]] > Korean[key[j]]) { // 국어 점수가 감소하는 순서로 정렬
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
	while (i < right) {
		temp[pos] = key[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = key[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++)
		key[i] = temp[i];
	return;
}