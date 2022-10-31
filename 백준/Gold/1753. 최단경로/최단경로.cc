#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp {
	bool operator() (pair <int, int> A, pair <int, int> B) {
		return A.second > B.second;
	}
};

int V, E, K;
vector <pair<int, int>> graph[20000];
int val[20000];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u - 1].push_back({ v - 1, w });
	}
	Dijkstra(K - 1);
	for (int i = 0; i < V; i++) {
		if (i == K - 1) cout << 0 << "\n";
		else if (val[i] == 0) cout << "INF" << '\n';
		else cout << val[i] << '\n';
	}
	return 0;
}

void Dijkstra(int start) {
	priority_queue <pair <int, int>, vector<pair <int, int>>, cmp> pq;
	for (int i = 0; i < graph[start].size(); i++) {
		if (val[graph[start][i].first] == 0 || val[graph[start][i].first] > graph[start][i].second) {
			val[graph[start][i].first] = graph[start][i].second;
			pq.push({ graph[start][i].first, graph[start][i].second });
		}
	}
	while (pq.size()) {
		int idx, value;
		idx = pq.top().first;
		value = pq.top().second;
		pq.pop();
		if (val[idx] != 0 && val[idx] < value) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			if (graph[idx][i].first == start) continue;
			else {
				if (val[graph[idx][i].first] == 0 || val[graph[idx][i].first] > val[idx] + graph[idx][i].second) {
					val[graph[idx][i].first] = val[idx] + graph[idx][i].second;
					pq.push({ graph[idx][i].first,val[graph[idx][i].first] });
				}
			}
		}
	}
}