#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[205];
int cap[205][205], flow[205][205], cost[205][205];

int find_Max(int s, int e);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		graph[0].push_back(i);
		graph[i].push_back(0);
		cap[i][0] = a;
	}
	for (int i = N + 1; i <= N + M; i++) {
		int a; cin >> a;
		graph[N + M + 1].push_back(i);
		graph[i].push_back(N + M + 1);
		cap[N + M + 1][i] = a;
	}
	for (int i = N + 1; i <= N + M; i++) {
		for (int j = 1; j <= N; j++) {
			int a; cin >> a;
			graph[i].push_back(j);
			graph[j].push_back(i);
			cap[i][j] = INF;
			cost[i][j] = a;
			cost[j][i] = -a;
		}
	}
	cout << find_Max(N + M + 1, 0);
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
		int parent[205], mark[205], dist[205];
		memset(parent, -1, sizeof(parent));
		memset(mark, 0, sizeof(mark));
		memset(dist, INF, sizeof(dist));
		dist[s] = 0;
		mark[s] = 1;
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			mark[f] = 0;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (cap[f][now] - flow[f][now] > 0 && dist[now] > dist[f] + cost[f][now]) {
					dist[now] = dist[f] + cost[f][now];
					parent[now] = f;
					if (mark[now] == 0) {
						q.push(now);
						mark[now] = 1;
					}
				}
			}
		}
		if (parent[e] == -1) break;
		int val = INF;
		for (int i = e; i != s; i = parent[i]) val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);
		for (int i = e; i != s; i = parent[i]) {
			ret += val * cost[parent[i]][i];
			flow[parent[i]][i] += val;
			flow[i][parent[i]] -= val;
		}
	}
	return ret;
}