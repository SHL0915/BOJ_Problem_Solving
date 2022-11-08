#include <iostream>
using namespace std;

int R, C, x, y;
char map[1001][1001];
string travel;
int mark[1001][1001];

void DFS(int x, int y, char c);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) map[i][j] = input[j - 1];
	}
	cin >> y >> x;
	cin >> travel;
	for (int i = 0; i < travel.length(); i++) {
		switch (travel[i]) {
		case 'U': y--; break;
		case 'D': y++; break;
		case 'L': x--; break;
		case 'R': x++; break;
		case 'W': DFS(x, y, map[y][x]); break;
		}
	}
	mark[y][x] = 1;
	if (x > 1) mark[y][x - 1] = 1;
	if (y > 1) mark[y - 1][x] = 1;
	if (x < C) mark[y][x + 1] = 1;
	if (y < R) mark[y + 1][x] = 1;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (mark[i][j] == 0) cout << '#';
			else cout << '.';
		}
		cout << '\n';
	}
	return 0;
}

void DFS(int x, int y, char c) {
	if (x < 1 || x > C || y < 1 || y > R) return;
	if (map[y][x] != c) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	DFS(x + 1, y, c);
	DFS(x - 1, y, c);
	DFS(x, y + 1, c);
	DFS(x, y - 1, c);
	return;
}