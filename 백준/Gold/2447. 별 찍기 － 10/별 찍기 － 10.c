#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Star(int i, int j, int N)
{
	if (N == 0) return;
	else if (((i / N) % 3 == 1) & ((j / N) % 3 == 1)) printf(" ");
	else
	{
		if (N / 3 == 0) printf("*");
		Star(i, j, N/3);
	}
}


int main(void)
{
	int N;
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			Star(i, j, N);
		}
		printf("\n");
	}

	return 0;
}