#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct edge { ll dist, cap, rev; };

int N, M, S, E;
pii K = { -1, -1 }, H = { -1, -1 };
int arr[101][101];
vector <edge> graph[20005];
int parent[20005], pe[20005];

int in(int x, int y);
int out(int x, int y);
void add_edge(int u, int v, int c);
ll find_Max(int s, int e);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '#') arr[i][j] = 1;
			else {
				if (s[j] == 'K') K = { j,i };
				else if (s[j] == 'H') H = { j,i };
			}
		}
	}
	if (K.first == -1 || H.first == -1) {
		cout << -1;
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			add_edge(in(j, i), out(j, i), 1);
			if (arr[i][j] == 1) continue;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
				if (arr[ny][nx] == 1) continue;
				add_edge(out(j, i), in(nx, ny), INF);
				add_edge(out(nx, ny), in(j, i), INF);
			}
		}
	}
	if (abs(K.first - H.first) + abs(K.second - H.second) == 1) cout << -1;
	else cout << find_Max(out(K.first, K.second), in(H.first, H.second));
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
	edge x;
	x.dist = v; x.cap = c; x.rev = graph[v].size();
	graph[u].push_back(x);
	x.dist = u; x.cap = 0; x.rev = graph[u].size() - 1;
	graph[v].push_back(x);
	return;
}

ll find_Max(int s, int e) {
	ll ret = 0;
	while (1) {
		memset(parent, -1, sizeof(parent));
		memset(pe, 0, sizeof(pe));
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i].dist;
				int cap = graph[f][i].cap;
				if (parent[now] == -1 && cap > 0) {
					parent[now] = f;
					pe[now] = i;
					q.push(now);
				}
			}
		}
		if (parent[e] == -1) break;
		ll val = 0x3f3f3f3f3f3f3f3fLL;
		for (int i = e; i != s; i = parent[i]) val = min(val, graph[parent[i]][pe[i]].cap);
		for (int i = e; i != s; i = parent[i]) {
			int rev = graph[parent[i]][pe[i]].rev;
			graph[parent[i]][pe[i]].cap -= val;
			graph[i][rev].cap += val;
		}
		ret += val;
	}
	return ret;
}

int in(int x, int y) {
	return 2 * (y * M + x);
}

int out(int x, int y) {
	return 2 * (y * M + x) + 1;
}