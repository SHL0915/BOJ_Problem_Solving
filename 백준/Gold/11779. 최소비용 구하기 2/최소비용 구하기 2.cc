#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1000000000000LL;

struct cmp {
	bool operator() (pair<long long, long long> A, pair<long long, long long> B) {
		return A.first > B.first;
	}
};

long long N, M, S, E;
vector <pair<long long, long long>> graph[1001];
pair <long long, long long> dist[1001];
vector <long long> route;

void Dijkstra(long long start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
	}
	cin >> S >> E;
	Dijkstra(S);
	route.push_back(E);
	long long temp = dist[E].second;
	while (1) {
		route.push_back(temp);
		if (temp == S) break;
		temp = dist[temp].second;
	}
	cout << dist[E].first << '\n' << route.size() << '\n';
	for (int i = route.size() - 1; i >= 0; i--) cout << route[i] << " ";
	return 0;
}

void Dijkstra(long long start) {
	for (int i = 1; i <= N; i++) dist[i].first = INF;
	priority_queue < pair<long long, long long>, vector <pair<long long, long long>>, cmp> pq;
	dist[start] = { 0, start };
	pq.push({ start, 0 });
	while (pq.size()) {
		long long idx = pq.top().first;
		long long val = pq.top().second;
		pq.pop();
		if (val > dist[idx].first) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			if (dist[graph[idx][i].first].first > graph[idx][i].second + dist[idx].first) {
				dist[graph[idx][i].first] = { graph[idx][i].second + dist[idx].first , idx };
				pq.push({ graph[idx][i].first , dist[graph[idx][i].first].first });
			}
		}
	}
}