#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pli;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (pli A, pli B) {
		return A.first > B.first;
	}
};

int N, M, x, z, P;
int arr[100001];
long long ans = INF;
vector <pli> graph[100001];
long long dist[100001];
long long x_P_dist[100001];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
		graph[v].push_back({ w,u });
	}
	cin >> x >> z;
	cin >> P;
	for (int i = 0; i < P; i++) cin >> arr[i];
	Dijkstra(x);
	for (int i = 1; i <= N; i++) x_P_dist[i] = dist[i];
	Dijkstra(z);
	for (int i = 0; i < P; i++) ans = min(ans, x_P_dist[arr[i]] + dist[arr[i]]);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void Dijkstra(int start) {
	for (int i = 0; i <= N; i++) dist[i] = INF;
	priority_queue <pli, vector<pli>, cmp> pq;
	dist[start] = 0;
	pq.push({ 0,start });
	while (pq.size()) {
		int now = pq.top().second;
		long long val = pq.top().first;
		pq.pop();
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			long long next_val = val + graph[now][i].first;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
}