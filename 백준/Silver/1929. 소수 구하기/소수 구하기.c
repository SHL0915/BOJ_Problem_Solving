#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int M, N;
	int arr[2000000] = { 0 };
	int i, j;

	arr[0] = 1;
	arr[1] = 1;

	scanf("%d %d", &M, &N);

	for (i = 2;i<=N; i++)
	{
		for (j = 2; j < (N / i)+1; j++)
		{
			if (arr[j * i] == 0)
			{
				arr[j * i] = 1;
			}
		}
	}

	for (i = M; i <= N; i++)
	{
		if (arr[i] == 0) printf("%d\n", i);
	}

	return 0;
}
