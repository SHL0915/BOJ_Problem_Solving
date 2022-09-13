#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void hanoi(int n, int from, int to, int sub)
{

	if (n == 1)
	{
		printf("%d %d\n",from, to);	
	}
	else
	{
		hanoi(n - 1, from, sub, to);
		printf("%d %d\n", from, to);
		hanoi(n - 1, sub, to, from);
	}
}

void hanoicount(int n, int from, int to, int sub, int* num)
{
	int* a = num;
	if (n == 1)
	{
		(*num) += 1;
	}
	else
	{
		hanoicount(n - 1, from, sub, to,a);
		(*num) += 1;
		hanoicount(n - 1, sub, to, from,a);
	}
}



int main(void)
{
	int N;
	int num=0;

	scanf("%d", &N);

	hanoicount(N, 1, 3, 2, &num);

	printf("%d\n", num);
	hanoi(N, 1, 3, 2);

	return 0;
}