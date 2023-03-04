#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1001113;

int K, N, V;
int table[101][101];

int DP(int pos, int k);

void solve() {
	cin >> K >> N >> V;
	memset(table, -1, sizeof(table));
	cout << K << " " << DP(1, 0) << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int pos, int k) {
	if (pos == N) return (k == V);
	int& ret = table[pos][k];
	if (ret != -1) return ret;
	ret = 0;
	ret += (pos - k) * DP(pos + 1, k + 1);
	ret += (k + 1) * DP(pos + 1, k);
	ret %= mod;
	return ret;
}