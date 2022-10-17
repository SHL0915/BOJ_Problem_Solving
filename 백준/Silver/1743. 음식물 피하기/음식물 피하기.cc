#include <iostream>
using namespace std;

int hallway[100][100];
int mark[100][100];
int N, M, K;
int cnt, ans;

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		hallway[y - 1][x - 1] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0 && hallway[i][j] == 1) {
				cnt = 0;
				DFS(j, i);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
	return 0;
}

void DFS(int x, int y) {
	if (hallway[y][x] == 0) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	cnt++;
	if (x > 0) DFS(x - 1, y);
	if (x < M - 1) DFS(x + 1, y);
	if (y > 0 ) DFS(x, y - 1);
	if (y < N - 1) DFS(x, y + 1);
	return;
}