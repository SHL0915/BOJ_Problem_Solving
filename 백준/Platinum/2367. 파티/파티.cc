#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, D;
vector <int> graph[305];
int cap[305][305], flow[305][305];
int parent[305];

int find_Max(int s, int e);

void solve() {
	cin >> N >> K >> D;
	for (int i = 1; i <= D; i++) {
		int a; cin >> a;
		graph[0].push_back(i);
		graph[i].push_back(0);
		cap[0][i] = a;
	}
	for (int i = D + 1; i <= N + D; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			graph[a].push_back(i);
			graph[i].push_back(a);
			cap[a][i] = 1;
		}
		graph[i].push_back(N + D + 1);
		graph[N + D + 1].push_back(i);
		cap[i][N + D + 1] = K;
	}
	cout << find_Max(0, N + D + 1);
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