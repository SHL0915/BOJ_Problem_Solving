#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1000000009;

int N, M, X, Y;
vector <pii> graph[100001];
ll dist[100001];
ll cnt[100001];
ll table[100001];
vector <int> path[100001];

void Dijkstra(int start);
ll DP(int now);

void solve() {
	cin >> N >> M >> X >> Y;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	Dijkstra(X);

	if (dist[Y] == INF) {
		cout << -1;
		return;
	}

	cout << dist[Y] << '\n';
	cout << cnt[Y] << '\n';
	memset(table, -1, sizeof(table));
	cout << DP(Y) << '\n';
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
	memset(cnt, INF, sizeof(cnt));
	priority_queue <pair<pii, int>, vector<pair<pii, int>>, greater<>> pq;
	dist[start] = 0;
	cnt[start] = 0;
	pq.push({ {0,0}, start });
	while (pq.size()) {
		pair<pii, int> t = pq.top(); pq.pop();
		int now = t.second;
		ll val = t.first.first;
		ll c = t.first.second;
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll new_val = val + graph[now][i].second;
			ll new_cnt = c + 1;
			if (dist[next] > new_val || (dist[next] == new_val) && (cnt[next] > new_cnt)) {
				path[next].clear();
				path[next].push_back(now);
				dist[next] = new_val;
				cnt[next] = new_cnt;
				pq.push({ {new_val, new_cnt}, next });
			}
			else if (dist[next] == new_val && cnt[next] == new_cnt) path[next].push_back(now);
		}
	}
	return;
}

ll DP(int now) {
	if (now == X) return 1;
	ll& ret = table[now];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < path[now].size(); i++) {
		int next = path[now][i];
		ret += DP(next);
		ret %= mod;
	}
	return ret;
}