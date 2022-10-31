#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000000;

int TC, N, M, W;
vector <pair<pair<long long, long long>, long long>> graph;
long long dist[501];

void BF();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		int flag = 0;
		cin >> N >> M >> W;
		graph.clear();
		for (int i = 0; i < M; i++) {
			long long S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ {S,E},T });
			graph.push_back({ {E,S},T });
		}
		for (int i = 0; i < W; i++) {
			long long S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ {S,E}, -1LL * T });
		}
		BF();
		for (int j = 0; j < graph.size(); j++) {
			if (dist[graph[j].first.second] > dist[graph[j].first.first] + graph[j].second) {
				cout << "YES\n";
				flag = 1;
				break;
			}	
		}
		if (flag == 0) cout << "NO\n";
	}
	return 0;
}

void BF() {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < graph.size(); j++) {
			if (dist[graph[j].first.second] > dist[graph[j].first.first] + graph[j].second) {
				dist[graph[j].first.second] = dist[graph[j].first.first] + graph[j].second;
			}
		}
	}
}