#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int Arr[5];
	int i, sum = 0;

	scanf("%d %d %d %d %d", &Arr[0], &Arr[1], &Arr[2], &Arr[3], &Arr[4]);

	for (i = 0; i < 5; i++) {
		if (Arr[i] <= 40)
			Arr[i] = 40;
		sum += Arr[i];
	}

	printf("%d", sum / 5);
	return 0;
}