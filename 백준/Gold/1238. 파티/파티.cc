#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;

struct cmp {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		return A.first > B.first;
	}
};

int N, M, X, ans;
vector <pair<int, int>> graph[1001];
int dist[1001];
int sum[1001];

void Djikstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[s].push_back({ e,t });
	}
	for (int i = 1; i <= N; i++) {
		Djikstra(i);
		sum[i] += dist[X];
	}
	Djikstra(X);
	for (int i = 1; i <= N; i++) ans = max(ans, sum[i] + dist[i]);
	cout << ans;
	return 0;
}

void Djikstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	dist[start] = 0;
	pq.push({ 0,start });
	while (pq.size()) {
		int idx = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (dist[idx] < val) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i].first;
			int next_val = val + graph[idx][i].second;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
}