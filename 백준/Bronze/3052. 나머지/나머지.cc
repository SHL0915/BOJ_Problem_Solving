#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int num[10];
	int i,j;
	int result=0;
	int temp;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
		num[i] = num[i] % 42;
	}

	for (i = 0; i < 10; i++)
	{
		temp = 0;
		for (j = i; j >= 0; j--)
		{
			if (num[i] != num[j]) temp += 1;
		}
		if (temp == i) result += 1;
	}
	printf("%d", result);

	return 0;
}