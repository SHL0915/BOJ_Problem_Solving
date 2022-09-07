#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, temp, count = 0, sum = 0, i; // 정수 N, N의 자릿수 count, 새로운 수의 자릿수 sum
	scanf("%d", &N);
	temp = N;
	while (temp != 0) { // N의 자릿수 구하기
		temp = temp / 10;
		count++;
	}
	temp = 1;
	for (i = 0; i < count; i++) { // N-1자릿수 까지 (i자릿수의 개수) * (i)만큼 누적하여 더해준다
		sum += 9 * temp * (i + 1);
		temp = temp * 10;
	}
	sum += (N - temp + 1) * i;	// N자릿수의 개수 * N을 더해준다
	printf("%d", sum);
}