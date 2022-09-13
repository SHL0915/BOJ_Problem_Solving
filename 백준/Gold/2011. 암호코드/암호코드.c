#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[5000] = { 0 };

int main(void) {
	char input[5001];
	int* Arr;
	int len, i;

	scanf("%s", input);
	len = strlen(input);
	Arr = (int*)malloc(sizeof(int) * len);

	for (i = 0; i < len; i++) {
		Arr[i] = input[i] - '0';
	}

	if (Arr[0] == 0) {
		printf("0");
		return 0;
	}
	else
		num[0] = 1;

	if (len == 1) {
		printf("%d", num[0]);
		return 0;
	}

	if (Arr[1] == 0) {
		if ((Arr[0] == 1) || (Arr[0] == 2))
			num[1] = 1;
		else {
			printf("0");
			return 0;
		}
	}
	else if (Arr[0] == 1) {
		num[1] = 2;
	}
	else if (Arr[0] == 2) {
		if ((Arr[1] > 0) && (Arr[1] <= 6))
			num[1] = 2;
		else
			num[1] = 1;
	}
	else
		num[1] = 1;

	for (i = 2; i < len; i++) {
		if (Arr[i] == 0) {
			if ((Arr[i - 1] == 1) || (Arr[i - 1] == 2))
				num[i] = num[i - 2] % 1000000;
			else {
				printf("0");
				return 0;
			}
		}
		else if (Arr[i-1] == 1) {
			num[i] = num[i - 1] % 1000000 + num[i - 2] % 1000000;
			num[i] = num[i] % 1000000;
		}
		else if (Arr[i-1] == 2) {
			if ((Arr[i] > 0) && (Arr[i] <= 6)) {
				num[i] = num[i - 1] % 1000000 + num[i - 2] % 1000000;
				num[i] = num[i] % 1000000;
			}
			else
				num[i] = num[i - 1] % 1000000;
		}
		else 
			num[i] = num[i - 1] % 1000000;
	}

	printf("%d", num[len - 1]);
	return 0;
}