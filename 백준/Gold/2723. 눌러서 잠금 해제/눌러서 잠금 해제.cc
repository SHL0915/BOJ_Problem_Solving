#include <iostream>
using namespace std;

int N, B;
long long memo[12];
long long combination[12][12];

long long DP(int N);
long long comb(int N, int K);

int main(void) {
	cin >> N;
	long long cal = DP(11);
	for (int i = 0; i < N; i++) {
		cin >> B;
		long long ans = 0;
		for (int j = 1; j < (1 << B); j++) {
			int bit = 1;
			int cnt = 0;
			for (int k = 0; k < B; k++) {
				if (bit & j)
					cnt++;
				bit = bit << 1;
			}			
			ans += memo[cnt];
		}
		cout << ans << '\n';
	}
	return 0;
}

long long DP(int N) {
	if (memo[N] != 0) return memo[N];
	else if (N == 1 || N == 0) memo[N] = 1;
	else {
		for (int i = 1; i <= N; i++) {
			memo[N] += comb(N, i) * DP(N - i);
		}
	}
	return memo[N];
}

long long comb(int N, int K) {
	if (combination[N][K] != 0) return combination[N][K];
	else if (K == 0 || K == N) combination[N][K] = 1;
	else combination[N][K] = comb(N - 1, K - 1) + comb(N - 1, K);
	return combination[N][K];
}