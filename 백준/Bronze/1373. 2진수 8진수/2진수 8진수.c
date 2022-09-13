#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[1000001];
	int len, i , j;
	int result[1000001];

	scanf("%s", str);
	len = strlen(str);

	j = 0;
	for (i = len - 1; i >= 0; i -= 3) {
		if (i == 0) {
			result[j] = (str[i] - '0') ;
			j++;
		}
		else if (i == 1) {
			result[j] = ((str[i - 1] - '0') * 2 + (str[i] - '0'));
			j++;
		}
		else {
			result[j] = ((str[i - 2] - '0') * 4 + (str[i - 1] - '0') * 2 + (str[i] - '0'));
			j++;
		}
	}

	for (i = j-1; i >=0; i--) {
		printf("%d", result[i]);
	}

	return 0;
}