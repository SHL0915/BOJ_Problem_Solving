#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int C, N, i, j, k;
	int arr[1001];
	int sum;
	double avg;

	scanf("%d", &C);

	for (i = 0; i < C; i++)
	{
		sum = 0;
		k = 0;
		scanf("%d", &N);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		avg = sum / ((double)N);
		for (j = 0; j < N; j++)
		{
			if (arr[j] > avg) k += 1;
		}

		printf("%.3lf%%\n", (k / ((double)N)) * 100);
	}
	return 0;

}
