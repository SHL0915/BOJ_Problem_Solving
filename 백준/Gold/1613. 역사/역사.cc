#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, K, S;
int graph[401][401];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	memset(graph, INF, sizeof(graph));
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 0;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}
	cin >> S;
	for (int i = 0; i < S; i++) {
		int a, b;
		cin >> a >> b;
		if (graph[a][b] == 0) cout << -1 << '\n';
		else if (graph[b][a] == 0) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}