#include <iostream>
#include <utility>
using namespace std;

int N, min_x = 100, min_y = 100, max_x, max_y;
string input;
char map[100][100];
pair<int, int> pos;
int dir;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> input;
	pos = { 50, 50 };
	map[pos.second][pos.first] = '.';
	for (int i = 0; i < N; i++) {
		switch (input[i]) {
		case 'F': {
			switch (dir) {
			case 0: pos.second--; break;
			case 1: pos.first++; break;
			case 2: pos.second++; break;
			case 3: pos.first--; break;
			}
			map[pos.second][pos.first] = '.';
			break;
		}
		case 'L': dir++; dir %= 4; break;
		case 'R': dir--; if (dir < 0) dir += 4; break;
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == '.') {
				min_x = min(min_x, j);
				min_y = min(min_y, i);
				max_x = max(max_x, j);
				max_y = max(max_y, i);
			}
		}
	}
	for (int i = max_y; i >= min_y; i--) {
		for (int j = min_x; j <= max_x; j++) {
			if (map[i][j] == 0) cout << '#';
			else cout << '.';
		}
		cout << '\n';
	}
	return 0;
}