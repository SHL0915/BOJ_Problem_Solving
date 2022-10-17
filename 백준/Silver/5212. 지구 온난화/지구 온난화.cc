#include <iostream>
#include <vector>
using namespace std;

int R, C;
char map[10][10];
vector <pair <int, int>> idx;
int l = 11, r = -1, u = 11, d = -1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) map[i][j] = s[j];
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') {
				int cnt = 0;
				if (j > 0 && map[i][j - 1] == 'X') cnt++;
				if (j < C - 1 && map[i][j + 1] == 'X') cnt++;
				if (i > 0 && map[i - 1][j] == 'X') cnt++;
				if (i < R - 1 && map[i + 1][j] == 'X') cnt++;
				if (cnt < 2) idx.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < idx.size(); i++) map[idx[i].first][idx[i].second] = '.';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') {
				if (j <= l) l = j;
				if (j >= r) r = j;
				if (i <= u) u = i;
				if (i >= d) d = i;
			}
		}
	}
	for (int i = u; i <= d; i++) {
		for (int j = l; j <= r; j++)
			cout << map[i][j];
		cout << "\n";
	}
	return 0;
}