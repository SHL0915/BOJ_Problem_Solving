#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int T;
	int A, B;
	int temp;
	int i,j;
	int result;
	int flag;

	scanf("%d", &T);

	for (j = 0; j < T; j++) {
		result = 1;
		flag = 0;
		scanf("%d %d", &A, &B);

		if (B <= A) {
			temp = B;
			B = A;
			A = temp;
		}

		while (flag == 0) {
			if ((A == 1) || (B == 1)) {
				result = result * A * B;
				break;
			}

			for (i = 2; i <= A; i++) {
				if ((A % i == 0) && (B % i == 0)) {
					result *= i;
					A = A / i;
					B = B / i;
					break;
				}
				else if (i == A) {
					result = result * A * B;
					flag = 1;
				}
			}
		}
		printf("%d\n", result);
	}	
	
	return 0;	
}