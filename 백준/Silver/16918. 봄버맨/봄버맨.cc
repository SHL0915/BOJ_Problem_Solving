#include <iostream>
#include <vector>
using namespace std;

int R, C, N;
int map[200][200];
vector <pair<int, int>> bomb;

void clear(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) if (input[j] == 'O') map[i][j] = 2;
	}
	N--;
	while (N--) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 0) map[i][j] = 2;
				else map[i][j]--;
				if (map[i][j] == 1) bomb.push_back({ j,i });
			}
		}
		N--;
		if (N < 0) break;
		while (bomb.size()) {
			int x = bomb.back().first;
			int y = bomb.back().second;
			bomb.pop_back();
			clear(x, y);
			clear(x - 1, y);
			clear(x + 1, y);
			clear(x, y - 1);
			clear(x, y + 1);
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0) cout << '.';
			else cout << 'O';
		}
		cout << '\n';
	}
	return 0;
}

void clear(int x, int y) {
	if (x < 0 || x >= C || y < 0 || y >= R) return;
	map[y][x] = 0;
}