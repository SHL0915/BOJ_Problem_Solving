#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
ll arr[50001];
ll psum[50001];
priority_queue <int, vector<int>, greater<>> pq[7];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	pq[0].push(0);

	for (int i = 1; i <= N; i++) {
		psum[i] = psum[i - 1] + arr[i];
		int now = psum[i] % 7;
		pq[now].push(i);

		if (pq[now].size()) {
			ans = max(ans, i - pq[now].top());
		}
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