#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int a1, a0, c, n0;

void solve() {
	cin >> a1 >> a0 >> c >> n0;
	if (a1 > c) {
		cout << 0;
		return;
	}

	if (a1 * n0 + a0 > c * n0) {
		cout << 0;
		return;
	}

	cout << 1;
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