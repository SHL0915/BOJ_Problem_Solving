#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000;

struct cmp {
	bool operator() (pair<ll, int> A, pair<ll, int> B) {
		return A.first > B.first;
	}
};

int N, M, K;
vector <pair<int, int>> graph[1001];
priority_queue <ll> dist[1001];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
	}
	Dijkstra(1);
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K) cout << -1 << '\n';
		else cout << dist[i].top() << '\n';
	}
	return 0;
}

void Dijkstra(int start) {
	priority_queue < pair<ll, int>, vector<pair<ll, int>>, cmp> pq;
	pq.push({ 0, start });
	dist[start].push(0);
	while (pq.size()) {
		int now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll next_val = graph[now][i].second + val;
			if (dist[next].size() == K) {
				if (dist[next].top() > next_val) {
					dist[next].pop();
					dist[next].push(next_val);
					pq.push({ next_val, next });
				}
			}
			else {
				dist[next].push(next_val);
				pq.push({ next_val, next });
			}
		}
	}
}