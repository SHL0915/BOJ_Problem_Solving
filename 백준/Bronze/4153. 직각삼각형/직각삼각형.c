#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int a, b, c;
	int T;
	int i;


	for (i = 0; ; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		if ((a == 0) & (b == 0) & (c == 0))
		{
			break;
		}
		else
		{
			if ((a >= b) & (a >= c))
			{
				if (a * a == b * b + c * c) printf("right\n");
				else printf("wrong\n");
			}
			else if ((b >= a) & (b >= c))
			{
				if (b * b == a * a + c * c) printf("right\n");
				else printf("wrong\n");
			}
			else if ((c >= b) & (c >= a))
			{
				if (c * c == b * b + a * a) printf("right\n");
				else printf("wrong\n");
			}
		}


	}
	return 0;
}
