#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int x, y;
	int date = 0;
	int i;

	scanf("%d %d", &x, &y);

	for (i = 1; i < x; i++) {
		if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 12)) {
			date += 31;
		}
		else if (i == 2)
			date += 28;
		else
			date += 30;
	}

	date += y;

	i = date % 7;

	switch (i) {
	case 1 :
		printf("MON");
		break;
	case 2:
		printf("TUE");
		break;
	case 3:
		printf("WED");
		break;
	case 4:
		printf("THU");
		break;
	case 5:
		printf("FRI");
		break;
	case 6:
		printf("SAT");
		break;
	case 0:
		printf("SUN");
		break;
	}

    return 0;
}