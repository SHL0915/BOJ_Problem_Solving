#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	char S[100];
	int pos[26];
	int i;

	for (i = 0; i < 26; i++)
	{
		pos[i] = -1;
	}

	scanf("%s", &S);


	for (i = 0;; i++)
	{
		if (S[i] == '\0') break;
		switch (S[i])
		{
		case 'a': if (pos[0] == -1) pos[0] = i; break;
		case 'b': if (pos[1] == -1) pos[1] = i; break;
		case 'c': if (pos[2] == -1) pos[2] = i; break;
		case 'd': if (pos[3] == -1) pos[3] = i; break;
		case 'e': if (pos[4] == -1) pos[4] = i; break;
		case 'f': if (pos[5] == -1) pos[5] = i; break;
		case 'g': if (pos[6] == -1) pos[6] = i; break;
		case 'h': if (pos[7] == -1) pos[7] = i; break;
		case 'i': if (pos[8] == -1) pos[8] = i; break;
		case 'j': if (pos[9] == -1) pos[9] = i; break;
		case 'k': if (pos[10] == -1) pos[10] = i; break;
		case 'l': if (pos[11] == -1) pos[11] = i; break;
		case 'm': if (pos[12] == -1) pos[12] = i; break;
		case 'n': if (pos[13] == -1) pos[13] = i; break;
		case 'o': if (pos[14] == -1) pos[14] = i; break;
		case 'p': if (pos[15] == -1) pos[15] = i; break;
		case 'q': if (pos[16] == -1) pos[16] = i; break;
		case 'r': if (pos[17] == -1) pos[17] = i; break;
		case 's': if (pos[18] == -1) pos[18] = i; break;
		case 't': if (pos[19] == -1) pos[19] = i; break;
		case 'u': if (pos[20] == -1) pos[20] = i; break;
		case 'v': if (pos[21] == -1) pos[21] = i; break;
		case 'w': if (pos[22] == -1) pos[22] = i; break;
		case 'x': if (pos[23] == -1) pos[23] = i; break;
		case 'y': if (pos[24] == -1) pos[24] = i; break;
		case 'z': if (pos[25] == -1) pos[25] = i; break;



		}
	}

	for (i = 0; i < 26; i++)
	{
		printf("%d ", pos[i]);
	}

	return 0;	
}