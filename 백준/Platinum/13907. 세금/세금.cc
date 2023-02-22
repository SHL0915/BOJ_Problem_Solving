#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f;

int N, M, K, S, D;
vector <pii> graph[1001];
ll dist[1001][1001];

void Dijkstra(int start);

void solve() {
	cin >> N >> M >> K >> S >> D;
	for (int i = 0; i < M; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ b,w });
		graph[b].push_back({ a,w });
	}

	Dijkstra(S);
	for (int i = 1; i <= N; i++) dist[D][i] = min(dist[D][i], dist[D][i - 1]);
	cout << dist[D][N] << '\n';

	ll sum = 0;
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		sum += a;
		ll ans = INF;
		for (int j = 0; j <= N; j++) ans = min(ans, dist[D][j] + sum * j);
		cout << ans << '\n';
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

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pair<ll, pii>, vector <pair<ll, pii>>, greater<>> pq;
	dist[start][0] = 0;
	pq.push({ 0,{start, 0} });
	while (pq.size()) {
		int now = pq.top().second.first;
		int cnt = pq.top().second.second;
		ll val = pq.top().first;
		pq.pop();
		if (cnt >= N) continue;
		if (dist[now][cnt] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll next_val = val + graph[now][i].second;
			int next_cnt = cnt + 1;
			if (dist[next][next_cnt] > next_val) {
				dist[next][next_cnt] = next_val;
				pq.push({ next_val, {next, next_cnt} });
			}
		}
	}
	return;
}