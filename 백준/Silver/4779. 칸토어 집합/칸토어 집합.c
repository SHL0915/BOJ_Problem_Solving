#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int pow(int N) { // 3의 제곱수 출력
	int i;
	int result = 1;
	for (i = 0; i < N; i++)
		result *= 3;
	return result;	
}

void Cantor(int N, int i) {
	if (N == 0) { // base case: N이 0일때 '-' 출력
		printf("-");
		return;
	}	
	else { 
		if (i / N == 1) // 유형 1: i/N이 1인 경우, 공백 출력
			printf(" ");
		else // 유형 2: i/N이 0 or 2인 경우, 인자로 N/3, i%N 전달.
			Cantor(N / 3, i % N); 
	}
}

int main(void) {	
	int N, i, num;	

	while (scanf("%d",&N) != EOF) { // EOF 전까지 반복			
		num = pow(N);		
		for(i=0;i<num;i++)
			Cantor(num/3, i);
		printf("\n");		
	}
	return 0;
}