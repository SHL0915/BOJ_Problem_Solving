#include <iostream>
#include <queue>
using namespace std;

int N, M, start_x, start_y, end_x, end_y;
int map[1001][1001];
int mark[1001][1001][2];
int row[1001];
int col[1001];
queue <pair<pair<int, int>, pair<int, int>>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	cin >> start_y >> start_x >> end_y >> end_x;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> map[i][j];
	}
	q.push({ {start_x,start_y},{0,0} });
	while (q.size()) BFS();
	cout << -1;
	return 0;
}

void BFS() {
	pair < pair<int, int>, pair<int, int>> temp = q.front();
	q.pop();
	int x = temp.first.first;
	int y = temp.first.second;
	int d = temp.second.first;
	int mode = temp.second.second;
	if (x < 1 || x > M || y < 1 || y > N) return;
	if (mode == 0 && mark[y][x][0] != 0) return;
	else if (mode == 1 && mark[y][x][1] != 0) return;
	if (x == end_x && y == end_y) {
		cout << d;
		exit(0);
	}
	mark[y][x][1] = 1;
	if (mode == 0) mark[y][x][0] = 1;
	if (mode == 0) {
		if (row[y] == 0) {
			for (int i = 1; i < x; i++) q.push({ {i, y}, {d + 1, 1} });
			for (int i = x + 1; i <= M; i++) q.push({ {i, y}, {d + 1, 1} });
			row[y] = 1;
		}
		if (col[x] == 0) {
			for (int i = 1; i < y; i++) q.push({ {x, i}, {d + 1, 1} });
			for (int i = y + 1; i <= N; i++) q.push({ {x, i}, {d + 1, 1} });
			col[x] = 1;
		}
	}
	q.push({ {x - map[y][x], y}, {d + 1, mode} });
	q.push({ {x + map[y][x], y}, {d + 1, mode} });
	q.push({ {x, y - map[y][x]}, {d + 1, mode} });
	q.push({ {x, y + map[y][x]}, {d + 1, mode} });
}