#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
vector <pair<pii, ll>> graph;
ll dist[101];
vector <int> path[101];
vector <int> ans;

void Bellman_Ford(int start);
void Find(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		c *= -1;
		graph.push_back({ {a,b},c });
	}
	Bellman_Ford(1);
	if (dist[N] == INF) {
		cout << -1;
		return;
	}
	ll a = dist[N];
	for (int i = 0; i < 20 * N; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int a = graph[j].first.first;
			int b = graph[j].first.second;
			ll c = graph[j].second;
			if (dist[a] == INF) continue;
			if (dist[b] > dist[a] + c) {
				path[b].clear();
				path[b].push_back(a);
				dist[b] = dist[a] + c;
			}
			else if (dist[b] == dist[a] + c) path[b].push_back(a);
		}
	}
	if (dist[N] != a) {
		cout << -1;
		return;
	}
	Find(N);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
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
			int a = graph[j].first.first;
			int b = graph[j].first.second;
			ll c = graph[j].second;
			if (dist[a] == INF) continue;
			if (dist[b] > dist[a] + c) {				
				path[b].clear();
				path[b].push_back(a);
				dist[b] = dist[a] + c;
			}
			else if (dist[b] == dist[a] + c) path[b].push_back(a);
		}
	}
}

void Find(int node) {
	ans.push_back(node);
	if (node == 1) return;
	Find(path[node].front());
	return;
}