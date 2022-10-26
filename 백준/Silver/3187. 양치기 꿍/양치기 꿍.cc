#include <iostream>
using namespace std;

int R, C, sheep_num, wolf_num, result_sheep, result_wolf;
char field[250][250];
int mark[250][250];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			field[i][j] = input[j];
			if (field[i][j] == '#') mark[i][j] = 1;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mark[i][j] == 0) {
				sheep_num = 0;
				wolf_num = 0;
				DFS(j, i);
				if (sheep_num > wolf_num) result_sheep += sheep_num;
				else result_wolf += wolf_num;
			}
		}
	}
	cout << result_sheep << " " << result_wolf;
	return 0;
}

void DFS(int x, int y) {
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (field[y][x] == 'v') wolf_num++;
	else if (field[y][x] == 'k') sheep_num++;
	if (x > 0) DFS(x - 1, y);
	if (x < C - 1) DFS(x + 1, y);
	if (y > 0) DFS(x, y - 1);
	if (y < R - 1) DFS(x, y + 1);
	return;
}