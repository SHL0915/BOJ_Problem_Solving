#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long sum = 0;

long long pow(long long N) {
	long long i;
	long long result = 1;
	for (i = 0; i < N; i++) {
		result *= 2;
	}
	return result;
}

void visit(long long N, long long r, long long c) {
	if (N == 1) {
		if ((r == 0) && (c == 0))
			return;
		else if ((r == 0) && (c == 1)) {
			sum += 1;
			return;
		}
		else if ((r == 1) && (c == 0)) {
			sum += 2;
			return;
		}
		else {
			sum += 3;
			return;
		}
	}
	else {
		if (r >= pow(N - 1)) {
			if (c >= pow(N - 1)) {
				sum += pow(N - 1) * pow(N-1) * 3;
				visit(N - 1, r - pow(N - 1), c - pow(N - 1));
			}
			else {
				sum += pow(N - 1) * pow(N - 1) * 2;
				visit(N - 1, r - pow(N - 1), c);
			}
		}
		else {
			if (c >= pow(N - 1)) {
				sum += pow(N - 1) * pow(N - 1);
				visit(N - 1, r, c - pow(N - 1));
			}
			else {				
				visit(N - 1, r, c);
			}
		}
	}
}

int main(void) {
	long long N, r, c;
	scanf("%lld %lld %lld", &N, &r, &c);

	visit(N, r, c);	
	printf("%lld", sum);
	return 0;
}