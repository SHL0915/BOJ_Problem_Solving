#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, L, R, cnt, tot, day;
int arr[50][50];
int mark[50][50];
pair<int, int> c[2501];

int Absol(int A) {
	if (A >= 0) return A;
	else return -A;
}
void DFS(int x, int y, int area);
void color();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	while (1) {
		int flag = 0;
		int ar = 1;
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mark[i][j] == 0) {
					cnt = 0;
					tot = 0;
					DFS(j, i, ar);
					if (cnt >= 2) flag = 1;
					c[ar] = { tot,cnt };
					ar++;
				}
			}
		}
		color();
		if (flag == 1) day++;
		else break;
	}
	cout << day;
	return 0;
}

void DFS(int x, int y, int area) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = area;
	cnt++;
	tot += arr[y][x];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;
		int val = Absol(arr[y][x] - arr[ny][nx]);
		if (val > R || val < L) continue;
		DFS(nx, ny, area);
	}
}

void color() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = c[mark[i][j]].first / c[mark[i][j]].second;
		}
	}
}