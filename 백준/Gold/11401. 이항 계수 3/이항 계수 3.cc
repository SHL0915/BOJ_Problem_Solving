#include <iostream>
using namespace std;

const long long mod = 1000000007;

int N, K;
long long nFact, bFact, ans, exponential;

int main(void) {
	cin >> N >> K;
	nFact = 1;
	for (int i = 1; i <= N; i++) nFact = (nFact * i) % mod;
	bFact = 1;
	for (int i = 1; i <= K; i++) bFact = (bFact * i) % mod;
	for (int i = 1; i <= N - K; i++) bFact = (bFact * i) % mod;	
	exponential = bFact;
	long long result = 1;
	int bit = 1;
	for (int i = 1; i <= 30; i++) {
		if (bit & (mod - 2))
			result = (result * exponential) % mod;
		exponential = (exponential * exponential) % mod;
		bit <<= 1;
	}
	ans = (nFact * result) % mod;
	cout << ans;
	return 0;
}