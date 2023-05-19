#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < S.length(); j++) {
			if (S[j] >= 'A' && S[j] <= 'Z') cout << (char)(S[j] - 'A' + 'a');
			else cout << S[j];
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