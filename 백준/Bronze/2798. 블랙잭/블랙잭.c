#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	int N, M;
	int i, j, k, l, temp;
	int arr[100];
	int esc = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N-1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = M; i > 0; i--)
	{
		if (esc == 1) break;
		for (j = 0; j < N - 2; j++)
		{
			if (esc == 1) break;
			for (k = j + 1; k < N - 1; k++)
			{
				if (esc == 1) break;
				for (l = k + 1; l < N; l++)
				{
					if (arr[j] + arr[k] + arr[l] == i)
					{
						printf("%d", i);
						esc = 1;
						break;
					}
				}

			}
		}
	}

	return 0;
}
