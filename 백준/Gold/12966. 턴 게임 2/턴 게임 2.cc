#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll x, y;

void solve() {
	cin >> x >> y;

	int flag = 0;
	ll pos = 0;

	for (ll i = 0; i * i <= x + y; i++) {
		if (i * i == x + y) {
			flag = 1;
			pos = i;
		}
	}

	if (flag == 0 || x == 2 || y == 2) {
		cout << -1;
		return;
	}

	if (x == 0) {
		cout << 0;
		return;
	}

	ll cnt = 0;

	for (ll i = pos; i >= 1; i--) {
		ll now = i * 2 - 1;
		if (x >= now) {
			if (x - now != 2) {
				x -= now;
				cnt++;
			}
		}
	}

	cout << cnt;
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