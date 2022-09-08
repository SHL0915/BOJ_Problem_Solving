#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void MergeSort(char* Arr, char* temp, int left, int right_end);

void Merge(char* Arr, char* temp, int left, int right, int right_end);

void BackTracking(char* Arr, char * Cipher, char* mark, int L, int C, int k, int vowel, int consonant, int start);

int main(void) {
	int L, C, i; // 암호의 길이 L, 사용된 문자의 종류 C
	char* Arr, *temp, * Cipher, c; // 문자의 종류를 저장한 배열 Arr, 암호를 저장할 배열 Cipher
	scanf("%d %d", &L, &C);
	Arr = (char*)malloc(sizeof(char) * C);
	Cipher = (char*)malloc(sizeof(char) * L);
	temp = (char*)malloc(sizeof(char) * C);
	c = getchar();
	for (i = 0; i < C-1; i++) {
		scanf("%c", &Arr[i]);
		c = getchar();
	}
	scanf("%c", &Arr[C - 1]);
	MergeSort(Arr, temp, 0, C - 1); // 문자를 사전순으로 정렬	
	for (i = 0; i < C; i++) // temp를 중복된 문자를 판별하는 marker로 사용
		temp[i] = 0;
	BackTracking(Arr, Cipher, temp, L, C, 0, 0, 0, 0); //
	return 0;
}

void MergeSort(char* Arr, char* temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	return;
}

void Merge(char* Arr, char* temp, int left, int right, int right_end) {
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

void BackTracking(char* Arr, char * Cipher, char* mark, int L, int C, int k, int vowel, int consonant, int start) {
	int i;
	if (k == L) { // 모든 암호가 채워짐		
		if ((vowel >= 1) && (consonant >= 2)) { // 모음이 1개, 자음이 2개 이상인 경우
			for (i = 0; i < L; i++) {
				printf("%c", Cipher[i]);
			}
			printf("\n");
		}
		return;
	}
	else { // 암호에 문자 하나를 추가
		for (i = start; i < C; i++) {
			if (mark[i] == 0) { // 중복되지 않은 문자를 추가
				Cipher[k] = Arr[i];
				mark[i] = 1;
				if ((Arr[i] == 'a') || (Arr[i] == 'e') || (Arr[i] == 'i') || (Arr[i] == 'o') || (Arr[i] == 'u')) { // Arr[i]가 모음인 경우
					BackTracking(Arr, Cipher, mark, L, C, k + 1, vowel + 1, consonant, i);
				}
				else { // Arr[i]가 자음인 경우
					BackTracking(Arr, Cipher, mark, L, C, k + 1, vowel, consonant + 1, i);
				}
				mark[i] = 0;
			}
		}
	}
}