#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int N, K;
int table[11][100001];
long long ans[11];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) table[1][i] = 1;
	ans[1] = K;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			long long sum = 0;
			for (int k = j * 2; k <= K; k += j) sum = (sum + table[i - 1][k]) % mod;
			table[i][j] = (ans[i - 1] - sum + mod) % mod;
			ans[i] = (ans[i] + table[i][j]) % mod;
		}
	}
	cout << ans[N];
	return 0;
}