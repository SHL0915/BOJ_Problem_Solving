#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	char a;
	int num = 0;
		

	while ((a = getchar()) != EOF) {		
		printf("%c", a);
	}	
	
	return 0;
}