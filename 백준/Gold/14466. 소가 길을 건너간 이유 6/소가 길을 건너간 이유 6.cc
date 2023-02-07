#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, K, R, cnt, id = 1;
ll num[10001];
ll psum[10001];
int arr[101][101];
int mark[101][101];
set <pair<pii, pii>> road;

void DFS(int x, int y);

void solve() {
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		road.insert({ {b,a},{d,c} });
		road.insert({ {d,c},{b,a} });
	}
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (mark[i][j] == 0) {
				cnt = 0;
				DFS(j, i);
				num[id++] = cnt;
			}
		}
	}
	for (int i = 1; i < id; i++) psum[i] = psum[i - 1] + num[i];
	ll ans = 0;
	for (int i = 1; i < id; i++) ans += num[i] * (psum[id - 1] - psum[i]);
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

void DFS(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > N) return;
	if (mark[y][x]) return;
	mark[y][x] = 1;
	cnt += arr[y][x];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (road.count({ { x,y }, { nx,ny } })) continue;
		DFS(nx, ny);
	}
	return;
}