#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, K;
vector <pii> graph[10001];
ll dist[10001];
vector <int> path[10001];

void Dijkstra(int start);
void DFS(int node);

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	Dijkstra(1);
	DFS(N);

	cout << "no";
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

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector<pii>, greater<>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		int now = t.second;
		ll val = t.first;
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll next_val = val + graph[now][i].second;
			if (dist[next] > next_val) {
				path[next].clear();
				path[next].push_back(now);
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
			else if (dist[next] == next_val) path[next].push_back(now);
		}
	}
	return;
}

void DFS(int node) {
	if (path[node].size() >= 2) {
		cout << "yes";
		exit(0);
	}
	for (int i = 0; i < path[node].size(); i++) DFS(path[node][i]);
	return;
}