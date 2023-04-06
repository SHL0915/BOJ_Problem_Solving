#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, T, B;
pii S, E;
pii pos[1005];
int cost[101];
vector <pii> graph[1005];
int dist[1005][101];

void Dijkstra(int start);
int cal(pii a, pii b);

void solve() {
	cin >> S.first >> S.second;
	cin >> E.first >> E.second;
	cin >> B;
	cin >> cost[0];
	cin >> T;
	for (int i = 1; i <= T; i++) cin >> cost[i];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pos[i].first >> pos[i].second;
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			graph[i].push_back({ a,b });
			graph[a].push_back({ i,b });
		}
	}

	pos[N] = S; pos[N + 1] = E;

	for (int i = 0; i < N; i++) {
		graph[N].push_back({ i, 0 });
		graph[i].push_back({ N, 0 });
		graph[N + 1].push_back({ i, 0 });
		graph[i].push_back({ N + 1, 0 });
	}
	graph[N].push_back({ N + 1, 0 });
	graph[N + 1].push_back({ N, 0 });

	Dijkstra(N);

	int ans = INF;
	for (int i = 0; i <= B; i++) ans = min(ans, dist[N + 1][i]);

	if (ans == INF) cout << -1;
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

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

	dist[start][0] = 0;
	pq.push({ 0, {start, 0} });

	while (pq.size()) {
		pair<int, pii> t = pq.top(); pq.pop();
		int now = t.second.first;
		int d = t.second.second;
		int val = t.first;
		if (dist[now][d] < val) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int type = graph[now][i].second;
			int dd = cal(pos[now], pos[next]);
			if (d + dd > B) continue;
			int new_val = val + cost[type] * dd;
			if (dist[next][d + dd] > new_val) {
				dist[next][d + dd] = new_val;
				pq.push({ new_val, {next, d + dd} });
			}
		}
	}
	return;
}

int cal(pii a, pii b) {
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	int sqrdist = dx * dx + dy * dy;
	double d = sqrt(sqrdist);
	return ceil(d);
}