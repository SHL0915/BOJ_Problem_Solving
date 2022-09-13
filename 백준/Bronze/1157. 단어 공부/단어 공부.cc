#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	char str[1000000];
	int i, len, pos;
	int max = 0;
	int o = 0;
	int alp[26] = { 0 };

	scanf("%s", str);

	for (i = 0;; i++)
	{
		if (str[i] == '\0') break;
		if ((str[i] >= 97) & (str[i]<=122))
		{
			str[i] -= 32;
		}
	} 
	len = i+1;

	for (i = 0; i < len; i++)
	{
		switch (str[i])
		{
		case 65: alp[0] += 1; break;
		case 66: alp[1] += 1; break;
		case 67: alp[2] += 1; break;
		case 68: alp[3] += 1; break;
		case 69: alp[4] += 1; break;
		case 70: alp[5] += 1; break;
		case 71: alp[6] += 1; break;
		case 72: alp[7] += 1; break;
		case 73: alp[8] += 1; break;
		case 74: alp[9] += 1; break;
		case 75: alp[10] += 1; break;
		case 76: alp[11] += 1; break;
		case 77: alp[12] += 1; break;
		case 78: alp[13] += 1; break;
		case 79: alp[14] += 1; break;
		case 80: alp[15] += 1; break;
		case 81: alp[16] += 1; break;
		case 82: alp[17] += 1; break;
		case 83: alp[18] += 1; break;
		case 84: alp[19] += 1; break;
		case 85: alp[20] += 1; break;
		case 86: alp[21] += 1; break;
		case 87: alp[22] += 1; break;
		case 88: alp[23] += 1; break;
		case 89: alp[24] += 1; break;
		case 90: alp[25] += 1; break;
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (alp[i] >= max)max = alp[i];
	}

	for (i = 0; i < 26; i++)
	{
		if (alp[i] == max)
		{
			o += 1;
			pos = i;
		}
	}

	if (o == 1) printf("%c", ('A' + pos));
	else printf("?");
	

	return 0;
}