#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int operation(int A, int P) {
	int i;
	int result = 0;
	int B;
	int temp = A;

	while(temp != 0){		
		B = temp % 10;
		for (i = 0; i < P - 1; i++) {
			B = B * (temp % 10);
		}
		result += B;
		temp = temp / 10;		
	}

	return result;
}

int main(void) {
	int A, P, k;
	int temp;
	int mark[1000000] = { 0 };

	scanf("%d %d", &A, &P);

	temp = A;
	k = 1;	
	while (mark[temp] == 0) {		
		mark[temp] = k;
		temp = operation(temp, P);
		k++;
	}
	printf("%d", mark[temp] - 1);
	return 0;
}