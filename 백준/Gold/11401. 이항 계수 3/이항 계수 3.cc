#include <iostream>
using namespace std;

const long long mod = 1000000007;

int N, K;
long long nFact, bFact, ans;
long long exponential[31];

int main(void) {
	cin >> N >> K;
	nFact = 1;
	for (int i = 1; i <= N; i++) nFact = (nFact * i) % mod;
	bFact = 1;
	for (int i = 1; i <= K; i++) bFact = (bFact * i) % mod;
	for (int i = 1; i <= N - K; i++) bFact = (bFact * i) % mod;
	exponential[1] = bFact;
	for (int i = 2; i <= 30; i++) exponential[i] = (exponential[i - 1] * exponential[i - 1]) % mod;
	long long result = 1;
	int bit = 1;
	for (int i = 1; i <= 30; i++) {
		if (bit & (mod - 2))
			result = (result * exponential[i]) % mod;
		bit <<= 1;
	}
	ans = (nFact * result) % mod;
	cout << ans;
	return 0;
}