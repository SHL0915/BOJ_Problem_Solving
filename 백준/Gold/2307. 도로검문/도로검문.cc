#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
const int INF = 0x3f3f3f3f;

struct cmp {
	bool operator() (pii A, pii B) {
		return A.first > B.first;
	}
};

int N, M, org, ans;
vector <pii> graph[1001];
vector <int> path[1001];
vector <pii> candidate;
int dist[1001];
int mark[1001];
int blocked[1001][1001];

void Dijkstra(int start);
void MakeCandidate(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, T;
		cin >> A >> B >> T;
		graph[A].push_back({ B,T });
		graph[B].push_back({ A,T });
	}
	Dijkstra(1);
	org = dist[N];
	MakeCandidate(N);
	for (int i = 0; i < candidate.size(); i++) {
		blocked[candidate[i].first][candidate[i].second] = 1;
		blocked[candidate[i].second][candidate[i].first] = 1;
		Dijkstra(1);
		ans = max(ans, dist[N]);
		blocked[candidate[i].first][candidate[i].second] = 0;
		blocked[candidate[i].second][candidate[i].first] = 0;
	}
	if (ans == INF) cout << -1;
	else cout << ans - org;
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pii, vector<pii>, cmp> pq;
	dist[start] = 0;
	pq.push({ 0,start });
	while (pq.size()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			if (blocked[now][next] == 1) continue;
			int new_val = val + graph[now][i].second;
			if (dist[next] > new_val) {
				dist[next] = new_val;
				path[next].clear();
				path[next].push_back(now);
				pq.push({ new_val, next });
			}
			if (dist[next] == new_val) path[next].push_back(now);
		}
	}
}

void MakeCandidate(int node) {
	if (mark[node] != 0) return;
	if (node == 1) return;
	mark[node] = 1;
	for (int i = 0; i < path[node].size(); i++) {
		candidate.push_back({ node, path[node][i] });
		MakeCandidate(path[node][i]);
	}
}