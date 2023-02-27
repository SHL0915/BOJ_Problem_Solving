#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int kx[8] = { -2,-1,1,2,2,1,-1,-2 };
int ky[8] = { 1,2,2,1,-1,-2,-2,-1 };
int bx[4] = { -1,1,1,-1 };
int by[4] = { 1,1,-1,-1 };
int rx[4] = { -1,0,1,0 };
int ry[4] = { 0,1,0,-1 };

int N;
int arr[11][11];
int mark[11][11][3][101];
pii S, E;
queue <pair<pii, pair<pii, int>>> q;

void BFS();

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) S = { j,i };
			if (arr[i][j] == N * N) E = { j,i };
		}
	}

	for (int i = 0; i < 3; i++) q.push({ S,{{i,1},0} });
	
	memset(mark, -1, sizeof(mark));
	while (q.size()) BFS();

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++) if(mark[E.second][E.first][i][N * N] != -1) ans = min(ans, mark[E.second][E.first][i][N * N]);	
	cout << ans;
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

void BFS() {
	pair<pii, pair<pii, int>> f = q.front(); q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int type = f.second.first.first;
	int target = f.second.first.second;
	int d = f.second.second;

	if (target > N * N) return;
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (mark[y][x][type][target] != -1) return;
	mark[y][x][type][target] = d;
	if (arr[y][x] == target) target++;

	for (int i = 0; i < 3; i++) {
		if (i == type) continue;
		q.push({ {x,y}, {{i,target}, d + 1} });
	}

	if (type == 0) {
		for (int i = 0; i < 8; i++) {
			int nx = x + kx[i];
			int ny = y + ky[i];
			if (nx < 0 || nx >= N || y < 0 || y >= N) continue;
			q.push({ {nx,ny}, {{type, target},d + 1} });
		}
	}
	else if (type == 1) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = x + i * bx[j];
				int ny = y + i * by[j];
				if (nx < 0 || nx >= N || y < 0 || y >= N) continue;
				q.push({ {nx,ny}, {{type, target},d + 1} });
			}
		}
	}
	else {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = x + i * rx[j];
				int ny = y + i * ry[j];
				if (nx < 0 || nx >= N || y < 0 || y >= N) continue;
				q.push({ {nx,ny}, {{type, target},d + 1} });
			}
		}
	}

	return;
}