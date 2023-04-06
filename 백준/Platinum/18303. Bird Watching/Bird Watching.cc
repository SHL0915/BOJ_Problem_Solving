#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, T;
vector <int> graph[100001];
set <int> mark[100001];

void DFS(int node, int par, int start);

void solve() {
	cin >> N >> M >> T;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	mark[T].insert(0); mark[T].insert(1);
	for (int i = 0; i < graph[T].size(); i++) DFS(graph[T][i], graph[T][i], graph[T][i]);
	
	vector <int> ans;
	for (int i = 0; i < graph[T].size(); i++) {
		if (mark[graph[T][i]].size() == 1) ans.push_back(graph[T][i]);
	}

	sort(ans.begin(), ans.end());

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

void DFS(int node, int par, int start) {
	if (mark[node].count(start)) return;
	if (mark[node].size() == 2) return;
	mark[node].insert(start);

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		DFS(next, node, start);
	}
	return;
}