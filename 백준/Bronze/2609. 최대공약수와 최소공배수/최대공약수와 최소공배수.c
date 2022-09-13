#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int a, b;
	int i;
	int min = 1;
	int max = 1;

	scanf("%d %d", &a, &b);

	for (i = 2;; i++)
	{
		if ((a / i == 0) & (b / i == 0))
		{
			printf("%d\n", max);
			min *= a * b;
			printf("%d", min);
			break;
		}
		else if ((a % i == 0) & (b % i == 0))
		{
			min *= i;
			max *= i;
			a = a / i;
			b = b / i;
			i -= 1;
			continue;
		}
	}

	return 0;

}