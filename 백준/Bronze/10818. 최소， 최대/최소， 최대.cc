#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N,value;
	int min = 1000000;
	int max = -1000000;
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &value);
		if (value >= max) max = value;
		if (value <= min) min = value;
	}

	printf("%d %d", min, max);
	return 0;
}
