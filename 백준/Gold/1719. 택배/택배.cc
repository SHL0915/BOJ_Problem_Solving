#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
int graph[201][201];
int path[201][201];

void solve() {
	cin >> N >> M;
	memset(graph, INF, sizeof(graph));
	for (int i = 1; i <= N; i++) graph[i][i] = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (graph[a][b] > c) {
			graph[a][b] = c;
			path[a][b] = b;
		}
		if (graph[b][a] > c) {
			graph[b][a] = c;
			path[b][a] = a;
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << "- ";
			else cout << path[i][j] << " ";
		}
		cout << '\n';
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