#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000000;

int N, M;
long long dist[101][101];

void FW();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		long long A, B, C;
		cin >> A >> B >> C;
		dist[A][B] = min(dist[A][B], C);
	}
	FW();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}

void FW() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}
}