#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
	for (int i = 0; i < 3; i++) {
		int a, b, c, d, e, f;
		cin >> d >> e >> f >> a >> b >> c;
		a -= d;
		b -= e;
		c -= f;

		if (c < 0) {
			c += 60;
			b--;
		}

		if (b < 0) {
			b += 60;
			a--;
		}

		cout << a << " " << b << " " << c << '\n';
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