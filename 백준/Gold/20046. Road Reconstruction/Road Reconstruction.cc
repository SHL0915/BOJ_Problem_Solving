#include <iostream>
#include <queue>
using namespace std;

const int INF = 1234567890;

struct cmp {
	bool operator() (pair<int, pair<int, int>> A, pair<int, pair<int, int>> B) {
		return A > B;
	}
};

int M, N;
int map[1000][1000];
int dist[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Dijkstra(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
	if (map[0][0] == -1) {
		cout << -1;
		return 0;
	}
	Dijkstra(0, 0);
	if (dist[M - 1][N - 1] == INF) cout << -1;
	else cout << dist[M - 1][N - 1];
	return 0;
}

void Dijkstra(int x, int y) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) dist[i][j] = INF;
	}
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
	pq.push({ map[y][x],{x,y}});
	dist[y][x] = map[y][x];
	while (pq.size()) {
		pair<int, pair<int, int>> t = pq.top();
		pq.pop();
		int now_x = t.second.first;
		int now_y = t.second.second;
		int now_val = t.first;
		if (dist[now_y][now_x] < now_val) continue;
		for (int i = 0; i < 4; i++) {
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;
			if (map[ny][nx] == -1) continue;
			int n_val = now_val + map[ny][nx];
			if (dist[ny][nx] > n_val) {
				dist[ny][nx] = n_val;
				pq.push({ n_val,{nx,ny} });
			}
		}
	}
}