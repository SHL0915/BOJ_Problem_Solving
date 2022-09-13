#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Fivonacci(int N)
{
	if (N == 0)
	{
		return 0;
	}

	if (N == 1)
	{
		return 1;
	}
	else return Fivonacci(N - 1) + Fivonacci(N - 2);
}

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%d", Fivonacci(N));
	return 0;
}
