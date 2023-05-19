#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
	int A = 0, B = 0;
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		A += a;
	}
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		B += a;
	}

	cout << max(A, B);
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