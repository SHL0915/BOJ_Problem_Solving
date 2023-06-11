#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
	cin >> S;
	int a = 0, b = 0, idx = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '0') a++;
		else b++;		
	}

	if (a == b) {
		cout << ((int)(S[0] - '0') ^ 1);
		for (int i = 1; i < S.length(); i++) cout << S[0];
	}
	else {
		if (a > b) {
			for (int i = 0; i < S.length(); i++) cout << 1;
		}
		else {
			for (int i = 0; i < S.length(); i++) cout << 0;
		}
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