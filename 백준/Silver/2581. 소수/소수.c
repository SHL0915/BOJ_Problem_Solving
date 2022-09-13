#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int M, N;
	int i, j;
	int d;
	int min = 10001;
	int sum = 0;

	scanf("%d", &M);
	scanf("%d", &N);

	for (i = M; i <= N; i++)
	{
		d = 0;
		for (j = 1; j <= i; j++)
		{
			if (i % j == 0) d += 1;
		}
		if (d == 2)
		{
			if (i <= min) min = i;
			sum += i;
		}
	}

	if (min == 10001) printf("%d", -1);
	else
	{
		printf("%d\n%d", sum, min);
	}
	return 0;
}