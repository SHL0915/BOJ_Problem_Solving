#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int C, P, X, L;
vector <int> graph[200005];
int in_degree[200005];
int cnt[200005];
int mark[200005];

void DFS(int node);

void solve() {
	cin >> C >> P >> X >> L;
	for (int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		in_degree[a] ++; in_degree[b] ++;
	}

	DFS(L);

	if (mark[X]) cout << "leave";
	else cout << "stay";

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

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (mark[next]) continue;
		if (++cnt[next] * 2 >= in_degree[next]) DFS(next);
	}
	return;
}