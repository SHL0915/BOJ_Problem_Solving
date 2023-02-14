#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
int arr[100001];
vector <pii> graph[100001];
ll dist[100001];

void Dijkstra(int start);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	arr[N - 1] = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	Dijkstra(0);
	if (dist[N - 1] == INF) cout << -1;
	else cout << dist[N - 1];
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
		int now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll next_val = val + graph[now][i].second;
			if (arr[next]) continue;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
	return;
}