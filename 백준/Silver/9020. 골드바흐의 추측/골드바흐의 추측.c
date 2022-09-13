#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int T, N;
	int i, j, k;
	int pnum1, pnum2;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);

		for (j = (N / 2); j >= 1; j--)
		{
			pnum1 = 0;
			pnum2 = 0;

			for (k = 1; k <= j; k++)
			{
				if (j % k == 0) pnum1 += 1;
			}

			for (k = 1; k <= N-j; k++)
			{
				if ((N-j) % k == 0) pnum2 += 1;
			}

			if ((pnum1 == 2) & (pnum2 == 2))
			{
				printf("%d %d\n", j, N - j);
				break;
			}
		}
	}

	return 0;
}
