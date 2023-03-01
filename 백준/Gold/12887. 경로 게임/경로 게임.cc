#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int M;
int arr[2][51];
int table[2][51];

int DP(int x, int y);

void solve() {
	cin >> M;
	int cnt = 0;

	for (int i = 0; i < 2; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '.') cnt++;
			else arr[i][j] = 1;
		}
	}

	memset(table, -1, sizeof(table));

	cout << cnt - min(DP(0, 0), DP(0, 1));
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

int DP(int x, int y) {
	if (arr[y][x]) return INF;
	if (x == M - 1) return 1;
	int& ret = table[y][x];
	if (ret != -1) return ret;

	ret = INF;
	if (arr[y ^ 1][x] == 0) ret = min(ret, 1 + DP(x, y ^ 1));
	if (arr[y][x + 1] == 0) ret = min(ret, 1 + DP(x + 1, y));

	return ret;
}