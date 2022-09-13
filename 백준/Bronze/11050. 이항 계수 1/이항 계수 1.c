#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int factorial(int n)
{
	if (n == 0) return 1;
	else
	{
		return n * factorial(n - 1);
	}
}
int main(void)
{
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d", factorial(N) / (factorial(K) * factorial(N - K)));
	return 0;
}
