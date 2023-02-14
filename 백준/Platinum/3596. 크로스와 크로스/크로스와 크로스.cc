#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll table[2001];

void solve() {
	cin >> N;
	for (int i = 1; i <= 3; i++) table[i] = 1;
	table[4] = 2;
	table[5] = 2;
	for (int i = 6; i <= N; i++) {
		vector <int> mex(i + 1);
		mex[table[i - 5]]++;
		mex[table[i - 4]]++;
		mex[table[i - 3]]++;
		for (int j = 1; j < i - 5; j++) mex[table[j] ^ table[i - 5 - j]]++;
		int now = 0;
		while (mex[now]) now++;
		table[i] = now;
	}
	if (table[N]) cout << 1;
	else cout << 2;
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