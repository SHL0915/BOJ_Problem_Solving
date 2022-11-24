#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, pair<int, int>> plii;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (plii A, plii B) {
		return A.first > B.first;
	}
};

int N, M;
long long ans = INF;
long long village[301][301];
long long dist[301][301];
int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

void Dijkstra();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> village[i][j];
			if (village[i][j] == -2) village[i][j] = 0;
			if (village[i][j] == -1) village[i][j] = INF;
		}
	}
	Dijkstra();
	for (int i = 0; i < N; i++) ans = min(ans, dist[i][0]); // 0열에 도착
	for (int i = 0; i < M; i++) ans = min(ans, dist[N - 1][i]); // N-1행에 도착
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void Dijkstra() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) dist[i][j] = INF;
	}
	priority_queue<plii, vector<plii>, cmp> pq;
	for (int i = 0; i < M; i++) { // 0행에서 시작
		if (village[0][i] == INF) continue;
		pq.push({ village[0][i], {i, 0} });
		dist[0][i] = village[0][i];
	}
	for (int i = 0; i < N; i++) { // M-1열에서 시작
		if (village[i][M - 1] == INF) continue;
		pq.push({ village[i][M - 1], {M - 1, i} });
		dist[i][M - 1] = village[i][M - 1];
	}
	while (pq.size()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		long long val = pq.top().first;
		pq.pop();
		if (dist[y][x] < val) continue;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1) continue;
			if (village[ny][nx] == INF) continue;
			long long new_val = val + village[ny][nx];
			if (dist[ny][nx] > new_val) {
				dist[ny][nx] = new_val;
				pq.push({ new_val, {nx,ny} });
			}
		}
	}
}