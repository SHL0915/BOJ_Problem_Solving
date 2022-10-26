#include <iostream>
#include <vector>
using namespace std;

int N, M, ans;
vector<pair<int, int>> zero;
int map[8][8];
int copymap[8][8];
int mark[8][8];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zero.push_back({ i,j });
		}
	}
	for (int i = 0; i < zero.size(); i++) {
		for (int j = i + 1; j < zero.size(); j++) {
			for (int k = j + 1; k < zero.size(); k++) {
				int cnt = 0;
				for (int n = 0; n < N; n++) {
					for (int m = 0; m < M; m++) {
						copymap[n][m] = map[n][m];
						mark[n][m] = 0;
					}
				}
				copymap[zero[i].first][zero[i].second] = 1;
				copymap[zero[j].first][zero[j].second] = 1;
				copymap[zero[k].first][zero[k].second] = 1;
				for (int n = 0; n < N; n++) {
					for (int m = 0; m < M; m++) {
						if (copymap[n][m] == 2 && mark[n][m] == 0) DFS(m, n);
					}
				}
				for (int n = 0; n < N; n++) {
					for (int m = 0; m < M; m++) {
						if (copymap[n][m] == 0) cnt++;
					}
				}
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
	return 0;
}

void DFS(int x, int y) {
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (copymap[y][x] == 1) return;
	copymap[y][x] = 2;
	if (x > 0) DFS(x - 1, y);
	if (x < M - 1) DFS(x + 1, y);
	if (y > 0) DFS(x, y - 1);
	if (y < N - 1) DFS(x, y + 1);
}