#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000009;

int N;
ll table[500001];

void solve() {
	cin >> N;
	table[1] = 1;
	for (ll i = 2; i <= N; i++) table[i] = ((2 * i - 1) * table[i - 1]) % mod;
	cout << table[N];
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