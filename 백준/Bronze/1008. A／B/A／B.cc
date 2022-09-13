#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int A, B;

	scanf("%d %d", &A, &B);
	printf("%.11Lf", A / (long double)B);
	return 0;
}