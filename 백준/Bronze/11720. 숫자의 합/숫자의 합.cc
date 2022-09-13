#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char a[100];
	int N,i;
	int sum = 0;

	scanf("%d", &N);
	
	scanf("%s", a);

	for (i = 0; i < N; i++)
	{
		sum += a[i] - 48;
	}

	printf("%d", sum);
	

	return 0;
}