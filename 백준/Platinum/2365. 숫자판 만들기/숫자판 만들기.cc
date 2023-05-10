#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, tot;
int A[55], B[55];
vector <int> graph[105];
int cap[105][105], flow[105][105];
int level[105], mark[105];

void add_edge(int u, int v, int c);
int Dinic(int S, int E);
int DFS(int S, int E, int f);
int BFS(int S, int E);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	for (int i = 1; i <= N; i++) tot += A[i];

	for (int i = 1; i <= N; i++) {
		add_edge(0, i, A[i]);
		add_edge(N + i, 2 * N + 1, B[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			add_edge(i, N + j, INF);
		}
	}

	int l = 0, r = 10000;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		memset(flow, 0, sizeof(flow));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cap[i][N + j] = mid;
			}
		}

		int res = Dinic(0, 2 * N + 1);
		if (res == tot) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}

	cout << ans << '\n';

	memset(flow, 0, sizeof(flow));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cap[i][N + j] = ans;
		}
	}

	Dinic(0, 2 * N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << flow[i][N + j] << " ";
		}
		cout << '\n';
	}

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

int DFS(int S, int E, int f) {
	if (S == E) return f;
	for (int& i = mark[S]; i < graph[S].size(); i++) {
		int next = graph[S][i];
		if (level[next] == level[S] + 1 && cap[S][next] - flow[S][next] > 0) {
			int ret = DFS(next, E, min(cap[S][next] - flow[S][next], f));
			if (ret) {
				flow[S][next] += ret;
				flow[next][S] -= ret;
				return ret;
			}
		}
	}
	return 0;
}

int BFS(int S, int E) {
	memset(level, -1, sizeof(level));
	queue <int> q;

	q.push(S);
	level[S] = 0;
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