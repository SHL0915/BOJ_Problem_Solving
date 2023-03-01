#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int N, K;
double table[51][51][51];

double DP(int x, int y, int k);

void solve() {
	int x, y;
	cin >> N >> x >> y >> K;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= K; k++) table[i][j][k] = -1;
		}
	}

	cout << DP(x, y, 0);
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

double DP(int x, int y, int k) {
	if (x < 1 || x > N || y < 1 || y > N) return 0;
	if (k == K) return 1;
	double& ret = table[x][y][k];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		ret += DP(nx, ny, k + 1) / 8;
	}

	return ret;
}