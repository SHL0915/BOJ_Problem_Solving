#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long INF = 1000000000000000;

struct cmp {
	bool operator() (pair<long long, int> A, pair<long long, int> B) {
		return A.first > B.first;
	}
};

int N, M, R, D;
vector <pair<int, long long>> graph[2001];
long long dist[2001];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> R >> D;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int H, E1, E2;
		long long T;
		cin >> H >> T >> E1 >> E2;
		for (int j = 0; j <= N - H; j++) {
			graph[E1 + j].push_back({ E2 + j, T });
			graph[E2 + j].push_back({ E1 + j, T });
		}
	}
	Dijkstra(R);
	if (dist[D] == INF) cout << -1;
	else cout << dist[D];
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pair<long long, int>, vector<pair<long long, int>>, cmp> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		pair<long long, int> t = pq.top();
		pq.pop();
		int node = t.second;
		long long val = t.first;
		if (dist[node] < val) continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i].first;
			long long next_val = val + graph[node][i].second;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
}