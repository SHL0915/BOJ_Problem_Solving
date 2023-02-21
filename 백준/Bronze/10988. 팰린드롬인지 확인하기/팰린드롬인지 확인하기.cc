#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
	cin >> S;
	int l = 0, r = S.length() - 1;
	while (l < r) {
		if (S[l] != S[r]) {
			cout << 0;
			return;
		}
		l++; r--;
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