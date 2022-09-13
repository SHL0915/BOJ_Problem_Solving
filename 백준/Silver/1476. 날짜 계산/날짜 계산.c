#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int E, S, M, i = 1, j = 1, k = 1, year = 1; // E에 해당하는 i, S에 해당하는 j, M에 해당하는 k 
	scanf("%d %d %d", &E, &S, &M);
	while (1) {
		if ((i == E) && (j == S) && (k == M)) { // 조건을 만족시키는 경우
			printf("%d", year);
			break;
		}
		else {
			i++;
			j++;
			k++;
			year++;
			if (i > 15)
				i = 1;
			if (j > 28)
				j = 1;
			if (k > 19)
				k = 1;
		}		
	}
	return 0;
}