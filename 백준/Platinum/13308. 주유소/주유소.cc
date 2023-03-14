#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
int arr[2501];
vector <pii> graph[2501];
int dist[2501][2501];

void Dijkstra(int start);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	Dijkstra(1);

	int ans = INF;
	for (int i = 0; i <= 2500; i++) ans = min(ans, dist[N][i]);

	cout << ans;
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
	priority_queue <pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
	dist[start][arr[start]] = 0;
	pq.push({ 0, {start, arr[start]} });
	while (pq.size()) {
		pair<int, pii> t = pq.top(); pq.pop();
		int val = t.first;
		int now = t.second.first;
		int cost = t.second.second;
		if (dist[now][cost] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_val = val + cost * graph[now][i].second;
			int next_cost = min(cost, arr[next]);
			if (dist[next][next_cost] > next_val) {
				dist[next][next_cost] = next_val;
				pq.push({ next_val, {next, next_cost} });
			}
		}
	}
	return;
}