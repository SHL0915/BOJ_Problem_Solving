#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int N;
	int i;
	int j;
	scanf("%d", &N);

	for (i = 1 ; i <= N-1; i++) {
		for (j = 0; j < N-i-1; j++) {
			printf(" ");
		}		
		for (j = 0; j < i; j++) {
			printf(" *");
		}
		printf("\n");
	}
	printf("*");
	for (j = 0; j < N-1; j++) {
		printf(" *");
	}
	
	return 0;
}