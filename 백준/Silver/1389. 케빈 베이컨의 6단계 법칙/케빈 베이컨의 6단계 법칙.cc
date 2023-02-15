#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;

int N, M;
int graph[101][101];
pii sum[101];

void solve() {
	cin >> N >> M;
	memset(graph, INF, sizeof(graph));
	for (int i = 1; i <= N; i++) graph[i][i] = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		sum[i].first = 0;
		sum[i].second = i;
		for (int j = 1; j <= N; j++) sum[i].first += graph[i][j];
	}
	sort(sum + 1, sum + N + 1);
	cout << sum[1].second;
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