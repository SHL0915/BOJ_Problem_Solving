#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, K;
vector <pii> graph[3005];
int adj[3005][3005];
int dist[3005];
int arr[3005];

void Dijkstra();

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
		adj[a][b] = c;
		adj[b][a] = c;
	}

	for (int i = 0; i < K; i++) cin >> arr[i];

	Dijkstra();

	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, dist[i]);

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (adj[i][j] == 0) continue;
			ans = max(ans, (dist[i] + dist[j] + adj[i][j] + 1) / 2);
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
	cout << fixed;
	cout.precision(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void Dijkstra() {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector<pii>, greater<>> pq;

	for (int i = 0; i < K; i++) {
		dist[arr[i]] = 0;
		pq.push({ 0, arr[i] });
	}

	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		int now = t.second;
		int cost = t.first;
		if (dist[now] < cost) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_cost = cost + graph[now][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
	return;
}