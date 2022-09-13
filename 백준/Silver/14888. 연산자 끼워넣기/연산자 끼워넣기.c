#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min = 1000000000;
int max = -100000000;

void BT(int Number[], int operator[], int N, int k, int result) {
	int i;
	if (k == 0) {
		if (max <= result)
			max = result;
		if (min >= result)
			min = result;
	}
	else {
		for (i = 0; i < 4; i++) {
			if (operator[i] == 0)
				continue;
			else {
				switch (i) {
				case 0: operator[0]--;
					BT(Number, operator,N, k - 1, result + Number[N - k]);
					operator[0]++;
					break;
				case 1: operator[1]--;
					BT(Number, operator,N, k - 1, result - Number[N - k]);
					operator[1]++;
					break;
				case 2: operator[2]--;
					BT(Number, operator,N, k - 1, result * Number[N - k]);
					operator[2]++;
					break;
				case 3: operator[3]--;
					BT(Number, operator,N, k - 1, result / Number[N - k]);
					operator[3]++;
					break;
				}
				
			}
		}
	}
}

int main(void) {
	int N, i;
	int* Number;
	int* operator;	
	scanf("%d", &N);
	Number = (int*)malloc(sizeof(int) * N);
	operator = (int*)malloc(sizeof(int) * 4);

	for (i = 0; i < N; i++)
		scanf("%d", &Number[i]);

	for (i = 0; i < 4; i++)
		scanf("%d", &operator[i]);

	BT(Number, operator,N, N - 1, Number[0]);

	printf("%d\n%d", max, min);
	return 0;
}