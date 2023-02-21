#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[305];
int arr[305];
int cap[305][305], flow[305][305];
int par[305];

int find_Max(int s, int e);

void solve() {
	cin >> N >> M;
	if (N == 0 && M == 0) exit(0);
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	graph[0].clear();
	graph[N + 1].clear();
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		graph[i].clear();
		if (arr[i] == 0) {
			graph[0].push_back(i);
			graph[i].push_back(0);
			cap[0][i] = 1;
		}
		else {
			graph[N + 1].push_back(i);
			graph[i].push_back(N + 1);
			cap[i][N + 1] = 1;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		cap[a][b] = 1;
		cap[b][a] = 1;
	}

	cout << find_Max(0, N + 1) << '\n';
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
	while (1) solve();
	return 0;
}

int find_Max(int s, int e) {
	int ret = 0;
	while (1) {
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
		int val = 0x3f3f3f3f;
		for (int i = e; i != s; i = par[i]) val = min(val, cap[par[i]][i] - flow[par[i]][i]);
		for (int i = e; i != s; i = par[i]) {
			flow[par[i]][i] += val;
			flow[i][par[i]] -= val;
		}
		ret += val;
	}
	return ret;
}