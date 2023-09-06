#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <pair<pii, int>> edge;
vector <int> graph[105];
int cap[105][105], flow[105][105], level[105], mark[105];

void init() {
	for (int i = 0; i <= N + 1; i++) graph[i].clear();
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	return;
}

void add_edge(int u, int v, int c) {
	graph[u].push_back(v);
	graph[v].push_back(u);
	cap[u][v] = c;
	return;
}

int DFS(int s, int e, int f) {
	if (s == e) return f;
	for (int & i = mark[s]; i < graph[s].size(); i++) {
		int next = graph[s][i];
		if (level[next] == level[s] + 1 && cap[s][next] - flow[s][next] > 0) {
			int res = DFS(next, e, min(f, cap[s][next] - flow[s][next]));
			if (res) {
				flow[s][next] += res;
				flow[next][s] -= res;
				return res;
			}
		}
	}
	return 0;
}

bool BFS(int s, int e) {
	memset(level, -1, sizeof(level));
	queue <int> q;
	q.push(s);
	level[s] = 0;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : graph[now]) {
			if (level[next] == -1 && cap[now][next] - flow[now][next] > 0) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[e] != -1;
}

int Dinic(int s, int e) {
	int ret = 0;
	while (BFS(s, e)) {
		memset(mark, 0, sizeof(mark));
		while (1) {
			int res = DFS(s, e, INF);
			if (res) ret += res;
			else break;
		}
	}
	return ret;
}

void solve() {
	cin >> N >> M;

	int S = 0, E = N + 1;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ {a,b},c });
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		init();
		for (int j = 0; j < M; j++) {
			int a = edge[j].first.first, b = edge[j].first.second, c = edge[j].second;
			if (c < edge[i].second) {
				add_edge(a, b, 1);
				add_edge(b, a, 1);
			}
		}
		add_edge(S, edge[i].first.first, INF);
		add_edge(edge[i].first.second, E, INF);

		ans += Dinic(S, E);
	}

	cout << ans;
	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}