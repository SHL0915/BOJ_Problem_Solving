#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, i, j, temp, max = 0;;
	int* Arr;
	int* val;

	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * N);
	val = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	val[N - 1] = Arr[N - 1];

	for (i = N - 2; i >= 0; i--) {
		temp = Arr[i];
		for (j = i+1; j < N; j++) {
			if (Arr[i] < Arr[j]) {
				if (temp <= val[j] + Arr[i])
					temp = val[j] + Arr[i];
			}			
		}		
		val[i] = temp;		
	}

	for (i = 0; i < N; i++) {
		if (max <= val[i])
			max = val[i];
	}
	printf("%d", max);
	return 0;
}