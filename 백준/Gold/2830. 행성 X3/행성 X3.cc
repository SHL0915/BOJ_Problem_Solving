#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
ll cnt[64];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a, bit = 1, idx = 0;
		cin >> a;
		while (bit <= a) {
			if (bit & a) cnt[idx]++;
			idx++;
			bit <<= 1;
		}
	}
	ll ans = 0;
	for (int i = 0; i < 64; i++) ans += (1 << i) * (cnt[i] * (N - cnt[i]));
	cout << ans;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}