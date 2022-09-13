#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int R;
	double pi = 3.141592653589;

	scanf("%d", &R);

	printf("%.6lf\n", R * R * pi);
	printf("%.6lf", (double)R * R * 2);
	
	return 0;
}
