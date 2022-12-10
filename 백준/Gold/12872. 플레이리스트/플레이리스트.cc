#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int N, M, P;
long long table[101][101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> P;
	table[0][0] = 1;
	for (int i = 1; i <= P; i++) {
		for (int j = 1; j <= N; j++) {
			table[i][j] += (table[i - 1][j - 1] * (N - j + 1)) % mod;
			table[i][j] += (table[i - 1][j] * max(j - M, 0)) % mod;
			table[i][j] %= mod;
		}
	}
	cout << table[P][N];
	return 0;
}