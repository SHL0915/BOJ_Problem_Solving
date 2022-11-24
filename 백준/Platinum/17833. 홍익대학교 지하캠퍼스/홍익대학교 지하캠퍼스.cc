#include <bits/stdc++.h>
using namespace std;
typedef pair<long, int> pli;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (pli A, pli B) {
		return A.first > B.first;
	}
};

int N, R, D, M;
vector <pli> graph[2001];
long long dist[2001];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> R >> D >> M;
	for (int i = 0; i < M; i++) {
		int H, E1, E2;
		long long T;
		cin >> H >> T >> E1 >> E2;
		for (int j = 0; j <= N - H; j++) {
			graph[E1 + j].push_back({ T, E2 + j });
			graph[E2 + j].push_back({ T, E1 + j });
		}
	}
	Dijkstra(R);
	if (dist[D] == INF) cout << -1;
	else cout << dist[D];
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pli, vector<pli>, cmp> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		int now = pq.top().second;
		long long val = pq.top().first;
		pq.pop();
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			long long new_val = val + graph[now][i].first;
			if (dist[next] > new_val) {
				dist[next] = new_val;
				pq.push({ new_val, next });
			}
		}
	}
}