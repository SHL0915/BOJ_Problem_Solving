#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, X;
vector <pii> graph[10005];
ll dist[10005];

void Dijkstra(int start, ll limit);

void solve() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	Dijkstra(1, INF);
	ll min_dist = dist[N];

	ll l = 0, r = 1000000000LL;
	while (l < r) {
		ll mid = (l + r) / 2;
		Dijkstra(1, mid);

		if (dist[N] == INF) l = mid + 1;
		else {
			if (dist[N] * 100 > min_dist * (100 + X)) l = mid + 1;
			else r = mid;
		}
	}

	cout << l;
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

void Dijkstra(int start, ll limit) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector<pii>, greater<>> pq;

	pq.push({ 0, start });
	dist[start] = 0;

	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		int now = t.second;
		ll val = t.first;

		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll cost = graph[now][i].second;
			if (cost > limit) continue;
			ll next_val = val + cost;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}

	return;
}