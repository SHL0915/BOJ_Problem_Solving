#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[505];
int in_degree[505], parent[505];
int org[505][505];
int flow[505][505], cap[505][505];

int find_Max(int s, int e);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		in_degree[b]++;
		org[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		graph[0].push_back(i);
		graph[i].push_back(0);
		graph[i].push_back(504);
		graph[504].push_back(i);
	}

	int l = 0, r = M;
	while (l < r) {
		int mid = (l + r) / 2;
		memset(flow, 0, sizeof(flow));
		for (int i = 0; i < 505; i++) {
			for (int j = 0; j < 505; j++) cap[i][j] = org[i][j];
		}

		int sum = 0;

		for (int i = 1; i <= N; i++) {
			cap[0][i] = max(0, in_degree[i] - mid);
			cap[i][504] = max(0, mid - in_degree[i]);
			sum += cap[0][i];
		}

		int m = find_Max(0, 504);

		if (m == sum) r = mid;
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