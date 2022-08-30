#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long findNum(long long k) {
	long long count = 1;
	while (count < k) // k보다 작은 최대의 2의 제곱수를 찾는다.
		count = count * 2;
	count = count / 2;		
	return k - count;
}

long long Thue_Morse(long long k) {	
	if (k == 1) // base case 1
		return 0;
	else if (k == 2)
		return 1; // base case 2
	else {		
		return (Thue_Morse(findNum(k)) + 1) % 2; // k - 2의 제곱수의 값을 0/1로 대칭하여 바꿔준다.
	}
}

int main(void) {
	long long k; // 자연수 k
	scanf("%lld", &k);	
	printf("%lld", Thue_Morse(k));
	return 0;
}