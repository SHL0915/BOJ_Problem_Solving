#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int N;
	int i, j, k, l, pos = 0;
	int jnum, num;
	int temp;
	int arr[10000];
	int d[1000];

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = pos + 1;; j++)
		{
			jnum = 0;
			temp = j;

			for (k = 0;; k++)
			{
				if (temp == 0) break;
				d[k] = temp % 10;
				temp = temp / 10;
			}

			for (l = 0; l < k - 2; l++)
			{
				if ((d[l] == 6) & (d[l + 1] == 6) & (d[l + 2] == 6))
				{
					jnum += 1;
				}
			}

			if (jnum >= 1)
			{
				pos = j;
				break;
			}
		}
	}

	printf("%d", pos);

	return 0;
}
