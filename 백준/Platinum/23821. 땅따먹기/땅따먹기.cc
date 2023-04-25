#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int N, M;
int arr[55][55];
int psum[55][55];
int ans[55][55];
ll bit[55];

int mark[55][55][55][55];
queue <pair<pii, pii>> q;

void BFS();
int check(pii a, pii b);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 1; j <= M; j++) {
			if (s[j - 1] == 'X') arr[i][j] = 1;
			else {
				if (s[j - 1] == 'A') q.push({ {j,i},{1,1} });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) psum[i][j] = arr[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
	}

	while (q.size()) BFS();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (bit[i] & (1LL << j)) cout << "Y";
			else cout << "N";
		}
		cout << '\n';
	}
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
	pair<pii, pii> f = q.front(); q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int w = f.second.first;
	int h = f.second.second;

	pii lu = { x,y };
	pii rd = { x + w - 1, y + h - 1 };

	ll add = 0;
	for (int i = x; i <= x + w - 1; i++) add |= (1LL << i);

	for (int i = y; i <= y + h - 1; i++) bit[i] |= add;

	if (x > 1) {
		lu = { x - 1, y };
		rd = { x - 1, y + h - 1 };
		if (check(lu, rd)) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i] - 1;
				int ny = y + dy[i];
				int nw = w + 1;
				int nh = h;
				if (nx < 1 || ny < 1 || nx + nw - 1 > M || ny + nh - 1 > N) continue;
				lu = { nx,ny };
				rd = { nx + nw - 1, ny + nh - 1 };
				if (check(lu, rd) == 0) continue;
				if (mark[ny][nx][nh][nw]) continue;
				q.push({ {nx,ny}, {nw, nh} });
				mark[ny][nx][nh][nw] = 1;
			}
		}
	}

	if (x + w <= M) {
		lu = { x + w, y };
		rd = { x + w, y + h - 1 };
		if (check(lu, rd)) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nw = w + 1;
				int nh = h;
				if (nx < 1 || ny < 1 || nx + nw - 1 > M || ny + nh - 1 > N) continue;
				lu = { nx,ny };
				rd = { nx + nw - 1, ny + nh - 1 };
				if (check(lu, rd) == 0) continue;
				if (mark[ny][nx][nh][nw]) continue;
				q.push({ {nx,ny}, {nw, nh} });
				mark[ny][nx][nh][nw] = 1;
			}
		}
	}

	if (y > 1) {
		lu = { x, y - 1 };
		rd = { x + w - 1, y - 1 };
		if (check(lu, rd)) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i] - 1;
				int nw = w;
				int nh = h + 1;
				if (nx < 1 || ny < 1 || nx + nw - 1 > M || ny + nh - 1 > N) continue;
				lu = { nx,ny };
				rd = { nx + nw - 1, ny + nh - 1 };
				if (check(lu, rd) == 0) continue;
				if (mark[ny][nx][nh][nw]) continue;
				q.push({ {nx,ny}, {nw, nh} });
				mark[ny][nx][nh][nw] = 1;
			}
		}
	}

	if (y + h <= N) {
		lu = { x, y + h };
		rd = { x + w - 1, y + h };
		if (check(lu, rd)) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nw = w;
				int nh = h + 1;
				if (nx < 1 || ny < 1 || nx + nw - 1 > M || ny + nh - 1 > N) continue;
				lu = { nx,ny };
				rd = { nx + nw - 1, ny + nh - 1 };
				if (check(lu, rd) == 0) continue;
				if (mark[ny][nx][nh][nw]) continue;
				q.push({ {nx,ny}, {nw, nh} });
				mark[ny][nx][nh][nw] = 1;
			}
		}
	}

	return;
}

int check(pii a, pii b) {
	if (psum[b.second][b.first] - psum[b.second][a.first - 1] - psum[a.second - 1][b.first] + psum[a.second - 1][a.first - 1]) return 0;
	else return 1;
}