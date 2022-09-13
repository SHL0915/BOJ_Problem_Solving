#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int N;
	int Arr[10002] = { 0 };
	int i, j, input;
	int max = 0;

	scanf("%d", &N);


	for (i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input >= max)
			max = input;
		Arr[input] += 1;
	}	
	for (i = 1; i <= max; i++) {
		Arr[i] += Arr[i - 1];
	}
	for (i = 1; i <= max; i++) {
		if (Arr[i] != Arr[i - 1])
		{
			for (j = 0; j < Arr[i] - Arr[i - 1]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}