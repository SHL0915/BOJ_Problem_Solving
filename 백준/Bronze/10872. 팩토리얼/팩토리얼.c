#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int factorial(int N)
{
	if (N == 0)
	{
		return 1;
	}
	else
	{
		return N * factorial(N - 1);
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);
	printf("%d", factorial(N));

	return 0;
}
