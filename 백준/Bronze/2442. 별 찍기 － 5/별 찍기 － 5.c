#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int N;
	int i;
	int j;
	scanf("%d", &N);

	for (i =1 ; i <= 2 * N -1 ; i++) {
		for (j = 0; j < ((2 * N - 1)-i)/2; j++) {
			printf(" ");
		}
		for (j = 0; j < i; j++) {
			printf("%c",'*');
		}		
		printf("\n");
		i++;
	}
	return 0;
}