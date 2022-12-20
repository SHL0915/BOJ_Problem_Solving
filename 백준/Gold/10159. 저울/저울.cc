#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, M;
int graph[101][101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	memset(graph, INF, sizeof(graph));
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A][B] = 0;
	}	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}	
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (graph[i][j] == INF && graph[j][i] == INF) cnt++;			
		}
		cout << cnt << '\n';
	}
	return 0;
}