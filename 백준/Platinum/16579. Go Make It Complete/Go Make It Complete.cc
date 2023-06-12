#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
int adj[505][505];
int degree[505];
queue <pii> q[1005];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (adj[i][j]) continue;
			q[degree[i] + degree[j]].push({ i,j });
			cnt++;
		}
	}

	for (int i = 2 * N; i >= 0; i--) {
		while (q[i].size()) {
			pii f = q[i].front(); q[i].pop();
			int a = f.first, b = f.second;
			if (adj[a][b] == 1) continue;

			adj[a][b] = 1; adj[b][a] = 1;
			degree[a]++; degree[b]++;
			cnt--;

			for (int j = 1; j <= N; j++) {
				if (j == a || adj[a][j]) continue;
				q[degree[j] + degree[a]].push({ j, a });
			}

			for (int j = 1; j <= N; j++) {
				if (j == b || adj[b][j]) continue;
				q[degree[j] + degree[b]].push({ j, b });
			}
		}

		if (cnt == 0) {
			cout << i;
			break;
		}
	}

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