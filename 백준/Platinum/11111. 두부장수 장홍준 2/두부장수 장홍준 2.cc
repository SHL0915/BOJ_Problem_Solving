#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M;
map <pii, int> score;
vector <int> graph[3000];
int arr[51][51];
int cap[3000][3000], flow[3000][3000], cost[3000][3000];

void init();
void add_edge(int u, int v, int ca, int co);
int convert(int x, int y);
pii find_Max(int s, int e);

void solve() {
	cin >> N >> M;
	init();

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) arr[i][j] = s[j] - 'A';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i + j) % 2) add_edge(convert(j, i), N * M + 1, 1, 0);
			else {
				add_edge(N * M, convert(j, i), 1, 0);
				add_edge(convert(j, i), N * M + 1, 1, 0);
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					add_edge(convert(j, i), convert(nx, ny), 1, -score[{ arr[i][j], arr[ny][nx] }]);
				}
			}
		}
	}

	pii ans = find_Max(N * M, N * M + 1);
	cout << -ans.second;
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

void init() {
	score[{0, 0}] = 10;
	score[{0, 1}] = 8;
	score[{0, 2}] = 7;
	score[{0, 3}] = 5;
	score[{0, 5}] = 1;

	score[{1, 0}] = 8;
	score[{1, 1}] = 6;
	score[{1, 2}] = 4;
	score[{1, 3}] = 3;
	score[{1, 5}] = 1;

	score[{2, 0}] = 7;
	score[{2, 1}] = 4;
	score[{2, 2}] = 3;
	score[{2, 3}] = 2;
	score[{2, 5}] = 1;

	score[{3, 0}] = 5;
	score[{3, 1}] = 3;
	score[{3, 2}] = 2;
	score[{3, 3}] = 2;
	score[{3, 5}] = 1;

	score[{5, 0}] = 1;
	score[{5, 1}] = 1;
	score[{5, 2}] = 1;
	score[{5, 3}] = 1;
	score[{5, 5}] = 0;

	return;
}

void add_edge(int u, int v, int ca, int co) {
	graph[u].push_back(v);
	graph[v].push_back(u);
	cap[u][v] = ca;
	cost[u][v] = co;
	cost[v][u] = -co;
	return;
}

int convert(int x, int y) {
	return y * M + x;
}

pii find_Max(int s, int e) {
	int mf = 0, mc = 0;
	while (1) {
		int par[3000], dist[3000], mark[3000];
		memset(par, -1, sizeof(par));
		memset(dist, INF, sizeof(dist));
		memset(mark, 0, sizeof(mark));
		queue <int> q;
		q.push(s);
		mark[s] = 1;
		dist[s] = 0;
		while (q.size()) {
			int f = q.front(); q.pop();
			mark[f] = 0;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (cap[f][now] - flow[f][now] > 0 && dist[now] > dist[f] + cost[f][now]) {
					dist[now] = dist[f] + cost[f][now];
					par[now] = f;
					if (mark[now] == 0) {
						mark[now] = 1;
						q.push(now);
					}
				}
			}
		}
		if (par[e] == -1) break;
		int val = INF;
		for (int i = e; i != s; i = par[i]) val = min(val, cap[par[i]][i] - flow[par[i]][i]);
		for (int i = e; i != s; i = par[i]) {
			mc += val * cost[par[i]][i];
			flow[par[i]][i] += val;
			flow[i][par[i]] -= val;
		}
		mf += val;
	}
	return { mf,mc };
}