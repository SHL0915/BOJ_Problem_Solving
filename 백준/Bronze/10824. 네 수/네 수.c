#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * Sum(char A[], char B[]) {
	int lenA, lenB, i, temp;
	char *result = (char *)malloc(sizeof(char)*18);
	char zero[17];
	lenA = strlen(A);
	lenB = strlen(B);
	if (lenA > lenB) {
		for (i = 0; i < lenA - lenB; i++) {
			zero[i] = '0';
		}
		zero[i] = '\0';
		strcat(zero, B);
		temp = 0;
		result[lenA+1] = '\0';
		for (i = lenA - 1; i >= 0; i--) {
			temp += A[i] + zero[i] - '0' - '0';
			result[i + 1] = temp % 10 + '0';
			temp = temp / 10;
		}
		result[0] = temp + '0';
	}
	else {
		for (i = 0; i < lenB - lenA; i++) {
			zero[i] = '0';
		}
		zero[i] = '\0';
		strcat(zero, A);
		temp = 0;
		result[lenB+1] = '\0';
		for (i = lenB - 1; i >= 0; i--) {
			temp += B[i] + zero[i] - '0' - '0';
			result[i + 1] = temp % 10 + '0';
			temp = temp / 10;
		}
		result[0] = temp + '0';
	}
	
	return result;
}

int main(void) {
	int i;
	char A[15];
	char B[8];
	char C[15];
	char D[8];

	char* result;

	scanf("%s %s %s %s", A, B, C, D);

	strcat(A, B);
	strcat(C, D);

	result = Sum(A, C);

	if (result[0] == '0') {
		for (i = 1; result[i] != '\0'; i++) {
			printf("%c", result[i]);
		}
	}
	else
		printf("%s", result);

	return 0;
}