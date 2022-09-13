#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[333335];
	int len, i , j;

	scanf("%s", str);
	len = strlen(str);

	switch (str[0]) {
	case '0': printf("0");
		break;
	case '1': printf("1");
		break;
	case '2': printf("10");
		break;
	case '3': printf("11");
		break;
	case '4': printf("100");
		break;
	case '5': printf("101");
		break;
	case '6': printf("110");
		break;
	case '7': printf("111");
		break;
	}

	for (i = 1; i < len; i++) {
		switch (str[i]) {
		case '0': printf("000");
			break;
		case '1': printf("001");
			break;
		case '2': printf("010");
			break;
		case '3': printf("011");
			break;
		case '4': printf("100");
			break;
		case '5': printf("101");
			break;
		case '6': printf("110");
			break;
		case '7': printf("111");
			break;
		}
	}


	return 0;
}