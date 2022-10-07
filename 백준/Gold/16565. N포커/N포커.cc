#include <iostream>
using namespace std;

const int mod = 10007;

int N;
int combination[53][53];
int memo[53];

int comb(int N, int K);
int DP(int N);

int main(void) {
	cin >> N;	
	cout << DP(N);		
	return 0;
}

int comb(int N, int K) {
	if (combination[N][K] != 0) return combination[N][K];
	else if (K == 0 || K == N) combination[N][K] = 1;
	else combination[N][K] = (comb(N - 1, K - 1) + comb(N - 1, K)) % mod;
	return combination[N][K];
}

int DP(int N) {
	if (N < 4) return 0;
	else if (memo[N] != 0) return memo[N];
	else if (N == 4) memo[N] = 13;
	else {
		for (int i = 1; i <= N / 4; i++) {
			if (i % 2 == 1) {
				memo[N] += (comb(13, i) % mod * ((comb(52 - i * 4, N - i * 4) % mod) % mod)) % mod;
				memo[N] = memo[N] % mod;
			}
			else {
				memo[N] -= (comb(13, i) % mod * ((comb(52 - i * 4, N - i * 4) % mod) % mod)) % mod;
				memo[N] = (memo[N] + mod) % mod;
			}
		}
	}	
	return memo[N];
}