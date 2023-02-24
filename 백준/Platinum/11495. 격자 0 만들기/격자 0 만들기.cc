#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, sum;
vector <int> graph[2505];
int arr[51][51];
int cap[2505][2505], flow[2505][2505];

int convert(int x, int y);
int find_Max(int s, int e);
void add_edge(int u, int v, int c);

void solve() {
	for (int i = 0; i < 2505; i++) graph[i].clear();
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	sum = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i + j) % 2) add_edge(convert(j, i), N * M + 1, arr[i][j]);
			else {
				add_edge(N * M , convert(j, i), arr[i][j]);
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					add_edge(convert(j, i), convert(nx, ny), INF);
				}
			}
		}
	}

	int ans = sum - find_Max(N * M, N * M + 1);
	cout << ans << '\n';
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

int convert(int x, int y) {
	return y * M + x;
}

int find_Max(int s, int e) {
	int ret = 0;
	while (1) {
		int par[2505];
		memset(par, -1, sizeof(par));
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (par[now] == -1 && cap[f][now] - flow[f][now] > 0) {
					par[now] = f;
					q.push(now);
				}
			}
		}
		if (par[e] == -1) break;
		int val = INF;
		for (int i = e; i != s; i = par[i]) val = min(val, cap[par[i]][i] - flow[par[i]][i]);
		for (int i = e; i != s; i = par[i]) {
			flow[par[i]][i] += val;
			flow[i][par[i]] -= val;
		}
		ret += val;
	}
	return ret;
}

void add_edge(int u, int v, int c) {
	graph[u].push_back(v);
	graph[v].push_back(u);
	cap[u][v] = c;
}