#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long X, N, i;
	long long a, b;
	long long sum = 0;

	scanf("%lld %lld", &X, &N);

	for (i = 0; i < N; i++) {
		scanf("%lld %lld", &a, &b);
		sum += a * b;
	}

	if (X == sum)
		printf("Yes");
	else
		printf("No");

	return 0;
}