#include <stdio.h>
#include <string.h>

int Sugar(int N)
{
	int i;

	for (i = (N / 5); i >= 0; i--)
	{
		if (N % 5 == 0) return i;
		else if ((N - 5 * i) % 3 == 0)
		{
			return i + ((N - 5 * i) / 3);
		}
		else
		{
			if (i == 0) return -1;
			else continue;
		}
	}
}

int main(void)
{
	int N, result;

	scanf("%d", &N);

	result = Sugar(N);

	if (result == -1)
	{
		puts("-1");
		return 0;
	}
	else
	{
		printf("%d", result);
	}

	return 0;
}