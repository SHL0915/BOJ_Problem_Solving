#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, Q;
int mark[1001];
pii edge[100001];
vector <int> graph[1001];
int del[1001][1001];
pii query[200001];
queue <pii> q;

void BFS();

void solve() {
	cin >> N >> M >> Q;
	for (int i = 1; i <= M; i++) {
		cin >> edge[i].first >> edge[i].second;
		graph[edge[i].first].push_back(edge[i].second);
	}
	for (int i = 0; i < Q; i++) {
		char a;
		int b;
		cin >> a >> b;
		if (a == 'U') {
			del[edge[b].first][edge[b].second] = 1;
			query[i] = { 0, b };
		}
		else query[i] = { 1,b };
	}
	memset(mark, -1, sizeof(mark));
	q.push({ 1,0 });
	while (q.size()) BFS();
	vector <int> ans;
	for (int i = Q - 1; i >= 0; i--) {
		int a = query[i].first, b = query[i].second;
		if (a) ans.push_back(mark[b]);
		else {
			int u = edge[b].first, v = edge[b].second;
			del[u][v] = 0;
			if (mark[u] != -1) q.push({ v, mark[u] + 1 });
			while (q.size()) BFS();
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
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

void BFS() {
	pii f = q.front();
	q.pop();
	int node = f.first;
	int d = f.second;
	if (mark[node] != -1 && mark[node] <= d) return;
	mark[node] = d;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (del[node][next]) continue;
		q.push({ next,d + 1 });
	}
	return;
}