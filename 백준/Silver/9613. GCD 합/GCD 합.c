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
	long long t, n, i, j, k, sum;
	long long Arr[100];

	scanf("%lld", &t);

	

	for (i = 0; i < t; i++) {
		scanf("%lld", &n);
		sum = 0;
		for (j = 0; j < n; j++) 
			scanf("%lld", &Arr[j]);
		for (j = 0; j < n; j++) {
			for (k = j+1; k < n; k++) {
				sum += Euclid(Arr[j], Arr[k]);
			}
		}
		printf("%lld\n", sum);
	}


}