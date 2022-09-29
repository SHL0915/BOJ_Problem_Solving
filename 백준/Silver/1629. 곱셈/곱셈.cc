#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long mul(int A, int B, int C) {
	if (B == 0) {
		return 1;
	}
	else if (B == 1) {
		return A % C;
	}
	else if (B % 2 == 0) {
		return ((mul(A, B / 2, C) % C) * (mul(A, B / 2, C) % C)) % C;
	}
	else {
		return ((((mul(A, (B - 1) / 2, C) % C) * (mul(A, (B - 1) / 2, C) % C)) % C) * A) % C;
	}
}

int main(void) {
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);
	printf("%lld", mul(A, B, C));
	return 0;
}