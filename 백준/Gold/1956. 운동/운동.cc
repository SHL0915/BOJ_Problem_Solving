#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
int graph[401][401];

void solve() {
	cin >> N >> M;
	memset(graph, INF, sizeof(graph));
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}
	int ans = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j == i) continue;
			ans = min(ans, graph[i][j] + graph[j][i]);
		}
	}
	if (ans == INF) cout << -1;
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