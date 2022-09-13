#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int Arr[26] = { 0 };
	char str[101];
	int i;
	int len;

	scanf("%s", str);
	len = strlen(str);

	for (i = 0; i < len; i++) {
		Arr[str[i] - 'a'] += 1;
	}

	for (i = 0; i < 26; i++) {
		printf("%d ", Arr[i]);
	}

	return 0;
}