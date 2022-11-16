#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1234567890;

struct cmp {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		return A.first < B.first;
	}
};

int N, M, X, Y;
vector <pair<int, int>> graph[100001];
int weight[100001];

void Dijkstra(long long start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({ B, C });
		graph[B].push_back({ A,C });
	}
	cin >> X >> Y;
	Dijkstra(X);
	cout << weight[Y];
	return 0;
}

void Dijkstra(long long start) {
	for (int i = 1; i <= N; i++) weight[i] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	weight[start] = INF;
	pq.push({ INF, start });
	while (pq.size()) {
		int idx = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (val < weight[idx]) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i].first;
			int next_val = min(val, graph[idx][i].second);
			if (next_val > weight[next]) {
				weight[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
}