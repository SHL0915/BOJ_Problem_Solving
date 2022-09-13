#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int xarr[3];
	int yarr[3];

	int i;
	int num = 0;

	scanf("%d %d", &xarr[0], &yarr[0]);
	scanf("%d %d", &xarr[1], &yarr[1]);
	scanf("%d %d", &xarr[2], &yarr[2]);

	for (i = 1; i < 3; i++)
	{
		if (xarr[i] == xarr[0]) num += 1;
	}
	if (num == 0) printf("%d ", xarr[0]);
	else
	{
		if (xarr[0] == xarr[1]) printf("%d ", xarr[2]);
		else printf("%d ", xarr[1]);
	}

	num = 0;

	for (i = 1; i < 3; i++)
	{
		if (yarr[i] == yarr[0]) num += 1;
	}
	if (num == 0) printf("%d", yarr[0]);
	else
	{
		if (yarr[0] == yarr[1]) printf("%d", yarr[2]);
		else printf("%d ", yarr[1]);
	}

	return 0;

}
