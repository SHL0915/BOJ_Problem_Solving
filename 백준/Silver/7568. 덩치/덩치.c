#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int arr[50][3];
	int N;
	int i, j;
	int rank;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (i = 0; i < N; i++)
	{
		rank = 1;
		for (j = 0; j < N; j++)
		{
			if ((arr[i][0] < arr[j][0]) & (arr[i][1] < arr[j][1]))
			{
				rank += 1;
			}
		}
		printf("%d ", rank);
	}
	return 0;
}