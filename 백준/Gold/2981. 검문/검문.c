#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Euclid(int A, int B) {
	if (A * B == 0)
		return A >= B ? A : B;
	else if (A == B)
		return A;
	else if (A > B)
		return Euclid(B, A - B);
	else
		return Euclid(A, B - A);
}

int main(void) {
	int N, i, j, temp, max, flag = 1;
	int min = 1000000000;
	int* Arr;
	int* List;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
		if (min >= Arr[i])
			min = Arr[i];
	}

	for (i = 0; i < N; i++) {
		Arr[i] -= min;
	}

	temp = Arr[0];

	for (i = 1; i < N; i++) {
		max = Euclid(temp, Arr[i]);
		temp = max;
	}
	
	List = (int*)malloc(sizeof(int));

	for (i = 1; i * i < max; i++);
	if ((i * i) != max) {
		flag = 0;
		i--;
	}
	temp = i;
	j = 0;

	if (flag == 0) {
		for (i = 2; i <= temp; i++) {
			if (max % i == 0) {
				printf("%d ", i);
				List[j] = max / i;
				j++;
				List = (int*)realloc(List, sizeof(int) * (j + 1));
			}
		}
		for (i = j-1; i >= 0; i--) {
			printf("%d ", List[i]);
		}
		printf("%d ", max);
	}
	else {
		for (i = 2; i <= temp-1; i++) {
			if (max % i == 0) {
				printf("%d ", i);
				List[j] = max / i;
				j++;
				List = (int*)realloc(List, sizeof(int) * (j + 1));
			}
		}
		printf("%d ", temp);
		for (i = j - 1; i >= 0; i--) {
			printf("%d ", List[i]);
		}
		printf("%d ", max);
	}


	return 0;
}