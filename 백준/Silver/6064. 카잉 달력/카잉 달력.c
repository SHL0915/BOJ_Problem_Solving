#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Euclid(int M, int N) { // 유클리드 호제법으로 최대공약수 구하기
	if (M == N)
		return N;
	else if (M > N) {
		if (M % N == 0)
			return N;
		else
			return Euclid(M % N, N);
	}
	else {
		if (N % M == 0)
			return M;
		else
			return Euclid(N % M, M);
	}
}

int main(void) {
	int T, M, N, x, y, i, k, GCD, LCM; // 테스트케이스 T, 정수 M, N, 최대공약수 GCD, 최소공배수 LCM
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		k = 0;
		GCD = Euclid(M, N);
		LCM = (M * N) / GCD;
		while (1) {			
			if (M * k + x > LCM) {
				printf("-1\n");
				break;
			}
			else{
				if ((M * k + x) % N == 0) {
					if (y == N) {
						printf("%d\n", M * k + x);
						break;
					}
				}
				else {
					if ((M * k + x) % N == y) {
						printf("%d\n", M * k + x);
						break;
					}			
				}				
			}
			k++;
		}
	}
	return 0;
}