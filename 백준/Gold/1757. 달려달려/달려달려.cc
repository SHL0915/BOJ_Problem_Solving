#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
ll arr[10001];
ll table[10001][501][2];

ll DP(int t, int e, int mode);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(1, 0, 0);
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

ll DP(int t, int e, int mode) {
	if (e > M) return -INF;
	if (t == N + 1) {
		if (e) return -INF;
		else return 0;
	}
	ll& ret = table[t][e][mode];
	if (ret != -1) return ret;
	ret = -INF;
	if (mode) {
		ret = max(ret, DP(t + 1, max(e - 1, 0), 1));
		if(e == 0) ret = max(ret, arr[t] + DP(t + 1, 1, 0));		
	}
	else {
		ret = max(ret, arr[t] + DP(t + 1, e + 1, 0));
		ret = max(ret, DP(t + 1, max(e - 1, 0), 1));
	}
	return ret;
}