#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	char board[50][51];
	char chess1[8][8];
	char chess2[8][8];
	int N, M;
	int i, j, k, l;
	int min = 64;
	int count1, count2;

	for (i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			for (j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					chess1[i][j] = 'W';
				}
				else chess1[i][j] = 'B';
			}
		}
		else
		{
			for (j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					chess1[i][j] = 'B';
				}
				else chess1[i][j] = 'W';
			}
		}
		
	} // chess1 초기화

	for (i = 0; i < 8; i++)
	{
		if (i % 2 == 1)
		{
			for (j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					chess2[i][j] = 'W';
				}
				else chess2[i][j] = 'B';
			}
		}
		else
		{
			for (j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					chess2[i][j] = 'B';
				}
				else chess2[i][j] = 'W';
			}
		}

	} 

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		scanf("%s", board[i]);
	}

	for (i = 0; i < N-7; i++)
	{
		for (j = 0; j < M - 7; j++)
		{
			count1 = 0;
			count2 = 0;
			for (k = i; k < i+8; k++)
			{
				for (l = j; l < j + 8; l++)
				{
					if (board[k][l] != chess1[k - i][l - j]) count1 += 1;
					if (board[k][l] != chess2[k - i][l - j]) count2 += 1;
				}
			}
			if (count1 < count2)
			{
				if (count1 < min) min = count1;
			}
			else
			{
				if (count2 < min) min = count2;
			}
		}
		
	}
	printf("%d", min);
	return 0;
}