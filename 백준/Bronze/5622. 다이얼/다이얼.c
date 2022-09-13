#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	char str[15];
	int i, len;
	int num[15] = { 0 };
	int sum = 0;
	
	scanf("%s", str);

	for (i = 0;; i++)
	{
		if (str[i] == '\0') break;

		if (str[i] == '1') num[i] += 2;
		else if (str[i] == '0') num[i] += 11;
		else
		{
			switch (str[i])
			{
			case 'A': num[i] += 3; break;
			case 'B': num[i] += 3; break;
			case 'C': num[i] += 3; break;
			case 'D': num[i] += 4; break;
			case 'E': num[i] += 4; break;
			case 'F': num[i] += 4; break;
			case 'G': num[i] += 5; break;
			case 'H': num[i] += 5; break;
			case 'I': num[i] += 5; break;
			case 'J': num[i] += 6; break;
			case 'K': num[i] += 6; break;
			case 'L': num[i] += 6; break;
			case 'M': num[i] += 7; break;
			case 'N': num[i] += 7; break;
			case 'O': num[i] += 7; break;
			case 'P': num[i] += 8; break;
			case 'Q': num[i] += 8; break;
			case 'R': num[i] += 8; break;
			case 'S': num[i] += 8; break;
			case 'T': num[i] += 9; break;
			case 'U': num[i] += 9; break;
			case 'V': num[i] += 9; break;
			case 'W': num[i] += 10; break;
			case 'X': num[i] += 10; break;
			case 'Y': num[i] += 10; break;
			case 'Z': num[i] += 10; break;
			}
		}
	}
	len = i;

	for (i = 0; i < len; i++)
	{
		sum += num[i];
	}
	printf("%d", sum);

	return 0;
}