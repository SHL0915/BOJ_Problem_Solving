#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, K;
vector <int> graph[2005];
int cap[2005][2005], flow[2005][2005];

int find_Max(int s, int e);

void solve() {
	cin >> N >> M >> K;
	graph[N + M + 1].push_back(0);

	graph[0].push_back(N + M + 1);
	cap[N + M + 1][0] = K;

	for (int i = 1; i <= N; i++) {
		graph[0].push_back(i);
		graph[i].push_back(0);
		cap[0][i] = INF;
		graph[N + M + 1].push_back(i);
		graph[i].push_back(N + M + 1);
		cap[N + M + 1][i] = 1;
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			a += N;
			graph[i].push_back(a);
			graph[a].push_back(i);
			cap[i][a] = INF;
		}
	}

	for (int i = 1; i <= M; i++) {
		graph[i + N].push_back(N + M + 2);
		graph[N + M + 2].push_back(i + N);
		cap[i + N][N + M + 2] = 1;
	}

	cout << find_Max(N + M + 1, N + M + 2);
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

int find_Max(int s, int e) {
	int ret = 0;
	while (1) {
		int par[2005];
		memset(par, -1, sizeof(par));
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (par[now] == -1 && cap[f][now] - flow[f][now] > 0) {
					q.push(now);
					par[now] = f;
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