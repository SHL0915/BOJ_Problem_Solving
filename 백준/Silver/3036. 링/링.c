#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Euclid(int A, int B) {
	if (A == B)
		return A;
	else {
		if (A < B)
			return Euclid(B - A, A);
		else
			return Euclid(A - B, B);
	}
}

int main(void) {
	int N;
	int i;
	int first;
	int data;
	scanf("%d", &N);

	scanf("%d", &first);
	for (i = 0; i < N-1; i++) {
		scanf("%d", &data);
		printf("%d/%d\n", first / Euclid(first, data), data / Euclid(first, data));
	}
	return 0;
}