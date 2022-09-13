#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long mul(long long A, long long B, long long C) {
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
	long long A, B, C;

	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", mul(A, B, C));
	return 0;
}