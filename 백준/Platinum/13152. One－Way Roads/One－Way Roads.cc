#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[3005];
int parent[3005];
int org[3005][3005];
int flow[3005][3005], cap[3005][3005];

int find_Max(int s, int e);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		a += M; b += M;
		graph[0].push_back(i);
		graph[i].push_back(0);
		org[0][i] = 1;

		graph[i].push_back(a);
		graph[a].push_back(i);
		graph[i].push_back(b);
		graph[b].push_back(i);
		org[i][a] = 1;
		org[i][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		graph[i + M].push_back(3003);
		graph[3003].push_back(i + M);
	}

	int l = 0, r = M;
	while (l < r) {
		int mid = (l + r) / 2;
		memset(flow, 0, sizeof(flow));
		for (int i = 0; i < 3005; i++) {
			for (int j = 0; j < 3005; j++) cap[i][j] = org[i][j];
		}

		for (int i = 1; i <= N; i++) cap[i + M][3003] = mid;

		int m = find_Max(0, 3003);

		if (m == M) r = mid;
		else l = mid + 1;
	}

	cout << l;
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
		memset(parent, -1, sizeof(parent));
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (parent[now] == -1 && cap[f][now] - flow[f][now] > 0) {
					parent[now] = f;
					q.push(now);
				}
			}
		}
		if (parent[e] == -1) break;
		int val = 0x3f3f3f3f;
		for (int i = e; i != s; i = parent[i]) val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);
		for (int i = e; i != s; i = parent[i]) {
			flow[parent[i]][i] += val;
			flow[i][parent[i]] -= val;
		}
		ret += val;
	}
	return ret;
}