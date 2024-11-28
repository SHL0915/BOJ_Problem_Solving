#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int arr[305];
int table[305][305];

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	memset(table, -1, sizeof(table));
	table[0][0] = 0;

	int ans = 0;

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < K; k++) {
				if (table[i - 1][k] != -1) {
					table[i][(k + arr[j]) % K] = max(table[i][(k + arr[j]) % K], table[i - 1][k] + (k + arr[j]) / K);
				}
			}
		}
	}

	for (int i = 1; i <= M; i++) ans = max(ans, K * table[i][0]);

	cout << ans;

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