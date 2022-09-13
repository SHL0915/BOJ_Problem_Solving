#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, i, j, temp;
	int* Arr;
	int* val;

	scanf("%d", &N);
	Arr = (int*)malloc(sizeof(int) * (N+1));
	val = (int*)malloc(sizeof(int) * (N+1));

	for (i = 1; i <= N; i++) {
		val[i] = 0;
		scanf("%d", &Arr[i]);
	}
	val[0] = 0;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			temp = 0;
			while (j - temp - i >= 0) {
				if (Arr[i] + val[j - temp - i] >= val[j]) {
					val[j] = Arr[i] + val[j - temp - i];
					temp += i;
				}
				else
					break;
			}
		}
	}

	printf("%d", val[N]);

	return 0;

}