#include <iostream>
using namespace std;

int T, M, N, K, cnt;
int field[50][50];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		cnt = 0;
		for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) field[i][j] = 1;
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			field[Y][X] = 0;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 0) {
					cnt++;
					DFS(j, i);
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

void DFS(int x, int y) {
	if (field[y][x] == 1) return;
	field[y][x] = 1;
	if (x > 0) DFS(x - 1, y);
	if (x < M - 1) DFS(x + 1, y);
	if (y > 0) DFS(x, y - 1);
	if (y < N - 1) DFS(x, y + 1);
	return;
}