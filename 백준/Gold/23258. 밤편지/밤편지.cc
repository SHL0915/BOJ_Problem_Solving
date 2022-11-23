#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, Q;
int dist[301][301][302];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dist[i][j][0];
			if (dist[i][j][0] == 0) dist[i][j][0] = INF;
		}
	}	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) dist[i][j][k] = min(dist[i][j][k - 1], dist[i][k][k - 1] + dist[k][j][k - 1]);
		}
	}
	for (int i = 0; i < Q; i++) {
		int C, S, E;
		cin >> C >> S >> E;
		if (S == E) cout << 0 << '\n';
		else if (dist[S][E][C - 1] == INF) cout << -1 << '\n';
		else cout << dist[S][E][C - 1] << '\n';
	}
	return 0;
}