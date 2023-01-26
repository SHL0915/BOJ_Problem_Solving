#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1000000000;

int N;
int table[(1 << 10)][101][10];

int DP(int state, int pos, int now);

void solve() {
	cin >> N;
	memset(table, -1, sizeof(table));
	int ans = 0;
	for (int i = 1; i < 10; i++) ans = (ans + DP((1 << i), 1, i)) % mod;
	cout << ans;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int state, int pos, int now) {
	if (pos == N) return (state == (1 << 10) - 1);
	int& ret = table[state][pos][now];
	if (ret != -1) return ret;
	ret = 0;
	if (now > 0) ret += DP(state | (1 << (now - 1)), pos + 1, now - 1);
	if (now < 9) ret += DP(state | (1 << (now + 1)), pos + 1, now + 1);
	ret %= mod;
	return ret;
}