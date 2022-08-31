#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int E, S, M;
	int i, j, k, count = 1; // E에 대응되는 i, S에 대응되는 j, M에 대응되는 k, 연도 count
	scanf("%d %d %d", &E, &S, &M);
	i = 1;
	j = 1;
	k = 1;
	while (1) { // 일치하는 연도까지 반복
		if (i == E && j == S && k == M)
			break;
		if (i == 15)
			i = 1;
		else
			i++;
		if (j == 28)
			j = 1;
		else
			j++;
		if (k == 19)
			k = 1;
		else
			k++;
		count++;
	}
	printf("%d", count);
	return 0;
}