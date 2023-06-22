#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double Dis(int x1, int y1, int x2, int y2)
{
	double dis;
	dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	dis = sqrt(dis);

	return dis;
}

int main(void)
{
	int T;
	int i;
	int x1, y1, r1, x2, y2, r2;
	double dis;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		dis = Dis(x1, y1, x2, y2);
		if (r1 == r2)
		{
			if ((x1 == x2) & (y1 == y2)) {
                if(r1 == 0) printf("%d\n", 1);
                else printf("%d\n", -1);
            }
			else if (r1 + r2 > dis) printf("%d\n", 2);
			else if (r1 + r2 == dis) printf("%d\n", 1);
			else printf("%d\n", 0);
		}
		else if (r1 > r2)
		{
			if ((x1 == x2) & (y1 == y2)) printf("%d\n", 0);
			else if (dis <= r1)
			{
				if ((r1 - dis) == r2) printf("%d\n", 1);
				else if ((r1 - dis) > r2) printf("%d\n", 0);
				else if ((r1 - dis) < r2) printf("%d\n", 2);
			}
			else
			{
				if (r1 + r2 == dis) printf("%d\n", 1);
				else if (r1 + r2 > dis) printf("%d\n", 2);
				else printf("%d\n", 0);
			}			
		}
		else
		{
			if ((x1 == x2) & (y1 == y2)) printf("%d\n", 0);
			else if (dis <= r2)
			{
				if ((r2 - dis) == r1) printf("%d\n", 1);
				else if ((r2 - dis) > r1) printf("%d\n", 0);
				else if ((r2 - dis) < r1) printf("%d\n", 2);
			}
			else
			{
				if (r1 + r2 == dis) printf("%d\n", 1);
				else if (r1 + r2 > dis) printf("%d\n", 2);
				else printf("%d\n", 0);
			}
		}
	}

	return 0;
}
