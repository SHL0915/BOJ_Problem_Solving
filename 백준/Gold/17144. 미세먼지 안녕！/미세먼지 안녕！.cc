#include <iostream>
#include <vector>
using namespace std;

int R, C, T, flag, ans;
int map[50][50];
int temp[50][50];
pair <int, int> U, D;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && flag == 0) {
				flag = 1;
				D = { j,i };
				U = { j,i + 1 };
			}
		}
	}
	while (T--) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) temp[i][j] = 0;
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] > 0) {
					int cnt = 0;
					if (i > 0 && map[i - 1][j] != -1) {
						temp[i - 1][j] += map[i][j] / 5;
						cnt++;
					}
					if (i < R - 1 && map[i + 1][j] != -1) {
						temp[i + 1][j] += map[i][j] / 5;
						cnt++;
					}
					if (j > 0 && map[i][j - 1] != -1) {
						temp[i][j - 1] += map[i][j] / 5;
						cnt++;
					}
					if (j < C - 1 && map[i][j + 1] != -1) {
						temp[i][j + 1] += map[i][j] / 5;
						cnt++;
					}
					map[i][j] -= cnt * (map[i][j] / 5);
				}
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) map[i][j] += temp[i][j];
		}
		for (int i = U.second + 1; i < R - 1; i++) map[i][0] = map[i + 1][0];
		for (int i = 0; i < C - 1; i++) map[R - 1][i] = map[R - 1][i + 1];
		for (int i = R - 1; i > U.second; i--) map[i][C - 1] = map[i - 1][C - 1];
		for (int i = C - 1; i > 1; i--) map[U.second][i] = map[U.second][i - 1];
		map[U.second][1] = 0;
		for (int i = D.second - 1; i > 0; i--) map[i][0] = map[i - 1][0];
		for (int i = 0; i < C - 1; i++) map[0][i] = map[0][i + 1];
		for (int i = 0; i < D.second; i++) map[i][C - 1] = map[i + 1][C - 1];
		for (int i = C - 1; i > D.first + 1; i--) map[D.second][i] = map[D.second][i - 1];
		map[D.second][1] = 0;		
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) ans += map[i][j];
	}
	ans += 2;
	cout << ans;
	return 0;
}