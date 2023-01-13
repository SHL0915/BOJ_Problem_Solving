#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, M, D, E;
ll arr[100001];
vector <pll> graph[100001];
ll dist[100001][2];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	Dijkstra(1);
	if (dist[N][1] == INF) cout << "Impossible";
	else cout << -dist[N][1] + E;
	return 0;
}

void Dijkstra(int start) {
	priority_queue <pair<pll, int>, vector<pair<pll, int>>, greater<>> pq;
	memset(dist, INF, sizeof(dist));
	dist[start][0] = 0;
	pq.push({ {0, start}, 0 });
	while (pq.size()) {
		int now = pq.top().first.second;
		ll val = pq.top().first.first;
		int mode = pq.top().second;
		pq.pop();
		if (dist[now][mode] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_mode;
			ll next_val = val + graph[now][i].second * D;
			if (arr[next] == arr[now]) continue;
			if (mode) {
				if (arr[next] > arr[now]) continue;
				next_mode = 1;
			}
			else {
				if (arr[next] > arr[now]) {
					next_val -= (arr[next] - arr[now]) * E;
					next_mode = 0;
				}
				else next_mode = 1;
			}
			if (dist[next][next_mode] > next_val) {
				dist[next][next_mode] = next_val;
				pq.push({ {next_val, next}, next_mode });
			}
		}
	}
}