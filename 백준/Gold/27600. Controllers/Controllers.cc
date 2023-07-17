#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
ll A, B;

void solve() {
	cin >> N;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') A++;
		else B++;
	}
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		ll x, y;
		cin >> x >> y;

		if (x == y) {
			if (A == B) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if ((x * (A - B)) % (x - y) != 0) cout << "NO\n";
			else {
				ll val = (x * (A - B)) / (x - y);
				if (val < -B || val > A) cout << "NO\n";
				else cout << "YES\n";
			}
		}
	}
	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
