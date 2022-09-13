#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int arr[10];
	int i;
	int num[10] = { 0 };
	int A, B, C;
	int result;
	
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	result = A * B * C;

	for (i = 0;; i++)
	{
		arr[i] = result % 10;
		switch (arr[i])
		{
		case 0: num[0] += 1; break;
		case 1: num[1] += 1; break;
		case 2: num[2] += 1; break;
		case 3: num[3] += 1; break;
		case 4: num[4] += 1; break;
		case 5: num[5] += 1; break;
		case 6: num[6] += 1; break;
		case 7: num[7] += 1; break;
		case 8: num[8] += 1; break;
		case 9: num[9] += 1; break;
		}
		if (result / 10 == 0) break;
		result = result / 10;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", num[i]);
	}


	return 0;

}
