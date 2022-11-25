#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, pair<int, int>> plii;
typedef pair<pair<int, int>, int> piii;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (plii A, plii B) {
		return A.first > B.first;
	}
};

int M, N, K, S, E;
long long ans = INF;
vector <pair<long long, int>> graph[30000];
vector <int> compressed[30000];
long long dist[30000][10];
set <piii> forbidden;

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> K;
	cin >> S >> E;
	for (int i = 0; i < M; i++) {
		int x, y;
		long long c;
		cin >> x >> y >> c;
		graph[x].push_back({ c,y });
		compressed[y].push_back(x);
	}
	for (int i = 0; i < N; i++) sort(compressed[i].begin(), compressed[i].end());	
	for (int i = 0; i < K; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		forbidden.insert({ {x,y},z });
	}
	Dijkstra(S);
	for (int i = 0; i < 10; i++) ans = min(ans, dist[E][i]);
	if (S == E) cout << 0;
	else if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void Dijkstra(int start) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) dist[i][j] = INF;
	}
	priority_queue<plii, vector<plii>, cmp> pq;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i].second;
		int now_idx = lower_bound(compressed[next].begin(), compressed[next].end(), start) - compressed[next].begin();
		long long new_val = graph[start][i].first;
		if (dist[next][now_idx] > new_val) {
			dist[next][now_idx] = new_val;
			pq.push({ new_val, {next, now_idx} });
		}
	}	
	while (pq.size()) {
		int now = pq.top().second.first;
		int prev = compressed[now][pq.top().second.second];
		int prev_idx = pq.top().second.second;
		long long val = pq.top().first;
		pq.pop();
		if (dist[now][prev_idx] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			if (forbidden.count({ {prev, now},next }) != 0) continue;			
			int now_idx = lower_bound(compressed[next].begin(), compressed[next].end(), now) - compressed[next].begin();
			long long new_val = val + graph[now][i].first;
			if (dist[next][now_idx] > new_val) {
				dist[next][now_idx] = new_val;
				pq.push({ new_val, {next, now_idx} });
			}
		}
	}
}