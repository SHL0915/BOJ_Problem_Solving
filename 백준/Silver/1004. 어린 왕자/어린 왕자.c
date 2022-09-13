#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int T, n;
	int a, b;
	int result;
	int i, j;
	int pos1[2];
	int pos2[2];
	int cir[3];
	int pos1_cir_dir, pos2_cir_dir;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		result = 0;

		scanf("%d %d %d %d", &pos1[0], &pos1[1], &pos2[0], &pos2[1]);
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			a = 0;
			b = 0;
			scanf("%d %d %d", &cir[0], &cir[1], &cir[2]);

			pos1_cir_dir = (pos1[0] - cir[0]) * (pos1[0] - cir[0]) + (pos1[1] - cir[1]) * (pos1[1] - cir[1]);
			pos2_cir_dir = (pos2[0] - cir[0]) * (pos2[0] - cir[0]) + (pos2[1] - cir[1]) * (pos2[1] - cir[1]);


			if ((cir[2] * cir[2]) > pos1_cir_dir)
				a = 1;
			if ((cir[2] * cir[2]) > pos2_cir_dir)
				b = 1;

			if (a != b)
				result += 1;
		}

		printf("%d\n", result);
	}

}