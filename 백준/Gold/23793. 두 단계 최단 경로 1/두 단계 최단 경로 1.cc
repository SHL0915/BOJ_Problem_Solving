#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1000000000000LL;

struct cmp {
	bool operator() (pair<long long, long long> A, pair<long long, long long> B){
		return A.second > B.second;
	}
};

int N, M, X, Y, Z;
long long A, B;
vector <pair<int, int>> graph[100001];
long long dist[100001];

void Dijkstra(int start);
void Dijkstra2(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	cin >> X >> Y >> Z;
	Dijkstra(X);
	A = dist[Y];
	Dijkstra(Y);
	B = dist[Z];
	A = A + B;	
	Dijkstra2(X);
	B = dist[Z];
	if (A < INF) cout << A << " ";
	else cout << -1 << " ";
	if (B < INF) cout << B << " ";
	else cout << -1 << " ";
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		long long idx = pq.top().first;
		long long val = pq.top().second;
		pq.pop();
		if (val > dist[idx]) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			if (dist[graph[idx][i].first] > val + graph[idx][i].second) {
				dist[graph[idx][i].first] = val + graph[idx][i].second;
				pq.push({ graph[idx][i].first, dist[graph[idx][i].first] });
			}
		}
	}
}

void Dijkstra2(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		long long idx = pq.top().first;
		long long val = pq.top().second;
		pq.pop();
		if (val > dist[idx]) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			if (graph[idx][i].first == Y) continue;
			if (dist[graph[idx][i].first] > val + graph[idx][i].second) {
				dist[graph[idx][i].first] = val + graph[idx][i].second;
				pq.push({ graph[idx][i].first, dist[graph[idx][i].first] });
			}
		}
	}
}