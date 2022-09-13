#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, i=0;
	int Result=100;

	int X;

	scanf("%d", &N);
	
	X = N;

	while (1)
	{
		if (Result == N)
		{
			printf("%d", i);
			break;
		}
		Result = (X % 10) * 10 + (X / 10 + X % 10) % 10;
		X = Result;
		i++;
	}

	return 0;
}