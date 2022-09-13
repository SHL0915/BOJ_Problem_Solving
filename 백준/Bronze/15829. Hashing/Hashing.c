#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int pow(int n, int exp)
{
	if (exp == 0) return 1;
	else
	{
		return n * pow(n, exp - 1);
	}
}
int main(void)
{
	int L, i;
	char str[50];
	int hash = 0;
	

	scanf("%d", &L);

	scanf("%s", str);

	for (i = 0; i < L; i++)
	{
		hash += (str[i] - 'a' + 1) * pow(31, i);
	}

	hash = hash % 1234567891;

	printf("%d", hash);
	
	return 0;
}
