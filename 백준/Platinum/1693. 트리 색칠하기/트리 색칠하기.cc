#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
vector <int> graph[100001];
ll table[100001][21];

ll DFS(int node, int par, int color);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	memset(table, -1, sizeof(table));
	ll ans = INF;
	for (int i = 1; i <= 20; i++) ans = min(ans, DFS(1, -1, i));
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

ll DFS(int node, int par, int color) {
	ll& ret = table[node][color];
	if (ret != -1) return ret;
	ret = color;
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i];
		if (now == par) continue;
		ll val = INF;
		for (int j = 1; j <= 20; j++) {
			if (j == color) continue;
			val = min(val, DFS(now, node, j));
		}
		ret += val;
	}
	return ret;
} 