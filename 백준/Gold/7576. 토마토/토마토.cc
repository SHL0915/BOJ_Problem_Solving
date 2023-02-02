#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int M, N, ans;
int arr[1001][1001];
int mark[1001][1001];
queue <pair<pii, int>> q;

void BFS();

void solve() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ {j,i},1 });
		}
	}
	while (q.size()) BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, mark[i][j] - 1);
			if (arr[i][j] == 0) {
				cout << -1;
				return;
			}
		}
	}
	cout << ans;
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

void BFS() {
	pair<pii, int> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (arr[y][x] == -1) return;
	if (mark[y][x]) return;
	mark[y][x] = d;
	arr[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny}, d + 1 });
	}
	return;
}