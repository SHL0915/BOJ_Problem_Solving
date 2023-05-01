#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 123456789;

int L, S;
ll table[1000005];
ll psum[1000005];

void solve() {
	cin >> L >> S;
	table[0] = 1;
	psum[0] = 1;
	for (int i = 1; i <= L; i++) {
		int idx = max(0, i - S);
		if (idx == 0) table[i] = psum[i - 1];
		else table[i] = (psum[i - 1] - psum[idx - 1] + mod) % mod;
		psum[i] = (psum[i - 1] + table[i]) % mod;
	}

	ll ans = 0;
	for (int i = 1; i <= S; i++) ans = (ans + (table[L - i] * i) % mod) % mod;
	
	cout << ans;
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