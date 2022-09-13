#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int n;
	int arr[300000] = { 0 };
	int i , j, k;
	int pnum1, pnum2;
	

	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
			return 0;
		}
		pnum1 = 0;
		pnum2 = 0;

		for (j = 2; j<= n; j++)
		{
			if (arr[j] == 0)
			{
				for (k = 2; k <= n / j; k++)
				{
					arr[k * j] = 1;
				}
				pnum1 += 1;
			}
		}
		for (j = 2; j <= 2*n; j++)
		{
			if (arr[j] == 0)
			{
				for (k = 2; k <= (2*n) / j; k++)
				{
					arr[k * j] = 1;
				}
				pnum2 += 1;
			}
		}

		printf("%d\n", pnum2 - pnum1);

	}
	return 0;
}