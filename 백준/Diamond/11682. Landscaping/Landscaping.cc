#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, A, B;
vector <int> graph[3005];
int cap[3005][3005], flow[3005][3005];
int level[3005], mark[3005];

void add_edge(int u, int v, int c);
int convert(int x, int y);
int Dinic(int S, int E);
int BFS(int S, int E);
int DFS(int S, int E, int f);

void solve() {
	cin >> N >> M >> A >> B;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '.') add_edge(N * M, convert(j, i), B);
			else add_edge(convert(j, i), N * M + 1, B);			
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int x = j + dx[k];
				int y = i + dy[k];
				if (x < 0 || x >= M || y < 0 || y >= N) continue; 
				add_edge(convert(j, i), convert(x, y), A);
			}
		}
	}

	cout << Dinic(N * M, N * M + 1);

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
	graph[u].push_back(v);
	graph[v].push_back(u);
	cap[u][v] = c;
	return;
}

int convert(int x, int y) {
	return y * M + x;
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