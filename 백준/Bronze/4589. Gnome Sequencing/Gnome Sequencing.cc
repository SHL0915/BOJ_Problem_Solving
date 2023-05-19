#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	cout << "Gnomes:\n";
	for (int i = 0; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a < b && b < c) cout << "Ordered\n";
		else if (a > b && b > c) cout << "Ordered\n";
		else cout << "Unordered\n";
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