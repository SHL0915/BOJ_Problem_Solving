#include <iostream>
using namespace std;

int R, C, K, ans;
char map[5][5];

void BackTracking(int x, int y, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) map[i][j] = s[j];
	}
	BackTracking(0, R - 1, 0);
	cout << ans;
	return 0;
}

void BackTracking(int x, int y, int k) {
	map[y][x] = 1;
	if (k == K - 1) {
		if (x == C - 1 && y == 0) ans++;
	}
	else {
		if (x > 0 && map[y][x - 1] == '.') BackTracking(x - 1, y, k + 1);		
		if (x < C - 1 && map[y][x + 1] == '.') BackTracking(x + 1, y, k + 1);
		if (y > 0 && map[y - 1][x] == '.') BackTracking(x, y - 1, k + 1);
		if (y < R - 1 && map[y + 1][x] == '.') BackTracking(x, y + 1, k + 1);
	}
	map[y][x] = '.';
	return;
}