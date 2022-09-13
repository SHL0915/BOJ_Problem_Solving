#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N;
	int max = 0;
	double sum = 0;
	int i;
	int arr[1000] = { 0 };

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i] >= max)max = arr[i];
	}

	for (i = 0; i < N; i++)
	{
		sum += (arr[i] / (double)max) * 100;
	}

	printf("%lf", sum / N);
}
