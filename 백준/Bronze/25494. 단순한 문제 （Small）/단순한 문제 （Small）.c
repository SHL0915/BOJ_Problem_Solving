#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T, a, b, c, i; // 테스트 케이스의 수 T, 세 정수 a, b, c
	int count = 0, l, n, m; // 정수 쌍의 개수 count
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d %d", &a, &b, &c);
		count = 0;
		for (l = 1; l <= a; l++) { // 완전탐색을 통해 정수 쌍의 개수를 구한다
			for (m = 1; m <= b; m++) {
				for (n = 1; n <= c; n++) {
					if ((l % m == m % n) && (m % n == n % l))
						count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}