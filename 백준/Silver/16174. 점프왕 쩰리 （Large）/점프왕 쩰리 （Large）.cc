#include <iostream>
using namespace std;

int N;
int map[64][64];
int mark[64][64];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
	DFS(0, 0);
	cout << "Hing";
	return 0;
}

void DFS(int x, int y) {
	if (x >= N || y >= N) return;
	if (x == N - 1 && y == N - 1) {
		cout << "HaruHaru";
		exit(0);
	}
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	DFS(x + map[y][x], y);
	DFS(x, y + map[y][x]);
	return;
}