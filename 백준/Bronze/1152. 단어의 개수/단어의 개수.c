#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	char str[10000002];
	int i;
	int len;
	int blank=0;

	fgets(str,sizeof(str),stdin);
	
	for (i = 0;; i++)
	{
		if (str[i] == '\0') {
			len = i;
			break;
		}
	}
	
	for (i = 0; i < len-1; i++) {
		if (str[i] == ' ')
			blank++;
	}

	if ((str[0] == ' ') && (str[len - 2] == ' '))
		printf("%d", blank - 1);

	else if (str[0] == ' ')
		printf("%d", blank);
	else if (str[len - 2] == ' ')
		printf("%d", blank);
	else
		printf("%d", blank + 1);

	return 0;
}