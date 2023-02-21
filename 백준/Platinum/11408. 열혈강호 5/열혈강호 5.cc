#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[805];
int cap[805][805], flow[805][805], cost[805][805];

pii find_Max(int s, int e);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		graph[0].push_back(i);
		graph[i].push_back(0);
		cap[0][i] = 1;
	}
	for (int i = N + 1; i <= N + M; i++) {
		graph[i].push_back(N + M + 1);
		graph[N + M + 1].push_back(i);
		cap[i][N + M + 1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			a += N;
			graph[i].push_back(a);
			graph[a].push_back(i);
			cap[i][a] = 1;
			cost[i][a] = b;
			cost[a][i] = -b;
		}
	}
	pii ans = find_Max(0, N + M + 1);
	cout << ans.first << '\n' << ans.second;
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

pii find_Max(int s, int e) {
	int mf = 0, mc = 0;
	while (1) {
		int parent[805], dist[805], mark[805];
		memset(parent, -1, sizeof(parent));
		memset(dist, INF, sizeof(dist));
		memset(mark, 0, sizeof(mark));
		queue <int> q;
		q.push(s);
		dist[s] = 0;
		mark[s] = 1;
		while (q.size()) {
			int f = q.front(); q.pop();
			mark[f] = 0;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (cap[f][now] - flow[f][now] > 0 && dist[now] > dist[f] + cost[f][now]) {
					dist[now] = dist[f] + cost[f][now];
					parent[now] = f;
					if (mark[now] == 0) {
						mark[now] = 1;
						q.push(now);
					}
				}
			}

		}
		if (parent[e] == -1) break;
		int val = INF;
		for (int i = e; i != s; i = parent[i]) val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);
		for (int i = e; i != s; i = parent[i]) {
			mc += val * cost[parent[i]][i];
			flow[parent[i]][i] += val;
			flow[i][parent[i]] -= val;
		}
		mf += val;		
	}
	return { mf, mc };
}