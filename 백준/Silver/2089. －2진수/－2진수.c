#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long N, i; // 10진법으로 표현된 수 N;	
	long long temp, count = 0;
	int Arr[100];
	scanf("%lld", &N);	
	if (N == 0) {
		printf("0");
		return 0;
	}
	temp = N;
	while (temp != 0) {
		if (temp % (-2) == 0) {
			Arr[count] = 0;
			count++;
			temp = temp / (-2);
		}
		else {
			Arr[count] = 1;
			count++;
			temp = (temp - 1) / (-2);
		}
	}
	for (i = count - 1; i >= 0; i--)
		printf("%d", Arr[i]);
	return 0;
}
