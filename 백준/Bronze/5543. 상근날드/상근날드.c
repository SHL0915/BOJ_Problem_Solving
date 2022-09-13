#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i;
	int burger[3];
	int min_burger, min_ade;
	int ade[2];

	scanf("%d %d %d", &burger[0], &burger[1], &burger[2]);
	scanf("%d %d", &ade[0], &ade[1]);

	min_burger = burger[0];
	for (i = 0; i < 3; i++) {
		if (min_burger >= burger[i])
			min_burger = burger[i];
	}

	min_ade = ade[0] < ade[1] ? ade[0] : ade[1];

	printf("%d", min_ade + min_burger - 50);
	return 0;
}