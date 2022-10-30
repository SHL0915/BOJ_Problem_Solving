#include <iostream>
using namespace std;

int N, M, ans;
char room[50][50];
int mark[50][50];

void DFS(int x, int y, char c);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) room[i][j] = input[j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0) {
				ans++;
				DFS(j, i, room[i][j]);
			}
		}
	}
	cout << ans;
	return 0;
}

void DFS(int x, int y, char c) {
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (room[y][x] != c) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (c == '-') DFS(x + 1, y, c);
	else DFS(x, y + 1, c);
	return;
}