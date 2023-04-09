#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int M, N;
ll arr[21];
int table[(1 << 21)][21];

int DP(int state, int now, ll val);

void solve() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a] -= c; arr[b] += c;
	}

	int init = 0;
	for (int i = 0; i < M; i++) if (arr[i] == 0) init |= (1 << i);

	if (init == (1 << M) - 1) {
		cout << 0;
		return;
	}

	int ans = INF;
	memset(table, -1, sizeof(table));
	for (int i = 0; i < M; i++) {
		if (arr[i] == 0) continue;
		ans = min(ans, DP(init, i, arr[i]));
	}

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

int DP(int state, int now, ll val) {
	if (state == (1 << M) - 1) return 0;
	int& ret = table[state][now];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < M; i++) {
		if ((1 << i) & state) continue;
		if (val * arr[i] > 0) continue;
		if (abs(val) > abs(arr[i])) ret = min(ret, 1 + DP(state ^ (1 << i), now, abs(val + arr[i]) * val / abs(val)));
		else if (abs(val) == abs(arr[i])) {
			int new_state = state + (1 << i) + (1 << now);
			if (new_state == (1 << M) - 1) ret = min(ret, 1);
			else {
				for (int j = 0; j < M; j++) {
					if ((1 << j) & new_state) continue;
					ret = min(ret, 1 + DP(new_state, j, arr[j]));
				}
			}
		}
		else ret = min(ret, 1 + DP(state ^ (1 << now), i, abs(val + arr[i]) * arr[i] / abs(arr[i])));
	}

	return ret;
}