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

struct qdata {
	int x, y, type, target, d, s;
};

int N;
pii S, E, cmp = { -1,-1 };
int arr[11][11];
pii mark[11][11][3][101];
queue <qdata> q;

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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l <= N * N; l++) mark[i][j][k][l] = cmp;
			}
		}
	}

	q.push({ S.first, S.second, 0, 1, 0, 0 });
	q.push({ S.first, S.second, 1, 1, 0, 0 });
	q.push({ S.first, S.second, 2, 1, 0, 0 });

	while (q.size()) BFS();

	pii ans = { 0x3f3f3f3f, 0x3f3f3f3f };
	for (int i = 0; i < 3; i++) {
		if(mark[E.second][E.first][i][N * N] != cmp) ans = min(ans, mark[E.second][E.first][i][N * N]);
	}

	cout << ans.first << " " << ans.second;
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
	qdata f = q.front(); q.pop();
	int x = f.x;
	int y = f.y;
	int type = f.type;
	int target = f.target;
	int d = f.d;
	int s = f.s;

	if (target > N * N) return;
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (mark[y][x][type][target] != cmp) {
		if (mark[y][x][type][target] <= make_pair(d, s)) return;
	}

	mark[y][x][type][target] = { d,s };
	if (arr[y][x] == target) target++;
	
	if (type == 0) {
		for (int i = 0; i < 8; i++) {
			int nx = x + kx[i];
			int ny = y + ky[i];
			if (nx < 0 || nx >= N || y < 0 || y >= N) continue;
			q.push({ nx,ny, type, target, d + 1, s });
		}
	}
	else if (type == 1) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = x + i * bx[j];
				int ny = y + i * by[j];
				if (nx < 0 || nx >= N || y < 0 || y >= N) continue;
				q.push({ nx,ny, type, target, d + 1, s });
			}
		}
	}
	else {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = x + i * rx[j];
				int ny = y + i * ry[j];
				if (nx < 0 || nx >= N || y < 0 || y >= N) continue;
				q.push({ nx,ny, type, target, d + 1, s });
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (i == type) continue;
		q.push({ x,y, i, target, d + 1, s + 1 });
	}

	return;
}