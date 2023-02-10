#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[32001];
int in_degree[32001];
queue <int> q;
vector <int> ans;

void Topology();

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		in_degree[b]++;
	}
	Topology();
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
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

void Topology() {
	for (int i = 1; i <= N; i++) if (in_degree[i] == 0) q.push(i);
	for (int i = 1; i <= N; i++) {
		int now = q.front();
		q.pop();
		ans.push_back(now);
		for (int j = 0; j < graph[now].size(); j++) {
			if (--in_degree[graph[now][j]] == 0) q.push(graph[now][j]);
		}
	}
	return;
}