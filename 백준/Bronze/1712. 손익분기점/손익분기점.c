#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int A, B, C;
	int i;
	int cost, earning;

	scanf("%d %d %d", &A, &B, &C);



	if (B >= C)
	{
		printf("-1");
		return 0;
	}
	else
	{
		i = A / (C - B);
		i += 1;
		printf("%d", i);
		return 0;
	}
}