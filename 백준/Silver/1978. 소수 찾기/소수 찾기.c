#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int N, num;
	int d;
	int pnum = 0;
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		d = 0;
		for (j = 1; j <= num; j++)
		{
			if (num % j == 0) d += 1;
		}
		if (d == 2) pnum += 1;
	}

	printf("%d", pnum);

}