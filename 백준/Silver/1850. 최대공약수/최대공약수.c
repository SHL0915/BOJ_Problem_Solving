#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long Euclid(long long A, long long B) {
	if (A == B)
		return A;
	else if ((A == 0) || (B == 0)) {
		return (A == 0) ? B : A;
	}
	else if ((A == 1) || (B == 1))
		return 1;
	else if (A > B)
		return Euclid(A - ((A/B) * B), B);
	else
		return Euclid(B - ((B / A) * A), A);
}

int main(void) {
	long long i;
	long long A, B;

	scanf("%lld %lld", &A, &B);

	for (i = 0; i < Euclid(A, B); i++) {
		printf("1");
	}
}