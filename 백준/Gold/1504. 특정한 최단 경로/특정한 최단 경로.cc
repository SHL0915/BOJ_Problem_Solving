#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 10000000000000LL;

struct cmp {
	bool operator () (pair<long long, long long> A, pair<long long, long long> B) {
		return A.second > B.second;
	}
};

long long N, E, v1, v2, flag, V;
vector <pair<long long, long long>> graph[801];
long long val[801];

void Dijkstra(long long start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	Dijkstra(v1);
	if (val[v2] == INF) {
		cout << -1;
		return 0;
	}
	V = val[v2];
	Dijkstra(1);
	long long A = val[v1];
	long long B = val[v2];
	if (A == INF && B == INF) {
		cout << -1;
		return 0;
	}
	else if (A == INF) flag = 1;
	else if (B == INF) flag = 2;
	if (flag == 0) {
		Dijkstra(v2);
		A += val[N];
		long long temp = val[N];
		Dijkstra(v1);
		B += val[N];
		if (temp == INF && val[N] == INF) {
			cout << -1;
			return 0;
		}
		else if (temp == INF) cout << B + V;
		else if (val[N] == INF) cout << A + V;
		else cout << min(B + V, A + V);
	}
	else if (flag == 1) {
		Dijkstra(v1);
		B += val[N];
		if (val[N] == INF) cout << -1;
		else cout << B + V;
	}
	else {
		Dijkstra(v2);
		A += val[N];
		if (val[N] == INF) cout << -1;
		else cout << A + V;
	}
	return 0;
}

void Dijkstra(long long start) {
	priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
	for (int i = 1; i <= N; i++) val[i] = INF;
	pq.push({ start, 0 });
	val[start] = 0;
	while (pq.size()) {
		long long idx = pq.top().first;
		long long value = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[idx].size(); i++) {
			if (val[graph[idx][i].first] > val[idx] + graph[idx][i].second) {
				val[graph[idx][i].first] = val[idx] + graph[idx][i].second;
				pq.push({ graph[idx][i].first, val[graph[idx][i].first] });
			}
		}
	}
}