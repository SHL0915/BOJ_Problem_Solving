#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000;
const ll mod = 1000000009;

struct cmp {
	bool operator() (pair<ll, int> A, pair<ll, int> B) {
		return A.first > B.first;
	}
};

int N, M, S, E;
vector <pair<int, ll>> graph[100001];
ll dist[100001];
vector <int> path[100001];
ll path_num[100001];

void Dijkstra(int start);
ll count_path(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++) {
		int A, B;
		ll C;
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
		graph[B].push_back({ A,C });
	}
	Dijkstra(S);
	ll ans = count_path(E);
	cout << ans;
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pair<ll, int>, vector<pair<ll, int>>, cmp> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (pq.size()) {
		int now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll next_val = val + graph[now][i].second;
			if (dist[next] > next_val) {
				path[next].clear();
				path[next].push_back(now);
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
			else if (dist[next] == next_val) path[next].push_back(now);
		}
	}
}

ll count_path(int node) {
	if (node == S) return 1;
	if (path_num[node] != 0) return path_num[node];
	for (int i = 0; i < path[node].size(); i++) path_num[node] = (path_num[node] + count_path(path[node][i])) % mod;
	return path_num[node];
}