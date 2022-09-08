#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	char cA[100001];
	char cB[100001];

	int iA[100001] = { 0 };
	int iB[100001] = { 0 };
	int sum[100002] = { 0 };
	int i, lenA, lenB;

	scanf("%s %s", cA, cB);

	

	for (i = 0;; i++)
	{
		if (cA[i] == '\0') break;
	}
	lenA = i;

	for (i = 0; i < lenA; i++)
	{
		iA[i] = cA[lenA - i - 1] - 48;
	}

	for (i = 0;; i++)
	{
		if (cB[i] == '\0') break;
	}
	lenB = i;

	for (i = 0; i < lenB; i++)
	{
		iB[i] = cB[lenB - i - 1] - 48;
	}
	
	if (lenA >= lenB)
	{
		for (i = 0; i < lenA; i++)
		{
			sum[i] = sum[i] + iA[i] + iB[i];
			if (sum[i] >= 10)
			{
				sum[i + 1] += sum[i] / 10;
				sum[i] = sum[i] % 10;
			}
			else sum[i] = sum[i] % 10;
		}
		if (sum[lenA] != 0)
		{
			for (i = lenA; i >= 0; i--)
			{
				printf("%d", sum[i]);
			}
		}
		else
		{
			for (i = lenA-1; i >= 0; i--)
			{
				printf("%d", sum[i]);
			}
		}

	}
	else
	{
		for (i = 0; i < lenB; i++)
		{
			sum[i] = sum[i] + iA[i] + iB[i];
			if (sum[i] >= 10)
			{
				sum[i + 1] += sum[i] / 10;
				sum[i] = sum[i] % 10;
			}
			else sum[i] = sum[i] % 10;
		}
		if (sum[lenB] != 0)
		{
			for (i = lenB; i >= 0; i--)
			{
				printf("%d", sum[i]);
			}
		}
		else
		{
			for (i = lenB - 1; i >= 0; i--)
			{
				printf("%d", sum[i]);
			}
		}
	}




	return 0;
}