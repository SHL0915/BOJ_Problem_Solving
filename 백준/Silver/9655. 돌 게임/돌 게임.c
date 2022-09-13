#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int N;
	scanf("%d", &N);

	if (N % 2 == 0) 
		printf("CY");
	else
		printf("SK");

	return 0;

}