#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int N;
	int i;
	int j;
	scanf("%d", &N);
		
	for (i = 1; i <= N - 1; i++) {
		if (i == 1) {
			for (j = 0; j < N - 1; j++)
				printf(" ");
			printf("*\n");
		}
		else {
			for (j = 0; j < N - i; j++) 
				printf(" ");
			printf("*");
			for (j = 0; j < 2 * (i - 1) - 1; j++)
				printf(" ");
			printf("*\n");
		}		
	}
	

	for (i = 0; i < 2*N-1; i++) {
		printf("*");
	}
	
	return 0;
}