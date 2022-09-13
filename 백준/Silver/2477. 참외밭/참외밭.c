#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int K;
	int i;
	int info[6];
	int dir[4] = { 0 };
	int a, b;
	int WholeArea = 1;
	int MinusArea = 0;

	scanf("%d", &K);

	for (i = 0; i < 6; i++) {
		scanf("%d %d", &a, &b);
		info[i] = a * 1000 + b;
		if (a == 1)
			dir[0] += 1;
		else if (a == 2)
			dir[1] += 1;
		else if (a == 3)
			dir[2] += 1;
		else
			dir[3] += 1;
	}

	b = 0;

	for (i = 0; i < 4; i++) {
		if (b == 0)
		{
			if (dir[i] == 2) {
				a = i+1;
				b = 1;
			}
		}
		else
		{
			if (dir[i] == 2) {
				b = i+1;
				break;
			}
		}
	}

	if (a * b == 3)
	{
		a = 3;
		b = 1;
	}
	else if (a * b == 6)
	{
		a = 2;
		b = 3;
	}
	else if (a * b == 8)
	{
		a = 4;
		b = 2;
	}
	else
	{
		a = 1;
		b = 4;
	}

	for (i = 0; i < 6; i++) {
		if ((info[i] / 1000 != a) && (info[i] / 1000 != b)) {
			WholeArea *= (info[i] % 1000);
		}
	}


	for (i = 0; i < 4; i++) {
		if ((info[i] / 1000 == a) && (info[i + 1] / 1000 == b)) {
			if (i == 0)
			{
				if (info[2] / 1000 == a)
					MinusArea = (info[1] % 1000) * (info[2] % 1000);
				else
					MinusArea = (info[0] % 1000) * (info[5] % 1000);
				break;
			}
			else if (i == 1)
			{
				if (info[3] / 1000 == a)
					MinusArea = (info[2] % 1000) * (info[3] % 1000);
				else
					MinusArea = (info[0] % 1000) * (info[1] % 1000);
				break;
			}
			else if (i == 2)
			{
				MinusArea = (info[3] % 1000) * (info[4] % 1000);
				break;
			}
			else 
			{
				MinusArea = (info[4] % 1000) * (info[5] % 1000);
				break;
			}
		}
	}
	

	printf("%d", K * (WholeArea - MinusArea));
	return 0;
}