#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000000;

int N, M;
vector <pair<pair<int, int>, int>> graph;
long long dist[501];

void BF(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph.push_back({ {A,B},C });
	}
	BF(1);
	for (int i = 0; i < N - 1; i++) {
		for (int i = 0; i < M; i++) {
			if (dist[graph[i].first.first] == INF) continue;
			else if (dist[graph[i].first.second] > dist[graph[i].first.first] + graph[i].second) {
				cout << -1;
				return 0;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}

void BF(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	for (int i = 0; i < N - 1; i++) {
		dist[start] = 0;
		for (int i = 0; i < M; i++) {
			if (dist[graph[i].first.first] == INF) continue;
			else if (dist[graph[i].first.second] > dist[graph[i].first.first] + graph[i].second) {
				dist[graph[i].first.second] = dist[graph[i].first.first] + graph[i].second;
			}
		}
	}
}