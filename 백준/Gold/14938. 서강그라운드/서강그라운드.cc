#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1000000000;

struct cmp {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		return A.first > B.first;
	}
};

int N, M, R, ans;
int item[101];
vector <pair<int, int>> graph[101];
int dist[101];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) cin >> item[i];
	for (int i = 0; i < R; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back({ b,l });
		graph[b].push_back({ a,l });
	}
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		Dijkstra(i);
		for (int i = 1; i <= N; i++) if (dist[i] <= M) temp += item[i];
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pair<int, int>, vector <pair<int, int>>, cmp> pq;
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