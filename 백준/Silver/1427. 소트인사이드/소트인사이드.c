#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int i, j;
	int counting[10] = { 0 };
	char Num[11];

	scanf("%s", Num);

	for (i = 0; Num[i] != '\0'; i++) {
		counting[Num[i] - '0'] += 1;
	}
	for (i = 9; i >=0 ; i--)
	{
		for (j = 0; j < counting[i]; j++) {
			printf("%d", i);
		}
	}

	return 0;
}