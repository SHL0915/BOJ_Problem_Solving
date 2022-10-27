#include <iostream>
#include <algorithm>
using namespace std;

int N, M, num, cnt, ans;
int paper[500][500];
int mark[500][500];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
			if (paper[i][j] == 0) mark[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0) {
				cnt = 0;
				num++;
				DFS(j, i);
				ans = max(ans, cnt);
			}
		}
	}
	cout << num << '\n' << ans;
	return 0;
}

void DFS(int x, int y) {
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	cnt++;
	if (x > 0) DFS(x - 1, y);
	if (x < M - 1) DFS(x + 1, y);
	if (y > 0) DFS(x, y - 1);
	if (y < N - 1) DFS(x, y + 1);
	return;
}