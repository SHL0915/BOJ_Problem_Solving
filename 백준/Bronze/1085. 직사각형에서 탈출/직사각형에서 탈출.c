#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int x, y, w, h;

	int a, b;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (x <= w - x) a = x;
	else a = w - x;

	if (y <= h - y) b = y;
	else b = h - y;

	printf("%d", a >= b ? b : a);

	return 0;
}
