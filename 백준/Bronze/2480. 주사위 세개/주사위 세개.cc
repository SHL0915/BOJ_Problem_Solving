#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	if ((A == B) & (A == C)) printf("%d", 10000 + A * 1000);
	else if ((A != B) & (B != C) & (A != C))
	{
		if (A > B)
		{
			if (A > C) printf("%d", A * 100);
			else printf("%d",C * 100);
		}
		else
		{
			{
				if (B > C) printf("%d", B * 100);
				else printf("%d",C * 100);
			}
		}
	}
	else
	{
		if (A == B) printf("%d", 1000 + A * 100);
		else if (B == C) printf("%d", 1000 + B * 100);
		else printf("%d", 1000 + A * 100);
	}

	return 0;

}