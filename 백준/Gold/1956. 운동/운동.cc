#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000000;

long long V, E;
long long dist[401][401];
long long ans = INF;

void FW();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) dist[i][j] = INF;
	}
	for (int i = 0; i < E; i++) {
		long long A, B, C;
		cin >> A >> B >> C;
		dist[A][B] = min(dist[A][B], C);
	}
	FW();
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if(i == j) ans = min(ans, dist[i][j]);
			else ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void FW() {
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
}