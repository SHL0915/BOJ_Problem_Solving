#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, Q;

ll arr[505][505];
ll psum[505][505];
ll min_val[505][505];

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}

	memset(min_val, INF, sizeof(min_val));

	for (int i = 1; i <= N; i++) {
		for (int j = N; j >= 1; j--) {
			psum[i][j] = psum[i][j + 1] + arr[i][j];
			min_val[i][j] = psum[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) min_val[i][j] = min(min_val[i][j], min_val[i - 1][j]);
	}

	for (int i = 0; i < Q; i++) {
		int x, y, L;
		cin >> x >> y >> L;

		ll ans = INF, sum = 0;
		for (int j = y; j <= N; j++) {
			ans = min(ans, sum + min_val[max(0, x - L)][j]);
			sum += arr[x][j];
		}

		cout << min(ans, sum) << '\n';
	}

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