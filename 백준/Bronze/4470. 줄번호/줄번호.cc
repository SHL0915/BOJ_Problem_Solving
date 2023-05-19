#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;

void solve() {
	cin >> N;
	getline(cin, S);
	for (int i = 1; i <= N; i++) {
		cout << i << ". ";
		getline(cin, S);
		cout << S << '\n';
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