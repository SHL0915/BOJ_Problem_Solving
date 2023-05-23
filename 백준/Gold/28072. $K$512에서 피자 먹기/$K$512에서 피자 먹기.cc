#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int cnt[100005];

void solve() {
	cin >> N >> K;
	int sum = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		sum += a; sum %= K;
		cnt[sum]++;
		ans = max(ans, cnt[sum]);
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