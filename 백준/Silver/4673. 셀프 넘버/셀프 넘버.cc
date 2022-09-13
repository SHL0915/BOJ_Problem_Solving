#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int arr[10100] = { 0 };
	int i,j;
	int value, temp;

	for (i = 1; i <= 10000; i++)
	{
		value = i;
		temp = i;
		for (j = 0;; j++)
		{
			if (temp / 10 == 0)
			{
				value += temp % 10;
				break;
			}
			value += temp % 10;
			temp = temp / 10;
		}
		arr[value] = 1;
	}

	for (i = 1; i < 10001; i++)
	{
		if (arr[i] == 0)printf("%d\n", i);
	}

	return 0;
}