#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

struct cmp {
	bool operator() (pii A, pii B) {
		return A.first > B.first;
	}
};

int N, M, S, D;
vector <pii> graph[501];
int dist[501];
vector <int> path[501];
int mark[501];

void Dijkstra(int start);
void Delete_Path(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> D;
		for (int i = 0; i < N; i++) {
			graph[i].clear();
			path[i].clear();
			mark[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int U, V, P;
			cin >> U >> V >> P;
			graph[U].push_back({ V,P });
		}
		Dijkstra(S);
		Delete_Path(D);
		Dijkstra(S);
		if (dist[D] == INF) cout << -1 << '\n';
		else cout << dist[D] << '\n';
	}
	return 0;
}

void Dijkstra(int start) {
	for (int i = 0; i < N; i++) dist[i] = INF;
	priority_queue<pii, vector<pii>, cmp> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (pq.size()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int new_val = val + graph[now][i].second;
			if (dist[next] > new_val) {
				dist[next] = new_val;
				path[next].clear();
				path[next].push_back(now);
				pq.push({ new_val, next });
			}
			else if (dist[next] == new_val) path[next].push_back(now);
		}
	}
}

void Delete_Path(int node) {
	if (mark[node] != 0) return;
	mark[node] = 1;
	for (int i = 0; i < path[node].size(); i++) {
		int now = node;
		int prev = path[node][i];
		for (int j = 0; j < graph[prev].size(); j++) {
			if (graph[prev][j].first == now) graph[prev][j].second = INF;			
		}
		Delete_Path(prev);
	}
}