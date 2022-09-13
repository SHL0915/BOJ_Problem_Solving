#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int findSqr(int N) {
	int i;
	for (i = 1; i <= N; i++) {
		if (i * i > N)
			break;
	}
	return i;
}

int Arr[100001] = { 0 };

int main(void) {
	int N, i, j, sqr;

	scanf("%d", &N);

	sqr = findSqr(N);

	for (i = 1; i <= sqr; i++) {
		Arr[i * i] = 1;
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= sqr; j++) {
			if (i + j * j <= N) {
				if (Arr[i + j * j] == 0)
					Arr[i + j * j] = Arr[i] + 1;
				else {
					Arr[i + j * j] = Arr[i + j * j] < Arr[i] + 1 ? Arr[i + j * j] : Arr[i] + 1;
				}
			}
			else
				break;
		}
	}



	printf("%d",Arr[N]);


}