#include <iostream>
using namespace std;

int R, C, wolves, sheep, ans_wolves, ans_sheep;
char backyard[250][250];
int mark[250][250];

void DFS(int i, int j);

int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			backyard[i][j] = s[j];
			if (s[j] == '#') mark[i][j] = 1;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			sheep = 0;
			wolves = 0;
			if (mark[i][j] == 0) {
				DFS(i, j);
				if (sheep > wolves) ans_sheep += sheep;
				else ans_wolves += wolves;
			}
			else continue;
		}
	}
	cout << ans_sheep << " " << ans_wolves;
	return 0;
}

void DFS(int i, int j) {
	if (mark[i][j] != 0) return;
	mark[i][j] = 1;
	if (backyard[i][j] == 'o') sheep++;
	else if (backyard[i][j] == 'v') wolves++;
	if (i > 0) DFS(i - 1, j);
	if (i < R - 1) DFS(i + 1, j);
	if (j > 0) DFS(i, j - 1);
	if (j < C - 1) DFS(i, j + 1);
	return;
}