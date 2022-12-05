#include <bits/stdc++.h>
using namespace std;

int R, C;
int arr[500][500];
int mark[500][500];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == 'S') arr[i][j] = 1;
			else if (s[j] == 'W') arr[i][j] = 2;
			else arr[i][j] = -1;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 2 && mark[i][j] == 0) {
				DFS(j, i);
			}
		}
	}
	cout << 1 << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			switch (arr[i][j]) {
			case 1: cout << 'S'; break;
			case 2: cout << 'W'; break;
			case -1: cout << 'D'; break;
			}
		}
		cout << '\n';
	}
	return 0;
}

void DFS(int x, int y) {
	if (x < 0 || x > C - 1 || y < 0 || y > R - 1) return;
	if (arr[y][x] == -1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (arr[y][x] == 1) {
		cout << 0;
		exit(0);
	}
	DFS(x - 1, y);
	DFS(x + 1, y);
	DFS(x, y - 1);
	DFS(x, y + 1);
}