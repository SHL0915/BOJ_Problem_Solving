#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1234567890;

struct cmp {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		return A.first > B.first;
	}
};

int N, M, S, D;
vector <pair<int, int>> graph[501];
int dist[501], mark[501];
vector <int> path[501];

void Dijkstra(int start);
void Deleting();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 0; i < N; i++) {
			graph[i].clear();
			mark[i] = 0;
			path[i].clear();
		}		
		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			int U, V, P;
			cin >> U >> V >> P;
			graph[U].push_back({ V,P });
		}
		Dijkstra(S);
		Deleting();		
		Dijkstra(S);
		if (dist[D] == INF) cout << -1 << '\n';
		else cout << dist[D] << '\n';
	}
	return 0;
}

void Dijkstra(int start) {
	for (int i = 0; i < N; i++) dist[i] = INF;
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		pair<int, int> t = pq.top();
		pq.pop();
		int now = t.second;
		int val = t.first;
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			if (graph[now][i].second == -1) continue;
			int next_val = val + graph[now][i].second;
			if (dist[next] > next_val) {
				path[next].clear();
				path[next].push_back(now);
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
			else if (dist[next] == next_val) path[next].push_back(now);
		}
	}
}

void Deleting() {
	queue <int> q;
	q.push(D);
	while (q.size()) {
		int now = q.front();
		q.pop();
		if (mark[now] != 0) continue;
		mark[now] = 1;
		for (int i = 0; i < path[now].size(); i++) {
			int prev = path[now][i];
			for (int j = 0; j < graph[prev].size(); j++) {
				if (graph[prev][j].first == now) graph[prev][j].second = -1;
			}
			q.push(prev);
		}
	}
}