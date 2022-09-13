#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Arr[21][21][21];

int dp(int a, int b, int c) {
	if (((a <= 0) || (b <= 0)) || (c <= 0))
		return Arr[0][0][0];
	else if (((a > 20) || (b > 20)) || (c > 20)) {
		Arr[20][20][20] = dp(20, 20, 20);
		return Arr[20][20][20];
	}
	else if (Arr[a][b][c] == 0) {
		if ((a < b) && (b < c)) {
			Arr[a][b][c] = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c);
			return Arr[a][b][c];
		}
		else {
			Arr[a][b][c] = dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1);
			return Arr[a][b][c];
		}
	}
	else
		return Arr[a][b][c];	
}

int main(void) {
	int a, b, c;
	int i;

	for (a = 0; a <= 20; a++) {
		for (b = 0; b <= 20; b++) {
			for (c = 0; c <= 20; c++)
				Arr[a][b][c] = 0;
		}
	}
	Arr[0][0][0] = 1;


	for (i = 0;; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (((a == -1) && (b == -1)) && (c == -1))
			break;
		else {
			printf("w(%d, %d, %d) = %d\n", a, b, c, dp(a, b, c));
		}
	}
	return 0;
}