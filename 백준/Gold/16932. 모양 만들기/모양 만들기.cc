#include <bits/stdc++.h>
using namespace std;

int N, M, shape, cnt, ans;
int arr[1005][1005];
int area[1000001];
int mark[1005][1005];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
set <int> s;

void DFS(int x, int y, int color);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (mark[i][j] == 0 && arr[i][j] == 1) {
				cnt = 0;
				shape++;
				DFS(j, i, shape);
				area[shape] = cnt;
			}
		}
	}	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) {
				s.clear();
				cnt = 1;
				for (int k = 0; k < 4; k++) {
					int x = j + dx[k];
					int y = i + dy[k];
					if (mark[y][x] == 0) continue;
					if (s.count(mark[y][x]) == 0) {
						cnt += area[mark[y][x]];
						s.insert(mark[y][x]);
					}
				}
				ans = max(ans, cnt);
			}
		}		
	}
	cout << ans;
	return 0;
}

void DFS(int x, int y, int color) {
	if (x < 1 || x > M || y < 1 || y > N) return;
	if (arr[y][x] == 0) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = color;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS(nx, ny, color);
	}
}