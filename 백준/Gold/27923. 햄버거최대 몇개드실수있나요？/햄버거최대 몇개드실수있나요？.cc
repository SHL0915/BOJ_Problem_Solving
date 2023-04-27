#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, L;
ll arr[200005];
ll psum[200005];

void solve() {
	cin >> N >> K >> L;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		psum[a] ++;
		psum[min(N + 1, a + L)]--;
	}

	for (int i = 1; i <= N; i++) psum[i] += psum[i - 1];

	sort(psum + 1, psum + N + 1);

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += arr[i] / (1LL << min(psum[i + 1], 50LL));
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