#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	int N;
	int i, j;
	int temp;
	int sum;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		if (i == N)
		{
			printf("%d", 0);
		}
		else
		{
			sum = i;
			temp = i;
			for (j = 0;; j++)
			{
				if (temp == 0) break;
				sum += temp % 10;
				temp = temp / 10;
			}

			if (sum == N)
			{
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}
