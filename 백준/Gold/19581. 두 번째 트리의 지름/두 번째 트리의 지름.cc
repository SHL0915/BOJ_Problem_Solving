#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, a, b;
vector <pii> graph[100001];
ll ans;

pii DFS(int node, int par, int type);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	a = DFS(1, -1, 0).second;
	b = DFS(a, -1, 0).second;	
	ans = max(DFS(a, -1, 1).first, DFS(b, -1, 2).first);
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

pii DFS(int node, int par, int type) {
	vector <pii> sub;
	sub.push_back({ 0,node });
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		if (next == par) continue;
		if (type == 1 && next == b) continue;
		if (type == 2 && next == a) continue;
		pii dfs = DFS(next, node, type);
		sub.push_back({ graph[node][i].second + dfs.first , dfs.second });
	}
	sort(sub.begin(), sub.end(), greater<>());
	return sub[0];
}