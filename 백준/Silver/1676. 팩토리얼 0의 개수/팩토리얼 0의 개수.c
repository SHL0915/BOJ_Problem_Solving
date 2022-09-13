#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N;
	int i, j, temp;
	int num2 = 0, num5 = 0;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		if (i % 2 == 0) {
			temp = i;
			while (temp % 2 == 0) {
				num2 += 1;
				temp = temp / 2;
			}
		}
		if (i % 5 == 0) {
			temp = i;
			while (temp % 5 == 0) {
				num5 += 1;
				temp = temp / 5;
			}
		}
	}

	printf("%d", num2 <= num5 ? num2 : num5);

	return 0;
}