#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[200005];
set <int> s[200005];
int degree[200005];
int mark[200005];

void DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		s[a].insert(b);
		s[b].insert(a);
		degree[a]++;
		degree[b]++;
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2 == 0) continue;
		ans++;
		DFS(i);
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) continue;
		if (degree[i] % 2 == 0 && mark[i] == 0) {
			ans++;
			DFS(i);
		}
	}

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

void DFS(int node) {
	mark[node] = 1;

	while (graph[node].size()) {
		int next = graph[node].back(); graph[node].pop_back();
		if (s[node].count(next) == 0) continue;
		degree[node]--;
		degree[next]++;
		s[node].erase(next);
		s[next].erase(node);
		DFS(next);
		break;
	}
	
	return;
}