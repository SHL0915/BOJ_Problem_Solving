#include <iostream>
using namespace std;

const long long mod = 1000000007;
int N, K;
long long ans;
long long factorial[4000001];
long long ifactorial[4000001];
long long exponential[31];


int main(void) {
	cin >> N >> K;
	factorial[0] = 1;	
	for (int i = 1; i <= N; i++) factorial[i] = (factorial[i - 1] * i) % mod;
	exponential[1] = factorial[N];
	for (int i = 2; i <= 30; i++) exponential[i] = (exponential[i - 1] * exponential[i - 1]) % mod;
	long long result = 1;
	int bit = 1;
	for (int i = 1; i <= 30; i++) {
		if (bit & (mod - 2))
			result = (result * exponential[i]) % mod;
		bit <<= 1;
	}
	ifactorial[N] = result;
	for (int i = N - 1; i >= 0; i--) ifactorial[i] = (ifactorial[i + 1] * (i + 1)) % mod;
	ans = ((factorial[N] * ifactorial[K]) % mod * ifactorial[N - K]) % mod;
	cout << ans;
	return 0;
}