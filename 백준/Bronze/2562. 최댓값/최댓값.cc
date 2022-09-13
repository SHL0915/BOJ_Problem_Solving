#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int arr[9];
	int i, max=0;
	
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max) max = arr[i];
	}
	printf("%d\n", max);

	for (i = 0; i < 9; i++)
	{
		if (arr[i] == max) printf("%d",i+1);
	}

	return 0;
}
