#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N, i;
	
	scanf("%d", &N);

	for (i = N; i >= 1; i--)
	{
		printf("%d\n", i);
	}

	return 0;

}