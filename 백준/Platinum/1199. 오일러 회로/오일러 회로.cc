#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int degree[1005];
vector <int> graph[1005];
int adj[1005][1005];

void DFS(int node);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> adj[i][j];
			degree[i] += adj[i][j];
			if (adj[i][j]) graph[i].push_back(j);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2) {
			cout << -1;
			return;
		}
	}

	DFS(1);

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
	while (graph[node].size()) {
		int next = graph[node].back();
		if (adj[node][next] == 0) {
			graph[node].pop_back();
			continue;
		}
		adj[node][next]--;
		adj[next][node]--;
		DFS(next);
	}
	
	cout << node << " ";
	return;
}