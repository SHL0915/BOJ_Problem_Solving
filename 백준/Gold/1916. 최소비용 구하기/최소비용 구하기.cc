#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1000000000000;

struct cmp {
	bool operator() (pair <long long, long long> A, pair<long long, long long> B) {
		return A.second > B.second;
	}
};

int N, M, A, B;
vector <pair<long long, long long>> graph[1001];
long long dist[1001];

void Dijkstra(int start);
bool func(pair<long long, long long> A, pair<long long, long long> B) {
	return A.second < B.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		long long S, E, C;
		cin >> S >> E >> C;
		graph[S].push_back({ E,C });
	}
	for (int i = 0; i < N; i++) sort(graph[i].begin(), graph[i].end(), func);
	cin >> A >> B;
	Dijkstra(A);
	cout << dist[B];
	return 0;
}

void Dijkstra(int start) {
	priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		long long idx = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[idx].size(); i++) {
			if (dist[graph[idx][i].first] > dist[idx] + graph[idx][i].second) {
				dist[graph[idx][i].first] = dist[idx] + graph[idx][i].second;
				pq.push({ graph[idx][i].first, dist[graph[idx][i].first] });
			}
		}
	}
}