#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
ll arr[100005];
ll dp[105];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	ll ans = 0;

	dp[0] = 1;
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		for (; idx <= N && !dp[100]; idx++) {
			for (int j = 100; j >= 0; j--) {
				if(j + arr[idx] <= 100) dp[j + arr[idx]] += dp[j];
			}
		}

		if(dp[100]) ans += (N + 2) - idx;

		for (int j = 0; j <= 100; j++) {
			if (j + arr[i] <= 100) {
				dp[j + arr[i]] -= dp[j];				
			}
		}
	}

	cout << ans;
}

int main(void) {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}