#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long N, M, S, T, C;
vector <pair<long long, long long>> graph[100001];
long long candy[100001];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	cin >> S >> T >> C;
	for (int i = 0; i < M; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		graph[u].push_back({ v,p });
		graph[v].push_back({ u,p });
	}
	Dijkstra(S);
	cout << candy[T];
	return 0;
}

void Dijkstra(int start) {
	priority_queue <pair<long long, long long>> pq;
	candy[start] = C;
	pq.push({ C,start });
	while (pq.size()) {
		long long val = pq.top().first;
		long long idx = pq.top().second;
		pq.pop();
		if (val < candy[idx]) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			long long temp = (val * (100 - graph[idx][i].second)) / 100;
			if (candy[graph[idx][i].first] < temp) {
				candy[graph[idx][i].first] = temp;
				pq.push({ temp, graph[idx][i].first });
			}
		}
	}
}