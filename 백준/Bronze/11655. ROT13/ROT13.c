#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char c;
	char S[101];
	int i, len;

	i = 0;

	while((c = getchar()) != '\n') {
		S[i] = c;
		i++;
	}
	S[i] = '\0';

	len = strlen(S);


	for (i = 0; i < len; i++) {
		if ((S[i] >= 'A') && (S[i] <= 'Z')) 
			S[i] = 'A' + (S[i] - 'A' + 13) % 26;
		else if ((S[i] >= 'a') && (S[i] <= 'z'))
			S[i] = 'a' + (S[i] - 'a' + 13) % 26;
	}
	
	printf("%s", S);

	


	return 0;
}