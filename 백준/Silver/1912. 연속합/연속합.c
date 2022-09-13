#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int n, i;
	int* Arr;
	int max, temp;
	scanf("%d", &n);
	Arr = (int*)malloc(sizeof(int) * n);
	if (!Arr)
		return 1;

	for (i = 0; i < n; i++) {
		scanf("%d", &Arr[i]);
	}

	max = Arr[0];
	temp = Arr[0];
	
	for (i = 1; i < n; i++) {
		if (Arr[i] >= Arr[i] + temp)
			temp = Arr[i];
		else {
			temp += Arr[i];
		}

		if (temp >= max)
			max = temp;
	}

	printf("%d", max);

	return 0;
}