#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	long long N, B, temp, result = 0;
	char str[31];
	int len, i;

	scanf("%s %lld", str, &B);
	len = strlen(str);

	temp = 1;
	for (i = 0; i < len -1; i++) {
		temp = temp * B;
	}

	for (i = 0; i < len; i++) {
		if ((str[i] >= '0') && (str[i] <= '9')) {
			result += temp * (str[i] - '0');
		}
		else {
			result += temp * (str[i] - 'A' + 10);
		}
		temp = temp / B;
	}

	printf("%lld", result);
	return 0;
}