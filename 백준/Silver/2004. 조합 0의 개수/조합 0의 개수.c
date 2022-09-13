#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long count2(long long n) {
	long long i;
	long long count = 0;

	for (i = 2; i <= n; i*= 2) {
		count += n / i;
	}

	return count;
}

long long count5(long long n) {
	long long i;
	long long count = 0;

	for (i = 5; i <= n; i *= 5) {
		count += n / i;
	}

	return count;
}

int main(void) {
	long long n, m;
	long long num2, num5;

	scanf("%lld %lld", &n, &m);

	num2 = count2(n) - count2(m) - count2(n - m);
	num5 = count5(n) - count5(m) - count5(n - m);

	printf("%lld", num2 <= num5 ? num2 : num5);
	return 0;
}