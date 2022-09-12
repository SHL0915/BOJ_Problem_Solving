#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c; // 입력받은 문자 c
	int count = 0; // 모음의 개수 count
	while (1) {
		c = getchar();
		if (c == '#')
			break;
		else if (c == '\n') {
			printf("%d\n", count);
			count = 0;
		}
		switch (c) {
		case 'a': count++;
			break;
		case 'e': count++;
			break;
		case 'i': count++;
			break;
		case 'o': count++;
			break;
		case 'u': count++;
			break;
		case 'A': count++;
			break;
		case 'E': count++;
			break;
		case 'I': count++;
			break;
		case 'O': count++;
			break;
		case 'U': count++;
			break;
		default: break;
		}
	}
	return 0;
}