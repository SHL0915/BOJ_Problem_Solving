#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int V, A, B;

	scanf("%d %d %d", &A, &B, &V);

	if ((V - A) % (A - B) == 0)
	{
		printf("%d", ((V - A) / (A - B)) + 1);
	}
	else printf("%d", ((V-A)/(A-B))+2);
	return 0;
}