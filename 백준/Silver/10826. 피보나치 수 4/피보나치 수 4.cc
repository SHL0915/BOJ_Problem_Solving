#include <iostream>
using namespace std;

int n;

int fib[10001][2101];

int main(void) {
	cin >> n;
	fib[1][2100] = 1;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2100; j >= 1; j--) {
			fib[i][j] += (fib[i - 1][j] + fib[i - 2][j]);
			fib[i][j - 1] += (fib[i][j] / 10);
			fib[i][j] = fib[i][j] % 10;
		}
	}
	int flag = 0;
	for (int i = 0; i < 2101; i++) {
		if (fib[n][i] != 0) flag = 1;
		if (flag == 1) cout << fib[n][i];
	}
	return 0;
}