#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Euclid(int A, int B); // 유클리드 호제법을 사용한 최대공약수 판별

int main(void) {
	int N, S, i, data, GCD; // 동생의 수 N, 수빈의 위치 S, 최대공약수 GCD
	int* Arr; // 동생과의 간격을 저장하는 배열 Arr
	scanf("%d %d", &N, &S);
	Arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) { // 동생과 수빈의 간격을 저장
		scanf("%d", &data);
		if (data > S)
			Arr[i] = data - S;
		else
			Arr[i] = S - data;
	}
	GCD = Arr[0];
	for (i = 0; i < N; i++) { // 최대공약수를 0이 아닌 값으로 초기화
		if (GCD == 0)
			GCD = Arr[i];
		else
			break;
	}
	for (i = 0; i < N; i++) { // 간격들의 최대공약수를 구함
		if (Arr[i] == 0)
			continue;
		else {
			GCD = Euclid(GCD, Arr[i]);
		}
	}
	printf("%d", GCD);
	return 0;	
}

int Euclid(int A, int B) {
	if (A == B)
		return A;
	else if (A > B) {
		if (A % B == 0)
			return B;
		else
			return Euclid(A % B, B);
	}
	else {
		if (B % A == 0)
			return A;
		else
			return Euclid(B % A, A);
	}
}