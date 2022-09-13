#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int N, i;

	scanf("%d", &N);

	if (N == 1)
	{
		return 0;
	}
	else
	{
		for (i = 2;; i++)
		{
			if (N == i)
			{
				printf("%d\n", i);
				break;
			}
			if (N % i == 0)
			{
				printf("%d\n", i);
				N = N / i;
				i--;
				continue;
			}
		}

		return 0;
	}
}
