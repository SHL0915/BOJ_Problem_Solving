#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, pair<int, int>> plii;
typedef pair<pair<int, int>, int> piii;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (plii A, plii B) {
		return A.first > B.first;
	}
};

int M, N, K, S, E;
vector <pair<long long, int>> graph[30000];
vector <int> path[30000];
long long dist[30000];
set <piii> forbidden;
set <pair<int, int>> edge;

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> K;
	cin >> S >> E;
	for (int i = 0; i < M; i++) {
		int x, y;
		long long c;
		cin >> x >> y >> c;
		graph[x].push_back({ c,y });
		edge.insert({ x,y });
	}
	for (int i = 0; i < K; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		forbidden.insert({ {x,y},z });
	}
	Dijkstra(S);
	if (S == E) cout << 0;
	else if (dist[E] == INF) cout << -1;
	else cout << dist[E];
	return 0;
}

void Dijkstra(int start) {
	for (int i = 0; i < N; i++) dist[i] = INF;
	priority_queue<plii, vector<plii>, cmp> pq;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i].second;		
		long long new_val = graph[start][i].first;
		if (dist[next] > new_val) {
			dist[next] = new_val;
			edge.erase({ start, next });
			pq.push({ new_val, {next, start} });
		}
	}	
	while (pq.size()) {
		int now = pq.top().second.first;	
		int prev = pq.top().second.second;
		long long val = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			if (edge.count({ now, next }) == 0) continue;
			if (forbidden.count({ {prev, now},next }) != 0) continue;
			edge.erase({ now,next });
			long long new_val = val + graph[now][i].first;
			dist[next] = min(dist[next], new_val);
			pq.push({ new_val, {next, now} });
		}
	}
}