#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
ll table[1001][3][3][3][2];

ll DP(int now, int adj, int prev_h, int now_h, int check);

void solve() {
	cin >> N;
	memset(table, -1, sizeof(table));
	cout << DP(2, 0, 0, 0, 0);
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

ll DP(int now, int adj, int prev_h, int now_h, int check) {
	if (adj > 2) return 0;
	if (prev_h == 2 && now_h == 2) return 0;
	if (now == N + 1) return (check == 1);
	ll& ret = table[now][adj][prev_h][now_h][check];
	if (ret != -1) return ret;
	ret = 0;
	ret += DP(now + 1, 0, now_h, 0, check);
	ret %= mod;

	ret += DP(now + 1, adj + 1, now_h, 1, check);
	ret %= mod;

	ret += DP(now + 1, adj + 1, now_h, 2, 1);
	ret %= mod;

	return ret;
}