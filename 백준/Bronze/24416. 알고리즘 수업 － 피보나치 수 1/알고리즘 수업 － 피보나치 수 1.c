#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
	if ((n == 1) || (n == 2))
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}


int main(void) {
	int n;

	scanf("%d", &n);

	printf("%d %d", fib(n), n - 2);
	
}