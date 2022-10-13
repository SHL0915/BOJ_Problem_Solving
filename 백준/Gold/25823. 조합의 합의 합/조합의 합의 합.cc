#include <iostream>
using namespace std;

const long long mod = 1000000007;

int M;
long long ans;
long long factorial[400001];
long long ifactorial[400001];

long long combination(int N, int K);

int main(void) {
	cin >> M;
	factorial[0] = 1;
	for (int i = 1; i <= 2 * M; i++) factorial[i] = (factorial[i - 1] * i) % mod;
	long long temp = factorial[M * 2];
	long long result = 1;
	long long p = mod - 2;
	while (p) {
		if (p & 1) result = (result * temp) % mod;
		temp = (temp * temp) % mod;
		p >>= 1;
	}
	ifactorial[M * 2] = result;
	for (int i = M * 2 - 1; i >= 0; i--) ifactorial[i] = (ifactorial[i + 1] * (i + 1)) % mod;
	for (int i = 3; i <= M; i++) ans = (ans + combination(i * 2, i)) % mod;
	cout << ans;
	return 0;
}

long long combination(int N, int K) {
	return ((factorial[N] * ifactorial[K]) % mod * ifactorial[N - K]) % mod;
}