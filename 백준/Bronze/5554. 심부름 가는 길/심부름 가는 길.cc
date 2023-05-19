#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int sum;

void solve() {
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		sum += a;
	}

	cout << sum / 60 << '\n' << sum % 60;
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