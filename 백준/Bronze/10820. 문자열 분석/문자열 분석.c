#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int Arr[4] = { 0 };
	char c;
	int i;

	while (1) {
		c = getchar();
		if ((c >= 'A') && (c <= 'Z'))
			Arr[1]++;
		else if ((c >= 'a') && (c <= 'z'))
			Arr[0]++;
		else if (c == ' ')
			Arr[3]++;
		else if ((c >= '0') && (c <= '9'))
			Arr[2]++;
		else if (c == EOF)
			break;
		else if (c == '\n') {
			for (i = 0; i < 4; i++) {
				printf("%d ", Arr[i]);
				Arr[i] = 0;
			}
			printf("\n");
		}
	}
	

	return 0;
}