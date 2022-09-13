#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int X;
	int i;

	scanf("%d", &X);

	for (i = 1;; i++)
	{
		X -= i;
		if (X <= 0) break;
	}

	if (i % 2 == 1)
	{
		printf("%d/%d", 1 - X, i + X);
	}
	else printf("%d/%d", i + X,1 - X);


	return 0;

}