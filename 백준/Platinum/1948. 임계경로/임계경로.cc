#include <bits/stdc++.h>
using namespace std;

int N, M, S, E, cnt;
vector <pair<int, int>> graph[10001];
vector <int> path[10001];
int dist[10001];
int mark[10001][10001];

void Dijkstra(int start);
void DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> S >> E;
	Dijkstra(S);
	cout << dist[E] << '\n';
	DFS(E);
	cout << cnt;
	return 0;
}

void Dijkstra(int start) {
	priority_queue <pair<int, int>> pq;
	pq.push({ 0, start });
	while (pq.size()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (dist[now] > val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int new_val = val + graph[now][i].second;
			if (dist[next] < new_val) {
				path[next].clear();
				path[next].push_back(now);
				dist[next] = new_val;
				pq.push({ new_val, next });
			}
			else if (dist[next] == new_val) path[next].push_back(now);
		}
	}
}

void DFS(int node) {
	if (node == S) return;
	for (int i = 0; i < path[node].size(); i++) {
		if (mark[node][path[node][i]]) continue;
		cnt++;
		mark[node][path[node][i]] = 1;
		DFS(path[node][i]);
	}
	return;
}