#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const long long INF = 1000000000000000;

struct cmp {
	bool operator() (pair<long long, pair<int, int>> A, pair<long long, pair<int, int>> B) {
		return A.first > B.first;
	}
};

long long ans = INF;
long long N, M;
long long map[305][305];
int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
long long dist[305][305];

void Dijkstra();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -2) map[i][j] = 0;
		}
	}
	Dijkstra();
	for (int i = 1; i <= N; i++) ans = min(ans, dist[i][1]);
	for (int i = 1; i <= M; i++) ans = min(ans, dist[N][i]);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void Dijkstra() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) dist[i][j] = INF;
	}
	priority_queue < pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, cmp> pq;
	for (int i = 1; i <= M; i++) {
		if (map[1][i] != -1) {
			pq.push({ map[1][i], {i, 1} });
			dist[1][i] = map[1][i];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (map[i][M] != -1) {
			pq.push({ map[i][M], {M, i} });
			dist[i][M] = map[i][M];
		}
	}	
	while (pq.size()) {
		pair<long long, pair<int, int>> t = pq.top();
		pq.pop();
		int x = t.second.first;
		int y = t.second.second;
		long long val = t.first;
		if (dist[y][x] < val) continue;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
			if (map[ny][nx] == -1) continue;
			long long new_val = val + map[ny][nx];
			if (dist[ny][nx] > new_val) {
				dist[ny][nx] = new_val;
				pq.push({ new_val, {nx,ny} });
			}
		}
	}
}