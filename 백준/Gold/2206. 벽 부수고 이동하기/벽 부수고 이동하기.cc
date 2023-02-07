#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M;
int arr[1001][1001];
int mark[1001][1001][2];
queue <pair<pii, pii>> q;

void BFS();

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) arr[i][j] = s[j] - '0';
	}
	q.push({ {0,0}, {1,0} });
	while (q.size()) BFS();
	int ans = INF;
	if (mark[N - 1][M - 1][0]) ans = min(ans, mark[N - 1][M - 1][0]);
	if (mark[N - 1][M - 1][1]) ans = min(ans, mark[N - 1][M - 1][1]);
	if (ans == INF) cout << -1;
	else cout << ans;
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
	pair<pii, pii> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second.first;
	int type = f.second.second;
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (arr[y][x] == 1) {
		if (type == 1) return;
		else type = 1;
	}
	if (mark[y][x][type]) return;
	mark[y][x][type] = d;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny},{d + 1,type} });
	}
	return;
}