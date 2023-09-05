#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct edge {
	int to, cap, rev;
};

int N, M;
vector <edge> graph[55005];
int cost[55005];
int level[55005], mark[55005];
vector <int> chosen;

void add_edge(int u, int v, int c) {
	graph[u].push_back({ v, c, (int)graph[v].size() });
	graph[v].push_back({ u, 0, (int)graph[u].size() - 1 });
	return;
}

int DFS(int s, int e, int f) {
	if (s == e) return f;
	for (int & i = mark[s]; i < graph[s].size(); i++) {
		edge & next = graph[s][i];
		if (level[next.to] == level[s] + 1 && next.cap > 0) {
			int res = DFS(next.to, e, min(f, next.cap));
			if (res) {
				next.cap -= res;
				graph[next.to][next.rev].cap += res;
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
		for (auto next : graph[now]) {
			if (level[next.to] == -1 && next.cap > 0) {
				level[next.to] = level[now] + 1;
				q.push(next.to);
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

void check(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	chosen.push_back(node);

	for (auto next : graph[node]) {
		if (next.cap > 0) check(next.to);
	}

	return;
}

void solve() {
	cin >> N >> M;
	int S = 0, E = N + M + 1, sum = 0;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		add_edge(i, E, a);
		sum += a;
		cost[i] = -a;
	}

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(S, N + i, c);
		add_edge(N + i, a, INF);
		add_edge(N + i, b, INF);
		cost[N + i] = c;
	}

	Dinic(S, E);
	memset(mark, 0, sizeof(mark));
	check(S);

	int ans = 0;
	for (int a : chosen) ans += cost[a];

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