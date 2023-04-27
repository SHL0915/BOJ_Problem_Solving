#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	int a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		if (c == 'D') a++;
		else b++;
		if (abs(a - b) >= 2) {
			cout << a << ":" << b;
			return;
		}
	}

	cout << a << ":" << b;
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