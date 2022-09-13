#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int i;
	int A, B;

	for (i = 0;; i++) {
		scanf("%d %d", &A, &B);
		if ((A == 0) && (B == 0))
			break;
		else if ((A <= B) && (B % A == 0))
			printf("factor\n");
		else if ((A >= B) && (A % B == 0))
			printf("multiple\n");
		else
			printf("neither\n");
	}
	return 0;
}