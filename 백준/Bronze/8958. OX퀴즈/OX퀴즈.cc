#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N,i,j,con;
	char test[80];
	int score;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		con = 0;
		score = 0;
		scanf("%s", test);
		for (j=0;;j++)
		{
			if (test[j] == '\0')
			{
				printf("%d\n", score);
				break;
			}

			if (test[j] == 'O')
			{
				con += 1;
				score += con;
			}
			else
			{
				con = 0;
			}
		}
	}

	return 0;
}
