#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
const int INF = 0x3f3f3f3f;

int N, T, M, L, ans = INF;
vector <piii> graph[101];
int dist[101][10001];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T >> M >> L;
	for (int i = 0; i < L; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		graph[a].push_back({ b,{c,d} });
		graph[b].push_back({ a,{c,d} });
	}
	Dijkstra(1);
	for (int i = 0; i <= T; i++) if (dist[N][i] <= M) ans = min(ans, dist[N][i]);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <piii, vector<piii>, greater<>> pq;
	pq.push({ 0,{0, start} });
	dist[start][0] = 0;
	while (pq.size()) {
		int money = pq.top().first;
		int time = pq.top().second.first;
		int now = pq.top().second.second;
		pq.pop();
		if (dist[now][time] < money) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_time = time + graph[now][i].second.first;
			int next_money = money + graph[now][i].second.second;
			if (next_time > T) continue;
			if (dist[next][next_time] > next_money) {
				dist[next][next_time] = next_money;
				pq.push({ next_money, {next_time, next} });
			}
		}
	}
}