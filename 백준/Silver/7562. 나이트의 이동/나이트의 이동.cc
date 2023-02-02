#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int N;
pii s, e;
int mark[301][301];
queue <pair<pii, int>> q;

void BFS();

void solve() {
	cin >> N;
	cin >> s.first >> s.second;
	cin >> e.first >> e.second;
	memset(mark, 0, sizeof(mark));
	q.push({ s, 1 });
	while (q.size()) BFS();
	cout << mark[e.second][e.first] - 1 << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void BFS() {
	pair<pii, int> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (mark[y][x]) return;
	mark[y][x] = d;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny},d + 1 });
	}
	return;
}