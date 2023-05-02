#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, mx;
vector <int> graph[55];
int len[3];
int edge[55][55][105];
int table[55][3];

void solve() {
	cin >> N >> M >> len[0] >> len[1] >> len[2];
	mx = max({ len[0],len[1],len[2] });

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		queue <pii> q;
		q.push({ i, 0 });
		while (q.size()) {
			pii f = q.front(); q.pop();
			int now = f.first, d = f.second;
			if (d > mx || edge[i][now][d]) continue;
			edge[i][now][d] = 1;
			for (int i = 0; i < graph[now].size(); i++) q.push({ graph[now][i], d + 1 });
		}
	}

	memset(table, INF, sizeof(table));
	table[N][0] = 0;
	table[N][1] = 0;
	table[N][2] = 0;

	for (int i = 0; i < N * N; i++) {
		for (int u = 1; u <= N; u++) {
			for (int v = 1; v <= N; v++) {
				for (int k = 0; k < 3; k++) {
					int dist = max({ table[u][0],table[u][1],table[u][2] }) + 1;
					if (edge[u][v][len[k]] && dist < table[v][k]) table[v][k] = dist;
				}
			}
		}
	}

	int ans = max({ table[1][0], table[1][1], table[1][2] });
	if (ans == INF) cout << "IMPOSSIBLE";
	else cout << ans;

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