#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, X;
	int i, value;

	scanf("%d %d", &N, &X);

	for (i = 0; i < N; i++)
	{
		scanf("%d", & value);
		if (value < X) printf("%d ", value);
	}

	return 0;
}
