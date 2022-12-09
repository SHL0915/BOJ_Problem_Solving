#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> piiii;
const int INF = 0x3f3f3f3f;

int K, W, H, ans = INF;
int arr[200][200];
int mark[200][200][31];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ddx[8] = { 2,2,1,1,-1,-1,-2,-2 };
int ddy[8] = { 1,-1,2,-2,2,-2,1,-1 };
queue <piiii> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> arr[i][j];
	}
	q.push({ {0,0},{1,0} });
	while (q.size()) BFS();
	for (int i = 0; i <= K; i++) if (mark[H - 1][W - 1][i] != 0) ans = min(ans, mark[H - 1][W - 1][i]);
	if (ans == INF) cout << -1;
	else cout << ans - 1;
	return 0;
}

void BFS() {
	piiii f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second.first;
	int k = f.second.second;
	if (x < 0 || x > W - 1 || y < 0 || y > H - 1) return;
	if (arr[y][x] == 1) return;
	if (k > K) return;
	if (mark[y][x][k] != 0) return;
	mark[y][x][k] = d;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny},{d + 1,k} });
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + ddx[i];
		int ny = y + ddy[i];
		q.push({ {nx,ny},{d + 1,k + 1} });
	}
}