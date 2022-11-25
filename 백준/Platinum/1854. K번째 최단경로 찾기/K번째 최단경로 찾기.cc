#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pli;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (pli A, pli B) {
		return A.first > B.first;
	}
};

int N, M, K;
vector <pli> graph[1001];
priority_queue <long long> dist[1001];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int A, B;
		long long C;
		cin >> A >> B >> C;
		graph[A].push_back({ C,B });
	}
	Dijkstra(1);
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K) cout << -1 << '\n';
		else cout << dist[i].top() << '\n';
	}
	return 0;
}

void Dijkstra(int start) {
	priority_queue <pli, vector<pli>, cmp> pq;
	dist[start].push(0);
	pq.push({ 0,start });
	while (pq.size()) {
		int now = pq.top().second;
		long long val = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			long long new_val = val + graph[now][i].first;
			if (dist[next].size() == K) {
				if (dist[next].top() > new_val) dist[next].pop();
				else continue;
			}
			dist[next].push(new_val);
			pq.push({ new_val, next });
		}
	}
}