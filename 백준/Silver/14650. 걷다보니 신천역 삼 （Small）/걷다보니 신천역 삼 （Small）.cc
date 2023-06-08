#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000009;

int N;

void solve() {
	cin >> N;
	if (N == 1) cout << 0;
	else {
		ll ans = 2;
		for (int i = 0; i < N - 2; i++) {
			ans *= 3;
			ans %= mod;
		}
		cout << ans;
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