#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	char str[101];
	int i, pos;

	scanf("%s", str);

	pos = 0;	

	while(1){
		for (i = pos; (i < pos+10) && (str[i] != '\0'); i++) {
			printf("%c", str[i]);
		}
		pos = i;
		if (str[pos] == '\0')
			break;
		printf("\n");
	}

	return 0;
}