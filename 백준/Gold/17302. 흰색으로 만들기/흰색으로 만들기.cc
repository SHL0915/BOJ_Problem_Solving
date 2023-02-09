#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M;
int arr[2001][2001];
int ans[2001][2001];

void flip(int x, int y);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'B') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				flip(nx, ny);
			}
			ans[i][j] = 2;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) ans[i][j] = 3;
		}
	}
	cout << 1 << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cout << ans[i][j];
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

void flip(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	arr[y][x] ^= 1;
	return;
}