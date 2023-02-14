#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1000000000000000LL;

int N, M, u, v;
vector <pii> graph[801];
ll dist[801][2];

void Dijkstra(int start, int type);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	Dijkstra(1, 0);
	Dijkstra(N, 1);
	cin >> u >> v;
	ll sum = INF;
	for (int i = 0; i < graph[u].size(); i++) {
		if (graph[u][i].first == v) sum = min(sum, graph[u][i].second);
	}
	ll ans = INF;
	ans = min(ans, dist[u][0] + dist[v][1]);
	ans = min(ans, dist[v][0] + dist[u][1]);
	Dijkstra(u, 0);
	ans += dist[v][0];
	if (ans >= INF) cout << -1;
	else cout << ans;
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

void Dijkstra(int start, int type) {
	for (int i = 1; i <= N; i++) dist[i][type] = INF;
	priority_queue <pii, vector<pii>, greater<>> pq;
	dist[start][type] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		int now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if (dist[now][type] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll next_val = graph[now][i].second + val;
			if (dist[next][type] > next_val) {
				dist[next][type] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
	return;
}