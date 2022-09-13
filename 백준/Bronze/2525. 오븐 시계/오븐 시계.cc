#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int H,M;
	int time;

	scanf("%d %d", &H,&M);
	scanf("%d", &time);

	M += time;

	if (M >= 60)
	{
		H += (M/60);
		M = M%60;
		if (H >= 24) H -= 24;

		printf("%d %d", H, M);
		return 0;
	}

	printf("%d %d", H, M);

	return 0;

}