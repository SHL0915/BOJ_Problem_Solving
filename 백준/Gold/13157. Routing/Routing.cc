#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int cost[101];
int graph[101][101];
set <int> arr[101][101];
int table[101][101];

int DP(int now, int par);

void solve() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int m, t;
		cin >> m >> t;
		cost[i] = t;
		for (int j = 0; j < m; j++) {
			int s, x;
			cin >> s >> x;
			graph[i][x] = 1;
			for (int j = 0; j < s; j++) {
				int a; cin >> a;
				arr[i][x].insert(a);
			}
		}
	}

	memset(table, -1, sizeof(table));
	int ans = DP(1, 0);
	if (ans == INF) cout << "impossible";
	else cout << ans;
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

int DP(int now, int par) {
	if (now == N) return cost[N];
	int& ret = table[now][par];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 1; i <= N; i++) {
		if (graph[now][i] == 0) continue;
		if (arr[now][i].count(par)) continue;
		ret = min(ret, cost[now] + DP(i, now));
	}

	return ret;
}