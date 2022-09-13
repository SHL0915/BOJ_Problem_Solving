#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, i;
	int temp1, temp2;
	int result;

	scanf("%d", &n);

	for (i = 1; i <= n+1; i++)
	{
		if (i == 1)
		{
			result = 0;
			temp1 = 0;
		}
		else if (i == 2)
		{
			result = 1;
			temp2 = 1;
		}
		else
		{
			if (i % 2 == 1)
			{
				result += temp1;
				temp1 = result;
			}
			else
			{
				result += temp2;
				temp2 = result;
			}
		}
	}

	printf("%d", result);
	return 0;
}