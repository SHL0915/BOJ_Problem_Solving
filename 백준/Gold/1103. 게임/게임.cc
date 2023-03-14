#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, ans;
int arr[51][51];
int mark[51][51];
int finished[51][51];
int table[51][51];

void DFS(int x, int y);
int DP(int x, int y);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'H') arr[i][j] = -1;
			else arr[i][j] = s[j] - '0';
		}
	}

	DFS(0, 0);

	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void DFS(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (arr[y][x] == -1) return;
	mark[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * arr[y][x];
		int ny = y + dy[i] * arr[y][x];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (arr[ny][nx] == -1) continue;

		if (mark[ny][nx] == 0) DFS(nx, ny);
		else if (finished[ny][nx] == 0) {
			cout << -1;
			exit(0);
		}
	}

	finished[y][x] = 1;
}

int DP(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return 0;
	if (arr[y][x] == -1) return 0;
	int& ret = table[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * arr[y][x];
		int ny = y + dy[i] * arr[y][x];
		ret = max(ret, 1 + DP(nx, ny));
	}
	return ret;
}