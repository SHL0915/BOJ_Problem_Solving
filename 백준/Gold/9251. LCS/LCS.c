#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str1[1001];
	char str2[1001];
	int len1, len2, i, j;
	int** Arr;

	scanf("%s %s", str1, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	Arr = (int**)malloc(sizeof(int*) * (len1+1));

	for (i = 0; i <= len1; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * (len2+1));
	}

	for (i = 0; i <= len1; i++) {
		Arr[i][0] = 0;
	}
	for (i = 0; i <= len2; i++) {
		Arr[0][i] = 0;
	}



	for (i = 1; i <= len2; i++) {
		for (j = 1; j <= len1; j++) {
			if (str1[j - 1] == str2[i - 1]) {
				Arr[j][i] = Arr[j - 1][i - 1] + 1;
			}
			else {
				Arr[j][i] = (Arr[j - 1][i] > Arr[j][i - 1] ? Arr[j - 1][i] : Arr[j][i - 1]);
			}
		}
	}

	printf("%d", Arr[len1][len2]);
	return 0;
}
