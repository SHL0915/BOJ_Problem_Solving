#include <iostream>
using namespace std;

int R, C, flag;
char map[12][12];
int mark[12][12];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i <= R + 1; i++) {
		map[i][0] = 'X';
		mark[i][0] = 1;
		map[i][C + 1] = 'X';
		mark[i][C + 1] = 1;
	}
	for (int i = 0; i <= C + 1; i++) {
		map[0][i] = 'X';
		mark[0][i] = 1;
		map[R + 1][i] = 'X';
		mark[R + 1][i] = 1;
	}
	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) {
			map[i][j] = input[j - 1];
			if (map[i][j] == 'X') mark[i][j] = 1;
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (mark[i][j] == 0) {
				DFS(j, i);
				break;
			}
		}
	}
	if (flag == 1) cout << 1;
	else cout << 0;
	return 0;
}

void DFS(int x, int y) {
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	int sum = 0;
	if (map[y - 1][x] == 'X') sum++;
	if (map[y + 1][x] == 'X') sum++;
	if (map[y][x - 1] == 'X') sum++;
	if (map[y][x + 1] == 'X') sum++;
	if (sum >= 3) flag = 1;
	if (x > 1) DFS(x - 1, y);
	if (x < C) DFS(x + 1, y);
	if (y > 1) DFS(x, y - 1);
	if (y < R - 1) DFS(x, y + 1);
	return;
}