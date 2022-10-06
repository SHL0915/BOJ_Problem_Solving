#include <iostream>
using namespace std;

int N, K;
int memo[5001][5001];

int DP(int N, int K);

int main(void) {
	cin >> N >> K;	
	cout << DP(N, K);
	return 0;
}

int DP(int N, int K) {
	if (K == 1 || N == 0) {
		memo[N][K] = 1;
		return memo[N][K];
	}
	else if (memo[N][K] != 0) return memo[N][K];
	else {
		memo[N][K] = (DP(N - 1, K) % 1000000000 + DP(N, K - 1) % 1000000000) % 1000000000;
		return memo[N][K];
	}
}