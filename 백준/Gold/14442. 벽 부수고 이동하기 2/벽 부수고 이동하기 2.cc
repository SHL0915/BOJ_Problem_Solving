#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1234567890;

int N, M, K, ans = INF;
int map[1000][1000];
int mark[1000][1000][11];
queue <pair<pair<int, int>, pair<int, int>>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) map[i][j] = input[j] - '0';
	}
	q.push({ {0,0},{1,0} });
	while (q.size()) BFS();
	for (int i = 0; i <= K; i++) {
		if (mark[N - 1][M - 1][i] != 0) ans = min(ans, mark[N - 1][M - 1][i]);		
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void BFS() {
	pair<pair<int, int>, pair<int, int>> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second.first;
	int cnt = f.second.second;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] == 1) cnt++;
	if (cnt > K) return;
	if (mark[y][x][cnt] != 0) return;
	mark[y][x][cnt] = d;
	q.push({ {x + 1,y}, {d + 1, cnt} });
	q.push({ {x - 1,y}, {d + 1, cnt} });
	q.push({ {x,y + 1}, {d + 1, cnt} });
	q.push({ {x,y - 1}, {d + 1, cnt} });
}