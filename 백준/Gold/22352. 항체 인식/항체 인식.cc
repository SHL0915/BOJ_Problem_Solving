#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, dat = -1;
int arr[31][31];
int cmp[31][31];
int mark[31][31];
set <pii> diff, result;

void DFS(int x, int y, int type);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> cmp[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != cmp[i][j]) {
				diff.insert({ j,i });
				if (dat == -1) dat = cmp[i][j];
				else {
					if (dat != cmp[i][j]) {
						cout << "NO";
						return;
					}
				}
			}
		}
	}
	if (diff.size() == 0) {
		cout << "YES";
		return;
	}
	pii a = *(diff.begin());
	DFS(a.first, a.second, arr[a.second][a.first]);
	if (diff.size() != result.size()) {
		cout << "NO";
		return;
	}
	for (auto i = diff.begin(), j = result.begin(); i != diff.end(); i++, j++) {
		if (*i != *j) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
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

void DFS(int x, int y, int type) {
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (arr[y][x] != type) return;
	if (mark[y][x]) return;
	mark[y][x] = 1;
	result.insert({ x,y });
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS(nx, ny, type);
	}
	return;
}