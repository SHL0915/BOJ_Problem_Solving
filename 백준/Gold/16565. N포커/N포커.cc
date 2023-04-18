#include <iostream>
using namespace std;

const int mod = 10007;

int N, ans;
int combination[53][53];

int comb(int N, int K);

int main(void) {
	cin >> N;	
	for (int i = 1; i <= N / 4; i++) {
		if (i % 2 == 1) {
			ans += (comb(13, i) * comb(52 - i * 4, N - i * 4)) % mod;
			ans = ans % mod;
		}
		else {
			ans -= (comb(13, i) * comb(52 - i * 4, N - i * 4)) % mod;
			ans = (ans + mod) % mod; // modular계에서 뺄셈을 진행할 때에는 음수가 되는 경우를 고려하여 mod를 더해준다.
		}
	}
	cout << ans;		
	return 0;
}

int comb(int N, int K) {
	if (combination[N][K] != 0) return combination[N][K];
	else if (K == 0 || K == N) combination[N][K] = 1;
	else combination[N][K] = (comb(N - 1, K - 1) + comb(N - 1, K)) % mod;
	return combination[N][K];
}