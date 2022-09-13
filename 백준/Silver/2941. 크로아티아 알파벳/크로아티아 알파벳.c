#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	char str[102];
	int i, len;
	int clen = 0;

	scanf("%s", str);

	len = strlen(str);

	str[len] = ' ';
	str[len + 1] = ' ';
	str[len + 2] = '\0';

	for (i = 0; i < len; i++)
	{
		if (str[i] == 'c')
		{
			if ((str[i + 1] == '-') | (str[i + 1] == '='))
			{
				clen += 1;
				i += 1;
			}
			else clen += 1;
		}
		else if (str[i] == 'd')
		{
			if (str[i + 1] == '-')
			{
				clen += 1;
				i += 1;
			}
			else if ((str[i + 1] == 'z') & (str[i + 2] == '='))
			{
				clen += 1;
				i += 2;
			}
			else clen += 1;
		}
		else if ((str[i] == 'l') & (str[i + 1] == 'j'))
		{
			clen += 1;
			i += 1;
		}
		else if ((str[i] == 'n') & (str[i + 1] == 'j'))
		{
			clen += 1;
			i += 1;
		}
		else if ((str[i] == 's') & (str[i + 1] == '='))
		{
			clen += 1;
			i += 1;
		}
		else if ((str[i] == 'z') & (str[i + 1] == '='))
		{
			clen += 1;
			i += 1;
		}
		else clen += 1;
	}

	printf("%d", clen);

	return 0;
}