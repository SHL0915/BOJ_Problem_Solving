#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int N;
	int** Arr;
	int* val;
	int i, temp;

	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	val = (int*)malloc(sizeof(int) * (N + 1));

	for (i = 0; i < N; i++) {
		val[i] = 0;
		Arr[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &Arr[i][0], &Arr[i][1]);
	}
	val[N] = 0;

	for (i = N - 1; i >= 0; i--) {
		if (i + Arr[i][0] > N)
			val[i] = val[i+1];
		else {
			temp = Arr[i][1] + val[i + Arr[i][0]];
			if (temp >= val[i + 1])
				val[i] = temp;
			else
				val[i] = val[i + 1];
		}
	}

	printf("%d", val[0]);

	return 0;
}