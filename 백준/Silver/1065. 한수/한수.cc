#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, temp;
	int num = 0;
	int i,j;
	int arr[4] = { 0 };

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		temp = i;
		for (j = 0;; j++)
		{
			if (temp / 10 == 0)
			{
				arr[j] = temp % 10;
				break;
			}
			arr[j] = temp % 10;
			temp = temp / 10;
		}
		if ((j == 0)|(j==1)) num += 1;
		else if (j == 2)
		{
			if ((arr[1] - arr[0]) == (arr[2] - arr[1])) num += 1;
		}
	}

	printf("%d", num);
	return 0;
}