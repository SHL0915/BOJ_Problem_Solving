#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
const int INF = 0x3f3f3f3f;

struct cmp {
	bool operator() (piii A, piii B) {
		return A.first > B.first;
	}
};

int M, N;
int city[1001][1001];
int dist[1001][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Dijkstra(int start_x, int start_y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == -1) city[i][j] = INF;
		}
	}
	Dijkstra(0, 0);
	if (dist[M - 1][N - 1] == INF) cout << -1;
	else cout << dist[M - 1][N - 1];
	return 0;
}

void Dijkstra(int start_x, int start_y) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) dist[i][j] = INF;
	}
	priority_queue <piii, vector<piii>, cmp> pq;
	dist[start_y][start_x] = city[start_y][start_x];
	pq.push({ city[start_y][start_x], {start_x, start_y} });
	while (pq.size()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int val = pq.top().first;
		pq.pop();
		if (dist[y][x] < val) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;
			int new_val = val + city[ny][nx];
			if (dist[ny][nx] > new_val) {
				dist[ny][nx] = new_val;
				pq.push({ new_val, {nx,ny} });
			}
		}
	}
}