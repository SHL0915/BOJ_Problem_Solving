#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector <pii> graph[50001];
map <int, int> mark[50001];
set <int> er[50001];
int check[50001], visited[50001];
pii record[50001];
map <pii, int> dir;
vector <int> ans;

void DFS(int node, int par, int ff, int ss);

void solve() {
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
		mark[a][c]++;
		mark[b][c]++;
		if (mark[a][c] >= 2) er[a].insert(c);
		if (mark[b][c] >= 2) er[b].insert(c);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int now = graph[i][j].first;
			int col = graph[i][j].second;
			if (er[i].count(col) == 0) continue;
			if (check[now] == 1) {
				if (dir[{i,now}] == -1) DFS(record[now].second, record[now].first, record[now].second, record[now].first);
			}
			else DFS(now, i, now, i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';

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

void DFS(int node, int par, int ff, int ss) {
	if (check[node] == 1) return;
	check[node] = 1;
	dir[{par, node}] = 1;
	dir[{node, par}] = -1;
	record[node] = { ff,ss };
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i].first;
		if (now == par) continue;
		DFS(now, node, ff, ss);
	}
	return;
}