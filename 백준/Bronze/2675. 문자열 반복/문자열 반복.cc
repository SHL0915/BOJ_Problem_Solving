#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int T, R, i, j,k;
	char arr[20];

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &R);
		scanf("%s", arr);

		for (j = 0;; j++)
		{
			if (arr[j] == '\0') break;
			for (k = 0; k < R; k++)
			{
				printf("%c", arr[j]);
			}
		}
		printf("\n");
	}

	return 0;
}