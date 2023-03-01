#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000009;

int N, M, K;
int A[1001], B[1001];
ll table[1001][1001][11], psum[1001][1001][11];

void solve() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
	sort(A + 1, A + N + 1);
	sort(B + 1, B + M + 1);

	for (int k = 1; k <= K; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (A[i] > B[j]) {
					if (k == 1) table[i][j][k] = 1;
					else table[i][j][k] = psum[i - 1][j - 1][k - 1];
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				psum[i][j][k] = (psum[i - 1][j][k] + psum[i][j - 1][k] - psum[i - 1][j - 1][k] + table[i][j][k] + mod) % mod;
			}
		}
	}

	cout << psum[N][M][K];
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}