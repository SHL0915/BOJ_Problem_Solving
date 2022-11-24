#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, pair<int, int>> plii;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (plii A, plii B) {
		return A.first > B.first;
	}
};

int N, M, K;
long long ans = INF;
vector <pair<int, long long>> graph[10001];
long long dist[10001][21];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int A, B;
		long long C;
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
		graph[B].push_back({ A,C });
	}
	Dijkstra(1);
	for (int i = 0; i <= K; i++) ans = min(ans, dist[N][i]);
	cout << ans;
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) dist[i][j] = INF;
	}
	priority_queue<plii, vector<plii>, cmp> pq;
	pq.push({ 0,{start, 0}});
	dist[start][0] = 0;
	while (pq.size()) {
		int now = pq.top().second.first;
		int num = pq.top().second.second;
		long long val = pq.top().first;
		pq.pop();
		if (dist[now][num] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			long long new_val = val + graph[now][i].second;
			if (dist[next][num] > new_val) {
				dist[next][num] = new_val;
				pq.push({ new_val, {next,num} });
			}
			if (num < K && dist[next][num + 1] > val) {
				dist[next][num + 1] = val;
				pq.push({ val, {next, num + 1} });
			}
		}
	}
}