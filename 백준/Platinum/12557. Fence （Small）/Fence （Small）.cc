#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll L, N;
ll arr[105];
ll table[10005];

ll DP(ll now);

void solve() {
	cin >> L >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	memset(table, -1, sizeof(table));
	ll ans = 0;

	if (L <= 10000) {
		ans = DP(L);
		if (ans == INF) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}
	else {
		L -= 10000;
		ans += L / arr[N - 1];
		L %= arr[N - 1];

		if (L) {
			L -= arr[N - 1];
			ans++;
		}

		L += 10000;
		if (DP(L) == INF) cout << "IMPOSSIBLE\n";
		else cout << ans + DP(L) << '\n';
	}
	
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1, tc = 1;
	cin >> t;
	while (t--) {
		cout << "Case #" << tc << ": ";
		solve();
		tc++;
	}
	return 0;
}

ll DP(ll now) {
	if (now < 0) return INF;
	if (now == 0) return 0;
	ll& ret = table[now];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < N; i++) ret = min(ret, 1 + DP(now - arr[i]));
	
	return ret;
}