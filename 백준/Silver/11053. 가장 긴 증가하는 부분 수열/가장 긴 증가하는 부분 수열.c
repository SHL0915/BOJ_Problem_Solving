#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[1000] = { 0 };

void dp(int Arr[], int val[], int pos, int N) {
	int i, temp;
	if (val[pos] == 0) {
		temp = 0;
		for (i = pos; i < N; i++) {
			if (Arr[i] > Arr[pos]) {
				dp(Arr, val, i, N);
				if (val[i] >= temp)
					temp = val[i];
			}
		}
		val[pos] = temp + 1;
		return;
	}
	else
		return;
}

int main(void) {
	int N;
	int i;
	int max = 0;

	int* Arr;

	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}


	val[N - 1] = 1;
	for (i = N-1; i >= 0; i--) {
		dp(Arr, val, i, N);
	}


	for (i = 0; i < N; i++) {
		if (val[i] >= max)
			max = val[i];
	}

	printf("%d", max);

}