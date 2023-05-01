#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[505], ans[505];
int adj[505][505];
vector <int> graph[505];
int cap[505][505], flow[505][505];
int mark[505], level[505];

void add_edge(int u, int v, int c);
int Dinic(int S, int E);
void check(int node);
int BFS(int S, int E);
int DFS(int S, int E, int f);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] == 1) add_edge(0, i, INF);
		else if (arr[i] == 2) add_edge(i, N + 1, INF);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a; cin >> a;
			add_edge(i, j, a);
		}
	}

	cout << Dinic(0, N + 1) << '\n';
	for (int i = 1; i <= N; i++) if (arr[i] == 1) check(i);

	for (int i = 1; i <= N; i++) if (ans[i]) cout << i << " ";
	cout << '\n';

	for (int i = 1; i <= N; i++) if (ans[i] == 0) cout << i << " ";
	cout << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void add_edge(int u, int v, int c) {
	if (adj[u][v] == 0) {
		graph[u].push_back(v);
		graph[v].push_back(u);
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	cap[u][v] = c;
	return;
}

int Dinic(int S, int E) {
	int ret = 0;
	while (BFS(S, E)) {
		memset(mark, 0, sizeof(mark));
		while (1) {
			int f = DFS(S, E, INF);
			if (f) ret += f;
			else break;
		}
	}

	return ret;
}

int BFS(int S, int E) {
	memset(level, -1, sizeof(level));
	level[S] = 0;
	queue <int> q;
	q.push(S);
	while (q.size()) {
		int f = q.front(); q.pop();
		for (int i = 0; i < graph[f].size(); i++) {
			int next = graph[f][i];
			if (level[next] == -1 && cap[f][next] - flow[f][next] > 0) {
				level[next] = level[f] + 1;
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

void check(int node) {
	if (ans[node]) return;
	ans[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (cap[node][next] - flow[node][next] > 0) check(next);
	}
	return;
}