#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (i < S.length() - 2) {
			if (S[i] + S[i + 1] + S[i + 2] == 'R' + 'B' + 'L') {
				cout << 'C';
				i += 2;
				continue;
			}
		}
		if (S[i] == 'R') cout << 'S';
		else if (S[i] == 'B') cout << 'K';
		else cout << 'H';
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