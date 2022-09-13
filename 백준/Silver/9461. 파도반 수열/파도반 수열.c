#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Sum(char* a, char* b) {
	char ref[30];
	char* result = (char*)malloc(sizeof(char) * 31);
	char* ans = (char*)malloc(sizeof(char) * 31);
	int lenA, lenB;
	int i;
	int temp;
	int quotient = 0;

	lenA = strlen(a);
	lenB = strlen(b);

	for (i = 0; i < lenA - lenB; i++) {
		ref[i] = '0';
	}
	ref[i] = '\0';
	strcat(ref, b);

	for (i = lenA - 1; i >= 0; i--) {
		temp = a[i] + ref[i] + quotient - 96;
		quotient = temp / 10;
		result[i + 1] = temp % 10 + 48;
	}
	result[lenA + 1] = '\0';
	result[0] = quotient + 48;
	if (result[0] != '0')
		strcpy(ans, result);
	else
		strcpy(ans, result + 1);
	free(result);
	return ans;
}

char* dp(int N, char** Arr) {
	if (Arr[N][0] == -1) {
		Arr[N] = Sum(dp(N - 1, Arr), dp(N - 5, Arr));
		return Arr[N];
	}
	else
		return Arr[N];
}

int main(void) {
	int T, N;
	char** Arr;
	int i;
	Arr = (char**)malloc(sizeof(char*) * 101);
	for (i = 0; i < 101; i++) {
		Arr[i] = (char*)malloc(sizeof(char) * 30);
		Arr[i][0] = -1;
	}
	Arr[1][0] = '1';
	Arr[1][1] = '\0';
	Arr[2][0] = '1';
	Arr[2][1] = '\0';
	Arr[3][0] = '1';
	Arr[3][1] = '\0';
	Arr[4][0] = '2';
	Arr[4][1] = '\0';
	Arr[5][0] = '2';
	Arr[5][1] = '\0';

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%s\n", dp(N,Arr));
	}
	return 0;
}