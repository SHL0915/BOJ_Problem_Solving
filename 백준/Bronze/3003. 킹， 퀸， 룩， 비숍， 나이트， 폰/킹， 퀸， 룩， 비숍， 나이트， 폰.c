#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N;

	scanf("%d", &N);
	printf("%d ", 1 - N);
	scanf("%d", &N);
	printf("%d ", 1 - N);
	scanf("%d", &N);
	printf("%d ", 2 - N);
	scanf("%d", &N);
	printf("%d ", 2 - N);
	scanf("%d", &N);
	printf("%d ", 2 - N);
	scanf("%d", &N);
	printf("%d ", 8 - N);

	return 0;
}