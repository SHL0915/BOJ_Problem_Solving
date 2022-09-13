#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int A, B;
	int T, i;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d,%d", &A, &B);
		printf("%d\n", A + B);
	}
	
}