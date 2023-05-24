#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, Q;
ll arr[105];
ll table[10005];

ll DP(ll now);

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	pii min_val = { 1, arr[1] };
	for (int i = 1; i <= N; i++) {
		if (arr[i] * min_val.first < min_val.second * i) min_val = { i, arr[i] };
	}

	memset(table, -1, sizeof(table));

	for (int i = 0; i < Q; i++) {
		ll a; cin >> a;

		if (a <= N * N) cout << DP(a) << '\n';
		else {
			ll ans = 0;
			a -= N * N;
			ans += min_val.second * (a / min_val.first);
			
			a %= min_val.first;
			if (a) {
				a -= min_val.first;
				ans += min_val.second;
			}

			a += N * N;
			ans += DP(a);

			cout << ans << '\n';
		}
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

ll DP(ll now) {
	if (now <= N) return table[now] = arr[now];
	ll& ret = table[now];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 1; i <= N; i++) ret = min(ret, arr[i] + DP(now - i));
	
	return ret;
}