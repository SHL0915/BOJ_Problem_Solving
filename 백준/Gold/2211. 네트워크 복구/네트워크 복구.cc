#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <pii> graph[1001];
int dist[1001];
int path[1001];

void Dijkstra(int start);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	Dijkstra(1);

	vector <pii> ans;
	for (int i = 2; i <= N; i++) ans.push_back({ i, path[i] });
	
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << '\n';
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
		int val = t.first;
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_val = graph[now][i].second + val;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				path[next] = now;
				pq.push({ next_val, next });
			}
		}
	}
	return;
}