#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, L, I;
ll table[40][40];

ll nCr(ll n, ll r);

void solve() {
	cin >> N >> L >> I;

	ll ans = 0;
	I--;
	while (I) {
		ll flag = 0, prev = 0;
		for (ll i = 0; i < N; i++) {
			ll cnt = 0;
			for (ll j = 0; j <= min(L, i); j++) cnt += nCr(i, j);

			if (cnt > I) {
				I -= prev;
				ans += (1LL << (i - 1));
				L--;
				flag = 1;
				break;
			}
			prev = cnt;
		}
		if (flag == 0) {
			I -= prev;
			ans += (1LL << (N - 1));
			L--;
		}
	}

	for (ll i = N - 1; i >= 0; i--) {
		if ((1 << i) & ans) cout << 1;
		else cout << 0;
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

ll nCr(ll n, ll r) {
	if (r == 0 || r == n) return 1;
	else if (table[n][r]) return table[n][r];
	else table[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
	return table[n][r];
}