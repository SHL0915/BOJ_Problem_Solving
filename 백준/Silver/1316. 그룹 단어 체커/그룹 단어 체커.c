#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	int N, i, j, k;
	char str[100];
	int len;
	int o;
	int group = 0;
	int alp[26] = { 0 };

	
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", str);
		o = 0;

		len = strlen(str);
		str[len] = ' ';
		str[len + 1] = '\0';

		for (j = 1; j < len+1; j++)
		{
			if (str[j] != str[j - 1])
			{
				for (k = 0; k < j; k++)
				{
					if (str[k] == str[j]) o += 1;
				}
			}
		}

		if (o == 0) group += 1;
	}
	printf("%d", group);
	return 0;
}