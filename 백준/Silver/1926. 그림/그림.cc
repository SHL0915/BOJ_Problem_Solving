#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, ans, cnt, num;
int arr[501][501];
int mark[501][501];

void DFS(int x, int y);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && mark[i][j] == 0) {
				num++;
				cnt = 0;
				DFS(j, i);
				ans = max(ans, cnt);
			}
		}
	}
	cout << num << '\n' << ans;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void DFS(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (arr[y][x] == 0) return;
	if (mark[y][x]) return;
	mark[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS(nx, ny);
	}
	return;
}