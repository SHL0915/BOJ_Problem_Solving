#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int N;
	int i, j;
	int sum;

	scanf("%d", &N);

	for (i = 1; ; i++)
	{
		sum = 1;
		for (j = 0; j < i; j++)
		{
			sum += j * 6;
		}

		if (N <= sum)
		{
			printf("%d", i);
			break;
		}

	}

	return 0;
}