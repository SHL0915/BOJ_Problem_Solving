#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
int arr[10000][500];
int mark[10000][500];

bool DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == 'x') arr[i][j] = 1;
		}
	}
	for (int i = 0; i < R; i++) DFS(0, i);
	cout << ans;
	return 0;
}

bool DFS(int x, int y) {
	if (x < 0 || x > C - 1 || y < 0 || y > R - 1) return false;
	if (arr[y][x] == 1) return false;
	if (mark[y][x] != 0) return false;
	mark[y][x] = 1;
	if (x == C - 1) {
		ans++;
		return true;
	}
	for (int i = -1; i < 2; i++) {
		if (DFS(x + 1, y + i) == true) return true;
	}
	return false;
}
