#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Arr[1000001] = { 0 };

int dp(int n) {
	int temp1, temp2, temp3;
	if (n == 1)
		return Arr[n];
	else if (Arr[n] != 0)
		return Arr[n];
	else {
		if (n % 3 == 0) {
			temp3 = dp(n / 3);
			if (n % 2 == 0) {
				temp2 = dp(n / 2);
				if (temp3 <= temp2)
					Arr[n] = temp3 + 1;
				else
					Arr[n] = temp2 + 1;
			}
			else {
				temp1 = dp(n - 1);
				if (temp1 <= temp3)
					Arr[n] = temp1 + 1;
				else
					Arr[n] = temp3 + 1;
			}
		}
		else {
			temp1 = dp(n - 1);
			if (n % 2 == 0) {
				temp2 = dp(n / 2);
				if (temp1 <= temp2)
					Arr[n] = temp1 + 1;
				else
					Arr[n] = temp2 + 1;
			}
			else
				Arr[n] = temp1 + 1;
		}
	}
	return Arr[n];
}

int main(void) {
	int N;

	Arr[2] = 1;
	Arr[3] = 1;

	scanf("%d", &N);
	printf("%d", dp(N));
	return 0;
}