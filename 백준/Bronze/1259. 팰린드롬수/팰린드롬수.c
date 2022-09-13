#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	int N, temp;
	int i, j, len;
	int arr[5] = { 0 };
	int num;

	for (i = 0; ; i++)
	{
		num = 0;
		scanf("%d", &N);
		if (N == 0) break;
		
		temp = N;
		for (j = 0;; j++)
		{
			if (temp == 0)
			{
				len = j;
				break;
			}
			arr[j] = temp % 10;
			temp = temp / 10;
		}

		for (j = 0; j < len/2; j++)
		{
			if (arr[j] != arr[len - j - 1]) num += 1;
		}

		if (num == 0) printf("yes\n");
		else printf("no\n");

	}

	return 0;
}
