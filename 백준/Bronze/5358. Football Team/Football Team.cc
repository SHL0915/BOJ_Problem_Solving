#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
	while (getline(cin, S)) {
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == 'i') cout << 'e';
			else if (S[i] == 'e') cout << 'i';
			else if (S[i] == 'I') cout << 'E';
			else if (S[i] == 'E') cout << 'I';
			else cout << S[i];
		}
		cout << '\n';
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