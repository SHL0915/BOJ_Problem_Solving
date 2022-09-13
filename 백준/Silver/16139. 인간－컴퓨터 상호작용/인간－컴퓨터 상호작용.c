#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char S[200001];
	int** Arr;
	int len;
	int q;
	int i, j;
	char temp;
	int l, r;

	scanf("%s", S);

	len = strlen(S);
	Arr = (int**)malloc(sizeof(int*) * len);

	for (i = 0; i < len; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * 26);
		for (j = 0; j < 26; j++) {
			Arr[i][j] = 0;
		}
	}

	scanf("%d", &q);

	for (i = 0; i < len; i++) {
		Arr[i][(S[i] - 'a')] += 1;
	}
	for (i = 1; i < len; i++) {
		for (j = 0; j < 26; j++) {
			Arr[i][j] += Arr[i - 1][j];			
		}
	}
		
	for (i = 0; i < q; i++) {
		getchar();
		scanf("%c", &temp);
		scanf("%d", &l);
		scanf("%d", &r);
		if (l == 0) {
			printf("%d\n", Arr[r][temp - 'a']);
		}
		else
			printf("%d\n", Arr[r][(temp - 'a')] - Arr[l-1][(temp - 'a')]);
	}
		
	return 0;
}