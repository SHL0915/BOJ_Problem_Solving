#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
vector <pair<ll, pii>> graph;
ll dist[501];

void Bellman_Ford(int start);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c, {a,b} });
	}
	Bellman_Ford(1);
	for (int i = 0; i < M; i++) {
		int u = graph[i].second.first;
		int v = graph[i].second.second;
		ll val = graph[i].first;
		if (dist[u] == INF) continue;
		if (dist[v] > dist[u] + val) {
			cout << -1;
			return;
		}
	}
	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
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

void Bellman_Ford(int start) {
	memset(dist, INF, sizeof(dist));
	dist[start] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int u = graph[j].second.first;
			int v = graph[j].second.second;
			ll val = graph[j].first;
			if (dist[u] == INF) continue;
			if (dist[v] > dist[u] + val) dist[v] = dist[u] + val;			
 		}
	}
	return;
}