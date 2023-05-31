#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[305];
vector <pii> edge;
int cap[305][305], flow[305][305], cop[305][305], mark[305], level[305];

void init();
void add_edge(int u, int v, int c);
int Dinic(int S, int E);
int BFS(int S, int E);
int DFS(int S, int E, int f);
int chk(int S, int E);

void solve() {
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a, b, c);
		edge.push_back({ a,b });
	}

	Dinic(1, N);	
		
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int a = edge[i].first, b = edge[i].second;

		if (cap[a][b] == flow[a][b]) {
			memset(mark, -1, sizeof(mark));
			if (chk(a, b) == 0) cnt++;
		}
	}

	cout << cnt << '\n';

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void init() {
	for (int i = 1; i <= N; i++) graph[i].clear();
	edge.clear();
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	return;
}

void add_edge(int u, int v, int c) {
	graph[u].push_back(v);
	graph[v].push_back(u);
	cap[u][v] += c;
	return;
}

int Dinic(int S, int E) {
	int ret = 0;
	while (BFS(S, E)) {
		memset(mark, 0, sizeof(mark));
		while (1) {
			int res = DFS(S, E, INF);
			if (res) ret += res;
			else break;
		}
	}
	return ret;
}

int BFS(int S, int E) {
	memset(level, -1, sizeof(level));
	queue <int> q;

	level[S] = 0;
	q.push(S);

	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : graph[now]) {
			if (level[next] == -1 && cap[now][next] - flow[now][next] > 0) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}

	return level[E] != -1;
}

int DFS(int S, int E, int f) {
	if (S == E) return f;

	for (int& i = mark[S]; i < graph[S].size(); i++) {
		int next = graph[S][i];
		if (level[next] == level[S] + 1 && cap[S][next] - flow[S][next] > 0) {
			int ret = DFS(next, E, min(f, cap[S][next] - flow[S][next]));
			if (ret) {
				flow[S][next] += ret;
				flow[next][S] -= ret;
				return ret;
			}
		}
	}

	return 0;
}

int chk(int S, int E) {
	if (S == E) return 1;
	if (mark[S] != -1) return mark[S];
	int& ret = mark[S];
	ret = 0;	

	for (int next : graph[S]) {
		if (cap[S][next] - flow[S][next] > 0) ret |= chk(next, E);
	}

	return ret;
}