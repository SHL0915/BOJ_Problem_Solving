#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long cal(long long N, long long num) {
	long long i, sum = 0;

	for (i = 1; i <= N; i++) {
		if (i > num)
			break;
		if (num > i * N) {
			sum += N;
			continue;
		}
		else {
			if ((num % i) != 0)
				sum += (num / i);
			else
				sum += (num / i) - 1;
		}
	}

	return sum;
}

long long Search(long long left, long long right_end, long long k, long long N) {
	long long mid = (left + right_end) / 2;
	long long temp;
	if (left < right_end) {
		if (cal(N, mid) < k) 
			temp = Search(mid+1, right_end, k, N);
		
		else 
			temp = Search(left, mid, k, N);
		
	}
	else
		return mid;
}

int main(void) {
	long long N, k;

	scanf("%lld %lld", &N, &k);

	if (k == N * N) 
		printf("%lld", Search(1, N * N, k, N));
	else
		printf("%lld", Search(1, N * N, k, N)-1);
	return 0;
}