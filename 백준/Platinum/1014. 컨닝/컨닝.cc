#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[11][11];
int table[11][11][(1 << 15)];

int DP(int x, int y, int state);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '.') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0) << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int x, int y, int state) {
	if (y >= N) return 0;
	if (arr[y][x] == 1) return DP((x + 1) % M, y + (x + 1) / M, state >> 1);
	int& ret = table[x][y][state];
	if (ret != -1) return ret;
	ret = 0;
	if (x == 0) {
		if (M == 1) ret = max(ret, 1 + DP((x + 1) % M, y + (x + 1) / M, state >> 1));
		else if ((state & (1 << 2)) == 0) ret = max(ret, 1 + DP((x + 1) % M, y + (x + 1) / M, (state >> 1) | (1 << M)));
	}
	else if (x == M - 1) {
		if (M == 1) ret = max(ret, 1 + DP((x + 1) % M, y + (x + 1) / M, state >> 1));
		else if (((state & (1 << M)) == 0) && ((state & 1) == 0)) ret = max(ret, 1 + DP((x + 1) % M, y + (x + 1) / M, (state >> 1) | (1 << M)));
	}
	else {
		if (((state & (1 << M)) == 0) && ((state & 1) == 0) && ((state & (1 << 2)) == 0)) ret = max(ret, 1 + DP((x + 1) % M, y + (x + 1) / M, (state >> 1) | (1 << M)));
	}
	ret = max(ret, DP((x + 1) % M, y + (x + 1) / M, state >> 1));
	return ret;
}