#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int arr1[15];
	int arr2[15];
	int T, k, n;
	int i, j, l, m;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);

		for (j = 0; j < 15; j++)
		{
			arr2[j] = 0;
		}

		for (j = 0; j <= k; j++)
		{
			for (l = 1; l <= 14; l++)
			{
				if (arr2[l] == 0)
				{
					arr2[l] = l;
					arr1[l] = l;
				}
				else
				{
					arr2[l] = arr1[l];
					for (m = 1; m < l; m++)
					{
						arr1[l] += arr2[m];
					}
				}
			}
		}

		printf("%d\n", arr1[n]);
	}
	return 0;
}