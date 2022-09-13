#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int N;
	int i;
	int j;
	scanf("%d", &N);

	for (i =1 ; i <= N ; i++) {
		for (j = 0; j < i; j++) {
			printf("*");
		}
		for (j = 0; j < 2 * (N - i); j++) {
			printf(" ");
		}	
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = N-1; i >= 1; i--) {
		for (j = 0; j < i; j++) {
			printf("*");
		}
		for (j = 0; j < 2 * (N - i); j++) {
			printf(" ");
		}
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}