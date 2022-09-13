#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int A, B;
	
	scanf("%d %d", &A, &B);
	printf("%d\n%d\n%d\n%d", A*(B%10),A*((B%100)/10),A*(B/100), A*B);

	return 0;
}