#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int N, M;
	int i, broken, min, temp, count;
	int flag;
	int Arr[10] = { 0 };
	int channel;

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &broken);
		Arr[broken] = 1;
	}

	if (N == 100) 
		min = 0;	
	else if (N < 100) {
		min = 100 - N;
		for (i = 0; i <= 100; i++) {
			count = 0;
			flag = 0;
			temp = i;
			if (temp == 0) {
				if (Arr[0] == 0)
					count++;
				else {
					flag = 1;
				}
			}
			while (temp != 0) {
				if (Arr[temp % 10] == 1) {
					flag = 1;
					break;
				}
				temp = temp / 10;
				count++;
			}
			if (flag == 1)
				continue;			
			if (N >= i) {
				if ((N - i) + count < min) {
					min = N - i + count;
					channel = i;
				}
			}
			else {
				if ((i - N) + count < min) {
					min = i - N + count;
					channel = i;
				}
			}
		}
	}
	else {
		min = N - 100;
		for (i = 101; i <= 2*N; i++) {
			count = 0;
			flag = 0;
			temp = i;
			if (temp == 0) {
				if (Arr[0] == 0)
					count++;
				else {
					flag = 1;
				}
			}
			while (temp != 0) {
				if (Arr[temp % 10] == 1) {					
					flag = 1;
					break;
				}
				temp = temp / 10;
				count++;
			}
			if (flag == 1)
				continue;
			if (N >= i) {
				if ((N - i) + count < min) 
					min = N - i + count;					
			}
			else {
				if ((i - N) + count < min)
					min = i - N + count;
			}
		}
	}

	printf("%d", min);

}