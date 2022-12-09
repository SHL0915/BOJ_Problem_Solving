#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, room, max_cnt, max_2_cnt;
int arr[50][50];
int mark[50][50];
int area[2501];

void DFS(int x, int y, int color);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0) {
				cnt = 0;
				room++;
				DFS(j, i, room);
				area[room] = cnt;
			}
		}
	}
	for (int i = 1; i <= room; i++) max_cnt = max(max_cnt, area[i]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i != N - 1 && mark[i][j] != mark[i + 1][j]) max_2_cnt = max(max_2_cnt, area[mark[i][j]] + area[mark[i + 1][j]]);
			if (j != M - 1 && mark[i][j] != mark[i][j + 1]) max_2_cnt = max(max_2_cnt, area[mark[i][j]] + area[mark[i][j + 1]]);
		}
	}
	cout << room << '\n' << max_cnt << '\n' << max_2_cnt;
	return 0;
}

void DFS(int x, int y, int color) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = color;
	cnt++;
	if (!(arr[y][x] & 1)) DFS(x - 1, y, color);
	if (!(arr[y][x] & 2)) DFS(x, y - 1, color);
	if (!(arr[y][x] & 4)) DFS(x + 1, y, color);
	if (!(arr[y][x] & 8)) DFS(x, y + 1, color);
}