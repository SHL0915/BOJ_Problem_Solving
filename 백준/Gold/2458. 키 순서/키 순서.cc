#include <iostream>
using namespace std;

const int INF = 1234567890;

int N, M, ans;
long long dist[501][501];
int cnt[501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) dist[i][j] = INF;		
	}
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		dist[A][B] = 0;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				cnt[i]++;
				continue;
			}
			else if (dist[i][j] == 0) {
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	for (int i = 1; i <= N; i++) if (cnt[i] == N) ans++;
	cout << ans;
	return 0;
}